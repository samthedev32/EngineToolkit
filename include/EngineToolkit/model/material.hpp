#pragma once

#include <EngineToolkit/vector/vector.hpp>

#include <string>
#include <unordered_map>

namespace EngineToolkit {

struct Material {
  typedef std::unordered_map<std::string, Material> MTL;

  // Data
  struct {
    vec<3> ambient, diffuse, specular; // Ka, Kd, Ks
  } color;
  float Tr;
  vec<3> Tf;
  // TODO

  // Load Wavefront MTL File
  static MTL load(const char *path);
};

} // namespace EngineToolkit