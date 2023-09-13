#include <EngineToolkit/image/image.hpp>

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
  return {};
}

Image Image::load(const char *path) {
  // Deternine File Type
  FILE *f = fopen(path, "rb");
  if (!f) {
    fprintf(stderr, "Failed to open file\n");
    return {};
  }

  // Load Part of the Header
  char header[4];
  bool success = fread(header, 4, 1, f);
  fclose(f);

  if (!success) {
    fprintf(stderr, "Failed to read file\n");
    return {};
  }

  // Load File
  if (!strncmp(header, "BM", 2))
    return loadBMP(path);
  else if (!strncmp(&header[1], "PNG", 3))
    return loadPNG(path);

  // Detection Failed
  fprintf(stderr, "Failed to recognize file\n");
  return {};
}

}; // namespace EngineToolkit