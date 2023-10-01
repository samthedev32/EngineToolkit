#pragma once

#include <EngineToolkit/vector/vector.hpp>

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

  // Relational Operators (Image Size)

  bool operator==(const Image &v) const;
  bool operator!=(const Image &v) const;
  bool operator>(const Image &v) const;
  bool operator<(const Image &v) const;
  bool operator>=(const Image &v) const;
  bool operator<=(const Image &v) const;

  // Other Operator

  unsigned char *operator()(uint32_t x, uint32_t y) const;

  Image resize(vec<2, uint32_t> newSize, uint32_t newChannels = 0) const;

  // enum class Rotation { Clockwise, CounterClockwise };
  // enum class Orientation { Landscape, Portrait };

  // Image rotate(Rotation rotation);
  // Image flip(Orientation orientation);

private:
  static bool isPNG(FILE *f);
  static bool isBMP(FILE *f);

  static Image loadPNG(FILE *f);
  static Image loadBMP(FILE *f);

  bool savePNG(const char *path);

public:
  static Image load(const char *path);
  bool save(const char *path);
};

} // namespace EngineToolkit