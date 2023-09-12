#pragma once

#include <EngineToolkit/vector/vec3.hpp>

// Euler Rotation
struct Euler {
  union {
    vec3 data;
    struct {
      vec1 x, y, z;
    };
  };

  // Euler(x, y, z) Constructor
  Euler(vec1 x, vec1 y, vec1 z = 0.0f);

  // Euler({x, y, z}) Constructor
  Euler(vec1 xyz[3]);

  // Euler(xyz) Constructor
  Euler(vec1 xyz = 0.0f);

  // Euler(vec2) Constructor
  Euler(vec2 v);
};