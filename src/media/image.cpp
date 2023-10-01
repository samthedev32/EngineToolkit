#include <EngineToolkit/media/image.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include "ext/stb_image.h"

#include <cctype>
#include <cstring>
#include <stdlib.h>
#include <string>

namespace EngineToolkit {

// Constructors & Destructor

Image::Image() {
  this->size = {0}, this->channels = 0;
  this->data = nullptr;
}

Image::Image(const char *path) { *this = load(path); }
Image::Image(Image const &image) { *this = image; } // FIXME: may cause segfault
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

  this->data = (typeof(this->data))malloc(this->size->x * this->size->y *
                                          this->channels);
  // TODO: error handling
  memcpy(this->data, image.data,
         image.size->x * image.size->y * image.channels);
}

// Other Operator

unsigned char *Image::operator()(uint32_t x, uint32_t y) const {
  return &this->data[(std::min(x, this->size->x - 1) +
                      std::min(y, this->size->y - 1) * this->size->x) *
                     channels];
}

// Functions (Static)

Image Image::load(const char *path) {
  Image out;

  int w, h, ch;
  unsigned char *data = stbi_load(path, &w, &h, &ch, 0);

  if (!data) {
    printf("failed to load image\n");
  } else {
    out.size = {w, h};
    out.channels = ch;
    out.data = data;
  }

  return out;
}

} // namespace EngineToolkit