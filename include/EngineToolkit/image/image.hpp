#pragma once

#include "stb_image.h"

#include <cstdint>

namespace EngineToolkit {

struct Image {
  uint32_t width, height;
  uint8_t channels;
  uint32_t size;

  unsigned char *data;

  // ---- Constructors

  Image();
  Image(const char *path);
  Image(Image const &image);

  ~Image();

  // ---- Operators

  void operator=(const Image image);

  // Load Image
  static Image load(const char *path);
};

} // namespace EngineToolkit