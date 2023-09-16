#define STB_IMAGE_IMPLEMENTATION
#include <EngineToolkit/image/image.hpp>

namespace EngineToolkit {

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

void Image::operator=(const Image image) {
  free(this->data);

  this->width = image.width, this->height = image.height;
  this->channels = image.channels;
  this->size = image.size;

  this->data = (unsigned char *)malloc(this->size);
  memcpy(this->data, image.data, image.width * image.height * image.channels);
}

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