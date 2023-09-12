#pragma once

#include <EngineToolkit/vector/vec1.hpp>
#include <EngineToolkit/vector/vec2.hpp>

namespace EngineToolkit {

// 3D Vector
struct vec3 {
  // Data
  union {
    // Position
    struct {
      vec1 x, y, z;
    };

    // Color
    struct {
      vec1 r, g, b;
    };

    // Texture Coordinate
    struct {
      vec1 u, v, w;
    };

    // Point
    vec1 p[3];
  };

  // ---- Constructors

  vec3(vec1 x, vec1 y, vec1 z = 0.0f);
  vec3(vec1 xyz[3]);
  vec3(vec1 xyz = 0.0f);
  vec3(vec2 v);

  // ---- Operator Overloading

  vec3 operator+(const vec3 v) const;
  vec3 operator-(const vec3 v) const;
  vec3 operator*(const vec3 v) const;
  vec3 operator/(const vec3 v) const;

  void operator+=(const vec3 v);
  void operator-=(const vec3 v);
  void operator*=(const vec3 v);
  void operator/=(const vec3 v);

  void operator=(const vec3 v);
  bool operator==(const vec3 v) const;
  bool operator!=(const vec3 v) const;

  vec1 operator[](int i) const;
  vec1 &operator[](int i);

  // ---- Functions (Instance Methods)

  // Length
  vec1 length();

  // Distance
  vec1 distance(vec3 v);

  // Normalize
  vec3 normalize();

  // ---- Functions (Static)

  // Dot Product
  static vec1 dot(vec3 a, vec3 b);

  // Cross Product
  static vec3 cross(vec3 a, vec3 b);

  // Linearly Interpolate
  static vec3 lerp(vec3 a, vec3 b, vec1 blend);

  // ---- MISC

  // Get Data
  vec1 *data();
};

} // namespace EngineToolkit