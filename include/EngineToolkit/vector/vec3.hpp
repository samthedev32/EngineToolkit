#pragma once

#include <EngineToolkit/vector/vec1.hpp>
#include <EngineToolkit/vector/vec2.hpp>

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

  // vec3(x, y, z) Constructor
  vec3(vec1 x, vec1 y, vec1 z = 0.0f);

  // vec3({x, y, z}) Constructor
  vec3(vec1 xyz[3]);

  // vec3(xyz) Constructor
  vec3(vec1 xyz = 0.0f);

  // vec3(vec2) Constructor
  vec3(vec2 v);

  // ---- Operator Overloading

  // [+] Operator
  vec3 operator+(const vec3 v) const;

  // [-] Operator
  vec3 operator-(const vec3 v) const;

  // [*] Operator
  vec3 operator*(const vec3 v) const;

  // [/] Operator
  vec3 operator/(const vec3 v) const;

  // [+=] Operator
  void operator+=(const vec3 v);

  // [-=] Operator
  void operator-=(const vec3 v);

  // [*=] Operator
  void operator*=(const vec3 v);

  // [/=] Operator
  void operator/=(const vec3 v);

  // [=] Operator
  void operator=(const vec3 v);

  // [==] Operator
  bool operator==(const vec3 v) const;

  // [!=] Operator
  bool operator!=(const vec3 v) const;

  // ---- Indexing

  // vec2[id] Get Operator
  vec1 operator[](int i) const;

  // vec2[id] Set Operator
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