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

// Functions (Static)

Image Image::load(const char *path) {
  Image out;

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