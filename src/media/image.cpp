#include <EngineToolkit/media/image.hpp>

#include <cctype>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <zlib.h>

namespace EngineToolkit {

// Constructors & Destructor

Image::Image() {
  this->size = {0}, this->channels = 0;
  this->data = nullptr;
}

// Image::Image(const char *path) { *this = load(path); }
// Image::Image(Image const &image) { *this = image; }
Image::~Image() {
  this->size = {0}, this->channels = 0, this->size = 0;

  free(this->data);
  this->data = nullptr;
}

// Assignment Operator

void Image::operator=(const Image image) {
  free(this->data);

  this->size = image.size;
  this->channels = image.channels;

  this->data =
      (unsigned char *)malloc(this->size->x * this->size->y * this->channels);
  memcpy(this->data, image.data,
         image.size->x * image.size->y * image.channels);
}

// Relational Operators (Image Size)

bool Image::operator==(const Image &v) const { return this->size == v.size; }
bool Image::operator!=(const Image &v) const { return this->size != v.size; }
bool Image::operator>(const Image &v) const { return this->size > v.size; }
bool Image::operator<(const Image &v) const { return this->size < v.size; }
bool Image::operator>=(const Image &v) const { return this->size >= v.size; }
bool Image::operator<=(const Image &v) const { return this->size <= v.size; }

// Other Operator

unsigned char *Image::operator()(uint32_t x, uint32_t y) const {
  return &this->data[(std::min(x, this->size->x - 1) +
                      std::min(y, this->size->y - 1) * this->size->x) *
                     channels];
}

// Functions (Instance Methods)

// Return Resized Copy
Image Image::resized(vec<2, uint32_t> newSize, uint32_t newChannels) const {
  if (newSize->x == 0)
    newSize->x = this->size->x;
  if (newSize->y == 0)
    newSize->y = this->size->y;
  if (newChannels == 0)
    newChannels = this->channels;

  Image out;

  out.size = newSize;
  out.channels = newChannels;
  out.data =
      (unsigned char *)malloc(this->size->x * this->size->y * this->channels);

  // Copy Data
  // TODO: copy data
  for (uint32_t x = 0; x < out.size->x; x++) {
    for (uint32_t y = 0; y < out.size->y; y++) {
      // TODO
    }
  }

  return out;
}

bool Image::resize(vec<2, uint32_t> newSize, uint32_t newChannels) {
  Image out = resized(newSize, newChannels);

  if (out.size != newSize || out.channels != newChannels)
    return false;

  *this = out;
  return true;
}

bool Image::save(const char *path, ImageType type) {
  printf("Image Saving is not implemented YET\n");
  return false;

  switch (type) {
  case ImageType::AUTO: {
    printf("error\n");
  } break;

  case ImageType::PNG: {
  } break;

  case ImageType::JPG: {
  } break;

  case ImageType::BMP: {
  } break;
  }

  return true;
}

// Functions (Static)

Image Image::loadPNG(const char *path) {
  Image out;

  // Why tf do i get a segfault when this func() returns "out"???

  // Open File
  FILE *f = fopen(path, "rb");
  if (!f) {
    fprintf(stderr, "Failed to open PNG file\n");
    return out;
  }

  // Read Header
  char header[8];
  if (!fread(header, 8, 1, f)) {
    fprintf(stderr, "Failed to read Header\n");
    fclose(f);
    return out;
  }

  const char pngHeader[] = "\x89PNG\x0D\x0A\x1A\x0A";

  // Check Header
  for (int i = 0; i < 8; i++) {
    if (header[i] != pngHeader[i]) {
      fprintf(stderr, "File is not PNG\n");
      fclose(f);
      return out;
    }
  }

  // IHDR Data
  struct {
    uint32_t width;
    uint32_t height;
    uint8_t bitDepth;
    uint8_t colorType;
    uint8_t compressionMethod;
    uint8_t filterMethod;
    uint8_t interlanceMethod;
  } ihdr{};

  // IDAT Data
  struct {
    size_t size;
    unsigned char *data;
  } idat{};

  // All used chunk types
  const char *chunkTypes[] = {"IHDR", "PLTE", "IDAT", "IEND"};

  bool reading = true;
  while (reading) {
    // Chunk Data
    struct {
      uint32_t length;
      char type[4];
      unsigned char *data;
      uint32_t crc;
    } chunk;

    // Read Chunk Length & Type
    if (!fread(&chunk.length, 4, 1, f) || !fread(chunk.type, 4, 1, f)) {
      fprintf(stderr, "Unexpected Error\n");
      fclose(f);
      return out;
    } else
      chunk.length = __bswap_32(chunk.length);

    // Detect Type
    uint8_t id = 0;
    for (int i = 0; i < sizeof(chunkTypes) / sizeof(char *); i++) {
      if (!strncmp(chunk.type, chunkTypes[i], 4)) {
        id = i + 1;
        break;
      }
    }

    // Read Chunk Data
    chunk.data = (unsigned char *)malloc(chunk.length);

    if (chunk.length > 0) {
      if (!fread(chunk.data, chunk.length, 1, f)) {
        fprintf(stderr, "Failed to read Chunk Data ('%.4s')\n", chunk.type);
        // if chunk is critical, exit; else ignore
        if (id != 0) {
          fclose(f);
          return out;
        } else {
          // disable chunk
          strncpy(chunk.type, "none", 4);
          fseek(f, chunk.length, SEEK_CUR);
        }
      }
    }

    // Read Chunk CRC
    if (!fread(&chunk.crc, 4, 1, f)) {
      fprintf(stderr, "Failed to read Chunk CRC\n");
      // fclose(f);
      // free(image);
      // return out;
      fseek(f, 4, SEEK_CUR);
    } else
      chunk.crc = __bswap_32(chunk.crc);

    switch (id) {
    case 0:
    default:
      // unknown chunk
      break;

    case 1: // IHDR
    {       // Image Info
      ihdr.width = *(uint32_t *)&chunk.data[0];
      ihdr.height = *(uint32_t *)&chunk.data[4];
      ihdr.bitDepth = *(uint8_t *)&chunk.data[8];
      ihdr.colorType = *(uint8_t *)&chunk.data[9];
      ihdr.compressionMethod = *(uint8_t *)&chunk.data[10];
      ihdr.filterMethod = *(uint8_t *)&chunk.data[11];
      ihdr.interlanceMethod = *(uint8_t *)&chunk.data[12];

      ihdr.width = __bswap_32(ihdr.width);
      ihdr.height = __bswap_32(ihdr.height);

      if (ihdr.compressionMethod != 0) {
        fprintf(stderr, "Invalid Compression Method\n");
        fclose(f);
        return out;
      }

      if (ihdr.filterMethod != 0) {
        fprintf(stderr, "Invalid Filter Method\n");
        fclose(f);
        return out;
      }

      // TODO: validate compatibility, check filterMethod, etc
    } break;

    // PLTE
    case 2: {
      if (chunk.length % 3) {
        // Invalid Palette Size
        fprintf(stderr, "Invalid Palette Size\n");
        fclose(f);
        return out;
      }

      uint8_t entries = chunk.length / 3;
      unsigned char palette[entries][3];

      if (fread(palette, 3, entries, f) != entries) {
        // Failed to read palette
        fprintf(stderr, "Failed to read Palette\n");
        fclose(f);
        return out;
      }

      // TODO: store palette

      printf("plte:\n");
      printf("%i\n", entries);
    } break;

    // IDAT
    case 3: {
      size_t cursor = idat.size;
      idat.size += chunk.length;
      if (idat.data == NULL) {
        idat.data = (unsigned char *)malloc(chunk.length);
      } else {
        unsigned char *d = (unsigned char *)realloc(idat.data, idat.size);
        if (!d) {
          fprintf(stderr, "Failed to allocate memory\n");
          fclose(f);
          return out;
        }
        idat.data = d;
      }

      for (int i = 0; i < chunk.length; i++)
        idat.data[cursor + i] = chunk.data[i];

    } break;

    // IEND
    case 4: {
      reading = false;
      // Decompress Data
      uLong dstSize =
          ihdr.width * ihdr.height * ihdr.bitDepth; // TODO: color type
      unsigned char *dst = (unsigned char *)malloc(dstSize);
      int result = uncompress((Bytef *)dst, &dstSize, (const Bytef *)idat.data,
                              idat.size);

      if (result) {
        fprintf(stderr, "Failed to Decompress Image\n");
        fclose(f);
        return out;
      }

      // TODO: interlancing

      // TODO: filtering
      switch (ihdr.filterMethod) {
      default:
      case 0: {
        // None
      } break;

      case 1: {
        // Sub
      } break;

      case 2: {
        // Up
      } break;

      case 3: {
        // Avarage
      } break;

      case 4: {
        // Paeth
      } break;
      }

      out.size->x = ihdr.width;
      out.size->y = ihdr.height;
      out.channels = 3;
      out.data = dst;
    } break;
    }
  }

  // Close File
  fclose(f);
  return out;
}

// Load from JPG File
Image Image::loadJPG(const char *path) {
  Image out;
  return out;
}

Image Image::loadBMP(const char *path) {
  Image out;

  // Open File
  FILE *f = fopen(path, "rb");
  if (!f) {
    fprintf(stderr, "Failed to open BMP file\n");
    return out;
  }

  // Get Image Info
  unsigned int dataPos;
  unsigned int imageSize;
  unsigned char header[54];

  // Check File
  if (fread(header, 1, sizeof(header), f) != sizeof(header)) {
    fprintf(stderr, "BMP Header not found\n");
    return out;
  }

  if (header[0] != 'B' || header[1] != 'M') {
    fprintf(stderr, "Invalid BMP Header\n");
    return out;
  }

  // Read Basic Info
  dataPos = *(int *)&(header[0x0A]);     // 10
  imageSize = *(int *)&(header[0x22]);   // 32
  out.size->x = *(int *)&(header[0x12]); // 18
  out.size->y = *(int *)&(header[0x16]);
  out.channels = 3; // TODO: check

  if (imageSize == 0)
    imageSize = out.size->x * out.size->y * 3;
  if (dataPos == 0)
    dataPos = 54;

  // Load in image data
  out.data = (unsigned char *)malloc(sizeof(unsigned char) * imageSize);

  fseek(f, dataPos, SEEK_SET);
  fread(out.data, 1, imageSize, f);
  fclose(f);

  // TODO: error handling, etc

  return out;
}

Image Image::load(std::string path, ImageType type) {
  Image out;

  switch (type) {
  case ImageType::AUTO:
    // TODO: attempt loading each one
    break;

  case ImageType::PNG:
    out = loadPNG(path.c_str());
    break;

  case ImageType::JPG:
    out = loadJPG(path.c_str());
    break;

  case ImageType::BMP:
    out = loadBMP(path.c_str());
    break;
  }

  return out;
}

} // namespace EngineToolkit