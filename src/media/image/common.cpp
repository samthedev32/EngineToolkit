#include <EngineToolkit/media/image.hpp>

#include <cstdio>
#include <cstring>
#include <string>
#include <zlib.h>

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

} // namespace EngineToolkit