#pragma once

#include <EngineToolkit/vector/vector.hpp>

#include <cstdint>
#include <string>
#include <unordered_map>

namespace EngineToolkit {

struct Material {
  typedef std::unordered_map<std::string, Material> MTL;

  // Data
  vec<3> Ka, Kd, Ks;
  float Ns, Ni;
  float d;
  uint8_t illum;

  Image map_Ka, map_Kd, map_Ks;
  // TODO

  // Load Wavefront MTL File
  static MTL load(const char *path);
};

} // namespace EngineToolkit