#include <EngineToolkit/media/image.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include <EngineToolkit/media/stb_image.h>

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

bool Image::isPNG(FILE *f) {
  if (!f)
    return false;

  fseek(f, 0, SEEK_SET);

  // Read Header
  char header[8];
  if (!fread(header, 8, 1, f))
    return false;

  // PNG Magic
  const char magic[] = "\x89PNG\x0D\x0A\x1A\x0A";

  // Check Header
  for (int i = 0; i < 8; i++)
    if (header[i] != magic[i])
      return false;

  return true;
}

bool Image::isBMP(FILE *f) {
  if (!f)
    return false;

  fseek(f, 0, SEEK_SET);

  // Read Header
  char header[2];
  if (!fread(header, 2, 1, f))
    return false;

  // PNG Magic
  const char magic[] = "BM";

  // Check Header
  for (int i = 0; i < 2; i++)
    if (header[i] != magic[i])
      return false;

  return true;
}

Image Image::loadPNG(FILE *f) {
  Image out;

  // Skip Magic
  fseek(f, 8, SEEK_SET);

  // IHDR Data
  struct {
    uint32_t width;
    uint32_t height;
    uint8_t bitDepth;
    uint8_t colorType;
    uint8_t compressionMethod;
    uint8_t filterMethod;
    uint8_t interlanceMethod;
  } ihdr;

  // IDAT Data
  struct {
    size_t size;
    unsigned char *data;
  } idat;

  idat.size = 0;
  idat.data = NULL;

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
      printf("unexpected error\n");
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
        printf("Failed to read Chunk Data ('%.4s')\n", chunk.type);
        // if chunk is critical, exit; else ignore
        if (id != 0) {
          printf("invalid file");
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
      printf("failed to read chunk crc\n");
      fseek(f, 4, SEEK_CUR);
      // return out;
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
        printf("Invalid Compression Method\n");
        return out;
      }

      if (ihdr.filterMethod != 0) {
        printf("Invalid Filter Method\n");
        return out;
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
    case 2: {
      if (chunk.length % 3) {
        // Invalid Palette Size
        printf("Invalid Palette Size\n");
        return out;
      }

      uint8_t entries = chunk.length / 3;
      unsigned char palette[entries][3];

      if (fread(palette, 3, entries, f) != entries) {
        // Failed to read palette
        printf("Failed to read Palette\n");
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
          printf("Failed to allocate memory\n");
          return out;
        }
        idat.data = d;
        // TODO: error handling
      }

      for (int i = 0; i < chunk.length; i++)
        idat.data[cursor + i] = chunk.data[i];

    } break;

    // IEND
    case 4: {
      printf("iend %zu\n", idat.size);
      reading = false;
      // TODO: finish up & return image

      // Decompress Data
      uLong dstSize =
          ihdr.width * ihdr.height * ihdr.bitDepth; // TODO: color type
      unsigned char *dst =
          (unsigned char *)malloc(sizeof(unsigned char) * dstSize);
      int result = uncompress((Bytef *)dst, &dstSize, (const Bytef *)idat.data,
                              idat.size);

      if (result) {
        printf("Failed to Decompress Image\n");
        return out;
      }

      out.size = {ihdr.width, ihdr.height};
      out.channels = 3;
      out.data = dst;
      printf("%i\n", ihdr.bitDepth);
    } break;
    }
  }

  return out;
}

Image Image::loadBMP(FILE *f) {
  Image out;

  // Skip Magic
  fseek(f, 0, SEEK_SET);

  // Get Image Info
  unsigned int dataPos;
  unsigned int imageSize;
  unsigned char header[54];

  // Check File
  if (fread(header, 1, 54, f) != 54) {
    printf("failed to read bmp header\n");
    return out;
  }

  // Read Basic Info
  dataPos = *(int *)&(header[0x0A]);     // 10
  imageSize = *(int *)&(header[0x22]);   // 32
  out.size->w = *(int *)&(header[0x12]); // 18
  out.size->h = *(int *)&(header[0x16]);
  out.channels = 3; // TODO: check

  if (imageSize == 0)
    imageSize = out.size->w * out.size->h * out.channels;
  if (dataPos == 0)
    dataPos = 54;

  // Load in image data
  out.data = (unsigned char *)malloc(sizeof(unsigned char) * imageSize);

  fseek(f, dataPos, SEEK_SET);
  fread(out.data, 1, imageSize, f);

  // TODO: error handling

  return out;
}

// Functions (Static)

Image Image::load(const char *path) {
  Image out;

  // Open File
  FILE *f = fopen(path, "rb");
  if (!f) {
    printf("failed to open file\n");
    return out;
  }

  // Determine Type
  if (isPNG(f)) {
    out = loadPNG(f);
  } else if (isBMP(f)) {
    out = loadBMP(f);
  } else {
    printf("failed to identify file type\n");
  }

  fclose(f);
  return out;

  int x, y, ch;
  stbi_set_flip_vertically_on_load(true);
  out.data = stbi_load(path, &x, &y, &ch, 0);

  if (out.data) {
    out.size = {x, y};
    out.channels = ch;
  }

  return out;
}

} // namespace EngineToolkit