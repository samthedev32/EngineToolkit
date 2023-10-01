#pragma once

#include "material.hpp"

#include <EngineToolkit/vector/vector.hpp>

#include <cstdint>
#include <vector>

namespace EngineToolkit {

struct Vertex {
  vec3 position;
  vec2 texCoord;
  vec3 normal;
};

struct Model {
  std::vector<Vertex> vertices;
  std::vector<uint16_t> indices;

  std::vector<Material> materials;

  static Model load(const char *path);
};

} // namespace EngineToolkit