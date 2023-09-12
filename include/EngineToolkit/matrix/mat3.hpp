#pragma once

#include <EngineToolkit/vector/vector.hpp>

#warning 3 by 3 Matrices are not implemented YET!

// 4 by 4 Matrix
struct mat3 {
  // Data
  vec1 m[3][3] = {};

  // ---- Constructors

  // mat3(m) Constructor
  mat3(float m = 0);

  // ---- Operator Overloading

  // [=] Operator
  void operator=(const mat3 m);

  // [==] Operator
  bool operator==(const mat3 m);

  // [*] Operator
  mat3 operator*(const mat3 m);

  // [*] Operator
  vec3 operator*(const vec3 v);

  // ---- Static

  static mat3 identity();
  static mat3 inverse(mat3 m);

  static mat3 rotationX(float rad);
  static mat3 rotationY(float rad);
  static mat3 rotationZ(float rad);
  static mat3 rotation(vec3 rad);

  static mat3 translation(vec3 v);
  static mat3 scale(vec3 v);

  static mat3 perspective(float fovrads, float aspect, float near, float far);

  static mat3 ortho(float left, float right, float bottom, float top,
                    float fnear, float ffar);

  static mat3 lookat(vec3 pos, vec3 target, vec3 up = {0.0f, 1.0f, 0.0f});
};

// TODO: other stuff

// // Undef "near" and "far" (problem on windows)
// #undef near
// #undef far

// // Functions for Matrices
// namespace matrix {

// // Create an Identity Matrix
// mat3 identity();

// // Inverse a Matrix
// mat3 inverse(mat3 m);

// // Create a Perspective Matrix
// mat3 perspective(float fovrads, float aspect, float near, float far);

// // Create an Orthographic Projection Matrix
// mat3 ortho(float left, float right, float bottom, float top, float near,
//            float far);

// // Create an X Rotation Matrix
// mat3 rotationX(float rad);

// // Create a Y Rotation Matrix
// mat3 rotationY(float rad);

// // Create a Z Rotation Matrix
// mat3 rotationZ(float rad);

// // Create a Rotation Matrix
// mat3 rotation(vec3 rad);

// // Create a Translation Matrix
// mat3 translation(vec3 v);

// mat3 scale(vec3 v);

// // Create a Look-At Matrix
// mat3 lookat(vec3 pos, vec3 target, vec3 up);

// }; // namespace matrix