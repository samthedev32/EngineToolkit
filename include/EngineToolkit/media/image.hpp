#pragma once

#include <EngineToolkit/core/vector.hpp>

#include <cstdint>
#include <string>

namespace EngineToolkit {

enum class ImageType { AUTO, PNG, JPG, BMP };

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

  // Save to File
  bool save(const char *path, ImageType type = ImageType::AUTO);

  // TODO: (GNU) image manipulating (program)

  // ---- Functions (Static)

  // Load from PNG File
  static Image loadPNG(const char *path);

  // Load from JPG File
  static Image loadJPG(const char *path);

  // Load from BMP File
  static Image loadBMP(const char *path);

  // Load From File
  static Image load(std::string path, ImageType type = ImageType::AUTO);
};

} // namespace EngineToolkit