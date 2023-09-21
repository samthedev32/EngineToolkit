#pragma once

#include <EngineToolkit/core/vector.hpp>

#include <cstdint>
#include <string>

namespace EngineToolkit {

struct Image {
  // Size of Image (width, height)
  vec<2, uint32_t> size;

  // Channels of Image (Red, Green, Blue, Alpha)
  uint8_t channels;

  // RAW Image Data
  unsigned char *data;

  // ---- Constructors & Destructor

  Image();
  // Image(const char *path);
  // Image(Image const &image);

  ~Image();

  // ---- Assignment Operator

  void operator=(const Image image);

  // ---- Relational Operators (Image Size)

  bool operator==(const Image &v) const;
  bool operator!=(const Image &v) const;
  bool operator>(const Image &v) const;
  bool operator<(const Image &v) const;
  bool operator>=(const Image &v) const;
  bool operator<=(const Image &v) const;

  // ---- Other Operator

  unsigned char *operator()(uint32_t x, uint32_t y) const;

  // ---- Functions (Instance Methods)

  // ---- Transform Image

  Image resized(vec<2, uint32_t> newSize, uint32_t newChannels = 0) const;
  bool resize(vec<2, uint32_t> newSize, uint32_t newChannels = 0);

  bool rotate(int direction);

  // ---- Functions (Static)

  // Load From File
  static Image load(const char *path);
};

} // namespace EngineToolkit