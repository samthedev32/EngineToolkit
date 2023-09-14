#pragma once

#include <EngineToolkit/vector/vec1.hpp>

namespace EngineToolkit {

// 2D Vector
struct vec2 {
  union {
    // Data
    union {
      // Position
      struct {
        vec1 x, y;
      };

      // Texture Coordinate
      struct {
        vec1 u, v;
      };

      // Point
      vec1 data[2];
    };
  };

  // ---- Constructors

  vec2(vec1 x, vec1 y);
  vec2(vec1 xy[2]);

  vec2(vec1 xy = 0.0f);

  // ---- Destructor

  ~vec2();

  // ---- Operators

  vec2 operator+(const vec2 v) const;
  vec2 operator-(const vec2 v) const;
  vec2 operator*(const vec2 v) const;
  vec2 operator/(const vec2 v) const;

  void operator+=(const vec2 v);
  void operator-=(const vec2 v);
  void operator*=(const vec2 v);
  void operator/=(const vec2 v);

  void operator=(const vec2 v);
  bool operator==(const vec2 v) const;
  bool operator!=(const vec2 v) const;

  // ---- Indexing

  vec1 operator[](int i) const;
  vec1 &operator[](int i);

  // ---- Functions (Instance Methods)

  // Length
  vec1 length();

  // Normalize
  vec2 normalize();

  // ---- Functions (Static)

  // Distance
  vec1 distance(vec2 a, vec2 b);

  // Dot Product
  static vec1 dot(vec2 a, vec2 b);

  // Linearly Interpolate
  static vec2 lerp(vec2 a, vec2 b, vec1 blend);
};

} // namespace EngineToolkit