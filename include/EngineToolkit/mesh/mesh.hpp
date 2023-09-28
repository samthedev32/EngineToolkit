#pragma once

#include <EngineToolkit/core/vector.hpp>
#include <EngineToolkit/mesh/material.hpp>

#include <cstdint>
#include <vector>

namespace EngineToolkit {

struct Vertex {
  vec<3> position;
  vec<2> texCoord;
  vec<3> normal;
};

struct Model {
  std::vector<Vertex> vertices;
  std::vector<uint16_t> indices;

  std::vector<Material> materials;

  static Model load(const char *path);
};

} // namespace EngineToolkit