#include <EngineToolkit/media/image.hpp>

#include <cstdio>
#include <cstring>
#include <zconf.h>
#include <zlib.h>

namespace EngineToolkit {

template <typename T, typename... Args> bool isOneOf(T a, Args... args) {
  T values[] = {static_cast<T>(args)...};
  for (int i = 0; i < sizeof...(args); i++)
    if (a == values[i])
      return true;
  return false;
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
  if (strncmp(header, magic, 8))
    return false;

  return true;
}

// TODO decompressing algorithm

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
          printf("invalid file\n");
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

      if (ihdr.width == 0 || ihdr.height == 0) {
        printf("Invalid Size\n");
        return out;
      }

      // Validate Color Type & Bit Depth
      bool palette = ihdr.colorType & 1 << 0;
      bool color = ihdr.colorType & 1 << 1;
      bool alpha = ihdr.colorType & 1 << 2;

      if (color && alpha) {
        if (!isOneOf(ihdr.bitDepth, 8, 16)) {
          printf("invalid bit depth\n");
          return out;
        }
      }

      if (palette && color) {
        if (!isOneOf<uint8_t>(ihdr.bitDepth, 1, 2, 4)) {
          printf("invalid bit depth\n");
          return out;
        }
      }

      // Validate Compression Method
      if (!isOneOf(ihdr.compressionMethod, 0)) {
        printf("Unknown Compression Method\n");
        return out;
      }

      // Validate Filter Method
      if (!isOneOf(ihdr.filterMethod, 0)) {
        printf("Unknown Filter Method\n");
        return out;
      }

      // Validate Interlance Method
      if (!isOneOf(ihdr.interlanceMethod, 0, 1)) {
        printf("Unknown Interlance Method\n");
        return out;
      }

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
      reading = false;
      // TODO: finish up & return image

      // Decompress Data
      uLong dstSize = ihdr.width * ihdr.height * ihdr.bitDepth; // TODO: color type
      unsigned char *dst = (unsigned char *)malloc(sizeof(unsigned char) * dstSize);
      int result = uncompress((Bytef *)dst, &dstSize, (const Bytef *)idat.data, idat.size);

      out.size = {ihdr.width, ihdr.height};
      out.channels = 3; // TODO determine channels
      out.data = (unsigned char *)malloc(sizeof(unsigned char) * out.size->width * out.size->height
                                         * out.channels);

      if (result) {
        printf("Failed to Decompress Image\n");
        return out;
      }

      // TODO filtering
      switch (ihdr.filterMethod) {
      default:
      case 0: // None

        break;

      case 1: // Sub
        break;

      case 2: // Up
        break;

      case 3: // Avarage
        break;

      case 4: // Paeth
        break;
      }
    } break;
    }
  }

  return out;
}

} // namespace EngineToolkit