#pragma once

#include <EngineToolkit/math/math.hpp>

#include <cstdint>
#include <string>

namespace EngineToolkit {

struct Image {
  // Size of Image
  vec<2, uint32_t> size;

  uint8_t channels;

  // RAW Image Data
  unsigned char *data;

  // Constructors & Destructor

  Image();
  Image(const char *path);

  Image(Image const &image);

  ~Image();

  // Operators

  void operator=(Image const &image);
  unsigned char *operator()(uint32_t x, uint32_t y) const;

private:
  static bool isPNG(FILE *f);
  static bool isBMP(FILE *f);

  static Image loadPNG(FILE *f);
  static Image loadBMP(FILE *f);

  // bool savePNG(const char *path);
  // bool saveBMP(const char *path);

public:
  // TODO request #channels
  static Image load(const char *path);
  bool save(const char *path);

  enum { Vertically, Horizontally };
  enum { Clockwise, CounterClockwise };

  void flip(typeof(Vertically) orientation = Vertically);
  void rotate(typeof(Clockwise) direction = Clockwise);
};

} // namespace EngineToolkit