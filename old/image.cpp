#include <EngineToolkit/image/image.hpp>
#include <vector>
#include <zlib.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace EngineToolkit {

Image::Image() {
  this->width = 0, this->height = 0, this->channels = 0;
  this->data = nullptr;
}

Image::Image(const char *path) { *this = load(path); }
Image::Image(Image const &image) { *this = image; }
Image::~Image() { free(this->data); }

void Image::operator=(const Image image) {
  this->width = image.width, this->height = image.height;
  this->channels = image.channels;

  memcpy(this->data, image.data, image.width * image.height * image.channels);
}

Image Image::loadBMP(const char *path) {
  // TODO: https://en.wikipedia.org/wiki/BMP_file_format
  // Open File
  FILE *f = fopen(path, "rb");
  if (!f) {
    fprintf(stderr, "failed to open file\n");
    return {};
  }

  // Get Image Info
  unsigned int dataPos;
  unsigned int imageSize;
  char header[54];

  // Check File
  if (!fread(header, 54, 1, f)) {
    fprintf(stderr, "failed to read header\n");
    return {};
  }

  if (!strncmp(header, "BM", 2)) {
    fprintf(stderr, "Invalid BMP Header\n");
    return {};
  }

  Image image;

  // Read Basic Info
  dataPos = *(int *)&(header[0x0A]);     // 10
  imageSize = *(int *)&(header[0x22]);   // 32
  image.width = *(int *)&(header[0x12]); // 18
  image.height = *(int *)&(header[0x16]);
  image.channels = 3;

  if (imageSize == 0)
    imageSize = image.width * image.height * image.channels;
  if (dataPos == 0)
    dataPos = 54;

  // Load in image data
  image.data = (unsigned char *)malloc(sizeof(unsigned char) * imageSize);

  fread(image.data, 1, imageSize, f);
  fclose(f);

  return {};
}

Image Image::loadPNG(const char *path) {
  // TODO: https://en.wikipedia.org/wiki/PNG
  // Open File
  FILE *f = fopen(path, "rb");

  if (!f) {
    fprintf(stderr, "Failed to open file\n");
    return {};
  }

  // Read Header

  unsigned char header[8];
  if (!fread(header, 8, 1, f)) {
    fprintf(stderr, "Failed to read Header\n");
    fclose(f);
    return {};
  }

  if (header[0] != 0x89 || header[1] != 'P' || header[2] != 'N' ||
      header[3] != 'G' || header[4] != 0x0D || header[5] != 0x0A ||
      header[6] != 0x1A || header[7] != 0x0A) {
    fprintf(stderr, "File is not PNG\n");
    fclose(f);
    return {};
  }

  // TODO: more header validation

  // Read Chunks
  Image out;

  struct {
    uint32_t width;
    uint32_t height;
    uint8_t bitDepth;
    uint8_t colorType;
    uint8_t compressionMethod;
    uint8_t filterMethod;
    uint8_t interlanceMethod;
  } ihdr;

  struct {
    std::vector<unsigned char *> data;
  } idat;

  const char *chunkTypes[] = {"IHDR", "PLTE", "IDAT", "IEND"};
  bool reading = true;
  while (reading) {
    // Read Chunk
    struct {
      uint32_t length;
      char type[4];
      unsigned char *data;
      uint32_t crc;
    } chunk;

    uint32_t length;
    char type[4];

    // The exact same problem xd:
    // https://stackoverflow.com/questions/33511395/bytes-to-integer-from-binary-file
    if (!fread(&length, 4, 1, f) || !fread(type, 4, 1, f)) {
      fprintf(stderr, "Unexpected Error\n");
      fclose(f);
      return {};
    }
    length = __bswap_32(length);

    // Read Data
    unsigned char data[length];
    if (fread(data, 1, length, f) != length) {
      fprintf(stderr, "failed to read data of chunk '%.4s'\n", type);
      if ('A' <= type[0] && type[0] <= 'Z') {
        fclose(f);
        return {};
      } else {
        // disable chunk
        strncpy(type, "none", 4);
        fseek(f, length, SEEK_CUR);
      }
    }

    // Read CRC
    uint32_t crc;
    if (!fread(&crc, 4, 1, f)) {
      fprintf(stderr, "failed to read crc\n");
      // TODO: use crc

      // fclose(f);
      // return {};
      fseek(f, 4, SEEK_CUR);
    }
    crc = __bswap_32(crc);

    // Detect Type
    uint8_t id = -1;
    for (int i = 0; i < sizeof(chunkTypes) / sizeof(char *); i++)
      if (!strncmp(type, chunkTypes[i], 4)) {
        id = i;
        break;
      }

    switch (id) {
    case 0: // IHDR
    {       // Image Info
      ihdr.width = *(uint32_t *)&data[0];
      ihdr.height = *(uint32_t *)&data[4];
      ihdr.bitDepth = *(uint8_t *)&data[8];
      ihdr.colorType = *(uint8_t *)&data[9];
      ihdr.compressionMethod = *(uint8_t *)&data[10];
      ihdr.filterMethod = *(uint8_t *)&data[11];
      ihdr.interlanceMethod = *(uint8_t *)&data[12];

      ihdr.width = __bswap_32(ihdr.width);
      ihdr.height = __bswap_32(ihdr.height);

      if (ihdr.compressionMethod != 0) {
        fprintf(stderr, "Invalid Compression Method\n");
        fclose(f);
        return {};
      }

      if (ihdr.filterMethod != 0) {
        fprintf(stderr, "Invalid Filter Method\n");
        fclose(f);
        return {};
      }

      // printf("ihdr:\n");
      // printf("%u x %u\n", width, height);
      // printf("%i %i\n", bitDepth, colorType);
      // printf("%i %i %i\n", compressionMethod, filterMethod,
      // interlanceMethod);

      // TODO: validate W, H
      // TODO: validate config

      // TODO: Store Info

      // TODO: check chunk order
    } break;

    // PLTE
    case 1: {
      if (length % 3 != 0) {
        // Invalid Palette Size
        fprintf(stderr, "Invalid Palette Size\n");
        fclose(f);
        return {};
      }

      uint8_t entries = length / 3;
      unsigned char palette[entries][3];

      if (fread(palette, 3, entries, f) != entries) {
        // Failed to read palette
        fprintf(stderr, "Failed to read Palette\n");
        fclose(f);
        return {};
      }

      // TODO: store palette

      printf("plte:\n");
      printf("%i\n", entries);
    } break;

    // IDAT
    case 2: {
      printf("idat\n");
      // TODO: read data
      // unsigned char data[length];
      // if (fread(data, 1, length, f) != length) {
      //   // Failed to read data
      //   fprintf(stderr, "Failed to read Image Data\n");
      //   fclose(f);
      //   return {};
      // }

      // TODO
    } break;

    // IEND
    case 3: {
      printf("iend\n");
      reading = false;
      // TODO: finish up & return image

      // Decompress Data
      char src[128];
      uLong srcSize = sizeof(src);

      uLong dstSize =
          ihdr.width * ihdr.height * ihdr.bitDepth; // TODO: color type
      char dst[dstSize];

      int result =
          uncompress((Bytef *)dst, &dstSize, (const Bytef *)src, srcSize);

      // TODO
    } break;

    default:
      // unknown chunk
      break;
    }
  }

  // Close File
  fclose(f);
  return 0;
  return {};
}

Image Image::load(const char *path) {
  // Load File
  Image out = loadPNG(path);

  if (!out.data)
    out = loadBMP(path);

  return out;

  // Detection Failed
  fprintf(stderr, "Failed to recognize file\n");
  return {};
}

}; // namespace EngineToolkit