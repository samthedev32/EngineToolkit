#include <EngineToolkit/media/image.hpp>

#include <cstdio>
#include <cstring>
#include <string>

namespace EngineToolkit {

// Constructors & Destructor

Image::Image() {
  this->size = {0}, this->channels = 0;
  this->data = nullptr;
}

Image::Image(const char *path) {
  *this = load(path);
}
Image::Image(Image const &image) {
  *this = image;
} // FIXME: may cause segfault
Image::~Image() {
  this->size = {0}, this->channels = 0, this->size = 0;

  free(this->data);
  this->data = nullptr;
}

// Assignment Operator

void Image::operator=(Image const &image) {
  free(this->data);

  this->size = image.size;
  this->channels = image.channels;

  this->data = (typeof(this->data))malloc(this->size->x * this->size->y * this->channels);
  // TODO: error handling
  memcpy(this->data, image.data, image.size->x * image.size->y * image.channels);
}

// Other Operator

unsigned char *Image::operator()(uint32_t x, uint32_t y) const {
  return &this->data[(MIN(x, this->size->x - 1) + MIN(y, this->size->y - 1) * this->size->x)
                     * channels];
}

// Other

Image Image::load(const char *path) {
  Image out;

  // Open File
  FILE *f = fopen(path, "rb");
  if (!f) {
    printf("failed to open file\n");
    return out;
  }

  // Determine File Type
  if (isPNG(f))
    out = loadPNG(f);
  else if (isBMP(f))
    out = loadBMP(f);
  else
    printf("failed to identify file type\n");

  fclose(f);
  return out;
}

bool Image::save(const char *path) {
  // Determine File Type
  const char *ext = strrchr(path, '.');

  // if (!strcmp(ext, ".png"))
  // return savePNG(path);
  // else if (!strcmp(ext, ".bmp"))
  // return saveBMP(path);
  // else
  printf("Not Implemented!\n");

  return false;
}

} // namespace EngineToolkit