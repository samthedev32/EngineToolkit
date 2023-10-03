#pragma once

#include <EngineToolkit/math/vector/vector.hpp>

#include <cstdint>
#include <string>

namespace EngineToolkit {

// 2D Image/Texture
struct Image {
  // Size of Image
  vec<2, uint32_t> size;

  // Number of Channels
  uint8_t channels;

  // RAW Image Data
  unsigned char *data;

  // ---- Constructors & Destructor

  Image();
  Image(const char *path);
  Image(Image const &image);

  ~Image();

  // Assignment Operator

  void operator=(const Image image);

  // Other Operator

  unsigned char *operator()(uint32_t x, uint32_t y) const;

  // Functions (Static)

  static Image load(const char *path);
};

} // namespace EngineToolkit