#pragma once

#include "stb_image.h"

#include <cstdint>

namespace EngineToolkit {

enum class ImageType { PNG, JPG, BMP };

struct Image {
  uint32_t width, height;
  uint8_t channels;
  uint32_t size;

  unsigned char *data;

  // Constructors & Destructor

  Image();
  Image(const char *path);
  Image(Image const &image);

  ~Image();

  // Assignment Operator

  void operator=(const Image image);

  // Relational Operators (Image Size)

  bool operator==(const Image &v) const;
  bool operator!=(const Image &v) const;
  bool operator>(const Image &v) const;
  bool operator<(const Image &v) const;
  bool operator>=(const Image &v) const;
  bool operator<=(const Image &v) const;

  // Other Operator

  unsigned char *operator()(uint32_t x, uint32_t y) const;

  // Functions (Instance Methods)

  bool resize(uint32_t newWidth, uint32_t newHeight, uint32_t newChannels = 0);
  bool save(const char *path, ImageType type = ImageType::PNG);

  // TODO: image manipulating

  // Functions (Static)

  static Image load(const char *path);
};

} // namespace EngineToolkit