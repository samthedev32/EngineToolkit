#include <cctype>
#define STB_IMAGE_IMPLEMENTATION
#include <EngineToolkit/media/image.hpp>

#include <stdlib.h>
#include <string.h>

namespace EngineToolkit {

// Constructors & Destructor

Image::Image() {
  this->size = {0}, this->channels = 0;
  this->data = nullptr;
}

Image::Image(const char *path) { *this = load(path); }
Image::Image(Image const &image) { *this = image; }
Image::~Image() {
  this->size = {0}, this->channels = 0, this->size = 0;
  this->data = nullptr;
  free(this->data);
}

// Assignment Operator

void Image::operator=(const Image image) {
  free(this->data);

  this->size = image.size;
  this->channels = image.channels;
  this->size = image.size;

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

Image Image::load(const char *path, ImageType type) {
  Image out;

  vec<2, int> size;
  int channels;
  if (!(out.data = stbi_load(path, &size->x, &size->y, &channels, 0))) {
    printf("failed to load image\n");
    return out;
  }

  out.size = size;
  out.channels = channels;

  return out;
}

} // namespace EngineToolkit