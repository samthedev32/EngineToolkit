#include <EngineToolkit/media/image.hpp>

#include <cstring>

namespace EngineToolkit {

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
  if (strncmp(header, magic, 2))
    return false;

  return true;
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
  dataPos = *(int *)&(header[0x0A]);         // 10
  imageSize = *(int *)&(header[0x22]);       // 32
  out.size->width = *(int *)&(header[0x12]); // 18
  out.size->height = *(int *)&(header[0x16]);
  out.channels = 3; // TODO: check

  if (imageSize == 0)
    imageSize = out.size->width * out.size->height * out.channels;
  if (dataPos == 0)
    dataPos = 54;

  // Load in image data
  out.data = (unsigned char *)malloc(sizeof(unsigned char) * imageSize);

  fseek(f, dataPos, SEEK_SET);
  fread(out.data, 1, imageSize, f);

  // TODO: error handling

  return out;
}

}