#pragma once

#include <EngineToolkit/vector/vector.hpp>

#include <cstdint>
#include <string>

namespace EngineToolkit {

// Audio
struct Audio {
  // Size of Image
  vec<2, uint32_t> size;

  uint8_t channels, sampleRate;

  float *data;

  // ---- Constructors & Destructor

  Audio();
  Audio(const char *path);
  Audio(Audio const &audio);

  ~Audio();

  // Assignment Operator

  void operator=(const Audio image);

  // Other Operator

  // unsigned char *operator()(uint32_t x, uint32_t y) const;

  // Functions (Static)

  // TODO: load / stream audio

  static Audio load(const char *path);
};

} // namespace EngineToolkit