#include <cctype>
#define STB_IMAGE_IMPLEMENTATION
#include <EngineToolkit/media/image.hpp>

#include <stdlib.h>
#include <string.h>

namespace EngineToolkit {

// Constructors & Destructor

Image::Image() {
  this->width = 0, this->height = 0, this->channels = 0, this->size = 0;
  this->data = nullptr;
}

Image::Image(const char *path) { *this = load(path); }
Image::Image(Image const &image) { *this = image; }
Image::~Image() {
  this->width = 0, this->height = 0, this->channels = 0, this->size = 0;
  this->data = nullptr;
  free(this->data);
}

// Assignment Operator

void Image::operator=(const Image image) {
  free(this->data);

  this->width = image.width, this->height = image.height;
  this->channels = image.channels;
  this->size = image.size;

  this->data = (unsigned char *)malloc(this->size);
  memcpy(this->data, image.data, image.width * image.height * image.channels);
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
  return &this->data[(std::min(x, this->width - 1) +
                      std::min(y, this->height - 1) * width) *
                     channels];
}

// Functions (Instance Methods)

bool Image::resize(uint32_t newWidth, uint32_t newHeight,
                   uint32_t newChannels) {

  if (newWidth == 0)
    newWidth = this->width;
  if (newHeight == 0)
    newHeight = this->height;
  if (newChannels == 0)
    newChannels = this->channels;
  uint32_t newSize = newWidth * newHeight * newChannels;

  if (this->width == newWidth && this->height == newHeight &&
      this->channels == newChannels && this->size == newSize)
    return true;

  unsigned char *newData = (unsigned char *)malloc(newSize);

  // Copy Data
  // TODO

  free(this->data);
  this->width = newWidth, this->height = newHeight;
  this->channels = newChannels, this->size = newSize;
  this->data = newData;

  return false;
}

bool Image::save(const char *path, ImageType type) {
  printf("Image Saving is not implemented YET\n");
  return false;

  switch (type) {
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

Image Image::load(const char *path) {
  Image out;

  int width, height, channels;
  if (!(out.data = stbi_load(path, &width, &height, &channels, 0))) {
    printf("failed to load image\n");
    return out;
  }

  out.width = width;
  out.height = height;
  out.channels = channels;

  return out;
}

} // namespace EngineToolkit