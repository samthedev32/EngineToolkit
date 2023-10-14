#pragma once

#include <EngineToolkit/math/math.hpp>
#include <EngineToolkit/media/image.hpp>

#include <cstdint>
#include <string>
#include <unordered_map>

namespace EngineToolkit {

struct Material {
  vec<3> Ka, Kd, Ks;
  float Ns, Ni;
  float d;
  uint8_t illum;

  Image map_Ka, map_Kd, map_Ks;
  // TODO

  // Wavefront MTL
  struct MTL {
    std::unordered_map<std::string, Material> material;

    static MTL load(const char *path);
  };
};

} // namespace EngineToolkit