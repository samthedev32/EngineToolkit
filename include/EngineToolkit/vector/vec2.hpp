#pragma once

#include <EngineToolkit/vector/vec1.hpp>

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
      vec1 p[2];
    };
  };

  // ---- Constructors

  // vec2(x, y) Constructor
  vec2(vec1 x, vec1 y);

  // vec2({x, y}) Constructor
  vec2(vec1 xy[2]);

  // vec2(xy) Constructor
  vec2(vec1 xy = 0.0f);

  // ---- Operator Overloading

  // [+] Operator
  vec2 operator+(const vec2 v) const;

  // [-] Operator
  vec2 operator-(const vec2 v) const;

  // [*] Operator
  vec2 operator*(const vec2 v) const;

  // [/] Operator
  vec2 operator/(const vec2 v) const;

  // [+=] Operator
  void operator+=(const vec2 v);

  // [-=] Operator
  void operator-=(const vec2 v);

  // [*=] Operator
  void operator*=(const vec2 v);

  // [/=] Operator
  void operator/=(const vec2 v);

  // [=] Operator
  void operator=(const vec2 v);

  // [==] Operator
  bool operator==(const vec2 v) const;

  // [!=] Operator
  bool operator!=(const vec2 v) const;

  // ---- Indexing

  // vec2[id] Get Operator
  vec1 operator[](int i) const;

  // vec2[id] Set Operator
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

  // ---- MISC

  // Get Data
  vec1 *data();
};