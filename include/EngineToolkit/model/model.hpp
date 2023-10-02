#pragma once

#include "material.hpp"

#include <EngineToolkit/math/vector/vector.hpp>

#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

namespace EngineToolkit {

struct Vertex {
  vec3 position;
  vec2 texCoord;
  vec3 normal;
};

// TODO: migrate to ONLY glTF (json & bin)

struct Model {
  typedef std::unordered_map<std::string, Model> OBJ;

  std::vector<Vertex> vertices;
  std::vector<uint16_t> indices;

  Material::MTL material;

  static OBJ load(const char *path);
};

} // namespace EngineToolkit