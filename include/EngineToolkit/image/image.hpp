#pragma once

#include <cstdint>

namespace EngineToolkit {

struct Image {
  // Image's Size
  uint32_t width, height;

  // Image Channels
  uint8_t channels;

  // RAW Image Data
  unsigned char *data;

  // ---- Constructors

  Image();
  Image(const char *path);
  Image(Image const &image);

  ~Image();

  // ---- Operators

  void operator=(const Image image);

  // Load BMP Image
  static Image loadBMP(const char *path);

  // Load PNG Image
  static Image loadPNG(const char *path);

  // Load Image (auto-detect)
  static Image load(const char *path);
};

} // namespace EngineToolkit