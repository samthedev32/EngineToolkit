#pragma once

#include <EngineToolkit/vector/vector.hpp>

namespace EngineToolkit {

// 2 by 2 Matrix
struct mat2 {
  // Data
  vec1 m[2][2] = {};

  // ---- Constructors

  mat2(float m = 0);
  mat2(mat2 const &m);

  // ---- Destructor

  ~mat2();

  // ---- Operators

  void operator=(const mat2 m);
  bool operator==(const mat2 m) const;
  bool operator!=(const mat2 m) const;

  mat2 operator*(const mat2 m);
  vec3 operator*(const vec3 v);

  // ---- Functions (Instance Methods)

  void inverse();

  // ---- Functions (Static)

  static mat2 identity();

  static mat2 rotationX(float rad);
  static mat2 rotationY(float rad);
  static mat2 rotationZ(float rad);
  static mat2 rotation(vec3 rad);

  static mat2 translation(vec3 v);
  static mat2 scale(vec3 v);

  static mat2 perspective(float fovrads, float aspect, float near, float far);

  static mat2 ortho(float left, float right, float bottom, float top,
                    float fnear, float ffar);

  static mat2 lookat(vec3 pos, vec3 target, vec3 up = {0.0f, 1.0f, 0.0f});
};

// TODO: other stuff

// // Undef "near" and "far" (problem on windows)
// #undef near
// #undef far

// // Functions for Matrices
// namespace matrix {

// // Create an Identity Matrix
// mat2 identity();

// // Inverse a Matrix
// mat2 inverse(mat2 m);

// // Create a Perspective Matrix
// mat2 perspective(float fovrads, float aspect, float near, float far);

// // Create an Orthographic Projection Matrix
// mat2 ortho(float left, float right, float bottom, float top, float near,
//            float far);

// // Create an X Rotation Matrix
// mat2 rotationX(float rad);

// // Create a Y Rotation Matrix
// mat2 rotationY(float rad);

// // Create a Z Rotation Matrix
// mat2 rotationZ(float rad);

// // Create a Rotation Matrix
// mat2 rotation(vec3 rad);

// // Create a Translation Matrix
// mat2 translation(vec3 v);

// mat2 scale(vec3 v);

// // Create a Look-At Matrix
// mat2 lookat(vec3 pos, vec3 target, vec3 up);

// }; // namespace matrix

} // namespace EngineToolkit