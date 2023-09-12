#pragma once

#include <EngineToolkit/vector/vec1.hpp>
#include <EngineToolkit/vector/vec2.hpp>
#include <EngineToolkit/vector/vec3.hpp>

// 3D Vector
struct vec4 {
  // Data
  union {
    // Position
    struct {
      vec1 x, y, z, w;
    };

    // Color
    struct {
      vec1 r, g, b, a;
    };

    // Point
    vec1 p[4];
  };

  // ---- Constructors

  // vec4(x, y, z, w) Constructor
  vec4(vec1 x, vec1 y, vec1 z, vec1 w = 0.0f);

  // vec4({x, y, z, w}) Constructor
  vec4(vec1 xyzw[4]);

  // vec4(xyzw) Constructor
  vec4(vec1 xyzw = 0.0f);

  // vec4(vec2) Constructor
  vec4(vec2 v);

  // vec4(vec3) Constructor
  vec4(vec3 v);

  // ---- Operator Overloading

  // [+] Operator
  vec4 operator+(const vec4 v) const;

  // [-] Operator
  vec4 operator-(const vec4 v) const;

  // [*] Operator
  vec4 operator*(const vec4 v) const;

  // [/] Operator
  vec4 operator/(const vec4 v) const;

  // [+=] Operator
  void operator+=(const vec4 v);

  // [-=] Operator
  void operator-=(const vec4 v);

  // [*=] Operator
  void operator*=(const vec4 v);

  // [/=] Operator
  void operator/=(const vec4 v);

  // [=] Operator
  void operator=(const vec4 v);

  // [==] Operator
  bool operator==(const vec4 v) const;

  // [!=] Operator
  bool operator!=(const vec4 v) const;

  // ---- Indexing

  // vec2[id] Get Operator
  vec1 operator[](int i) const;

  // vec2[id] Set Operator
  vec1 &operator[](int i);

  // ---- Functions (Instance Methods)

  // Length
  vec1 length();

  // Distance
  vec1 distance(vec4 v);

  // Normalize
  vec4 normalize();

  // ---- Functions (Static)

  // Dot Product
  static vec1 dot(vec4 a, vec4 b);

  // Linearly Interpolate
  static vec4 lerp(vec4 a, vec4 b, vec1 blend);

  // ---- MISC

  // Get Data
  vec1 *data();
};