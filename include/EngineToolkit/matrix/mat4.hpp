#pragma once

#include <EngineToolkit/vector/vector.hpp>

// 4 by 4 Matrix
struct mat4 {
  // Data
  vec1 m[4][4] = {};

  // ---- Constructors

  // mat4(m) Constructor
  mat4(float m = 0);

  // ---- Operator Overloading

  // [=] Operator
  void operator=(const mat4 m);

  // [==] Operator
  bool operator==(const mat4 m);

  // [*] Operator
  mat4 operator*(const mat4 m);

  // [*] Operator
  vec3 operator*(const vec3 v);

  // ---- Static

  static mat4 identity();
  static mat4 inverse(mat4 m);

  static mat4 rotationX(float rad);
  static mat4 rotationY(float rad);
  static mat4 rotationZ(float rad);
  static mat4 rotation(vec3 rad);

  static mat4 translation(vec3 v);
  static mat4 scale(vec3 v);

  static mat4 perspective(float fovrads, float aspect, float near, float far);

  static mat4 ortho(float left, float right, float bottom, float top,
                    float fnear, float ffar);

  static mat4 lookat(vec3 pos, vec3 target, vec3 up = {0.0f, 1.0f, 0.0f});
};

// TODO: other stuff

// // Undef "near" and "far" (problem on windows)
// #undef near
// #undef far

// // Functions for Matrices
// namespace matrix {

// // Create an Identity Matrix
// mat4 identity();

// // Inverse a Matrix
// mat4 inverse(mat4 m);

// // Create a Perspective Matrix
// mat4 perspective(float fovrads, float aspect, float near, float far);

// // Create an Orthographic Projection Matrix
// mat4 ortho(float left, float right, float bottom, float top, float near,
//            float far);

// // Create an X Rotation Matrix
// mat4 rotationX(float rad);

// // Create a Y Rotation Matrix
// mat4 rotationY(float rad);

// // Create a Z Rotation Matrix
// mat4 rotationZ(float rad);

// // Create a Rotation Matrix
// mat4 rotation(vec3 rad);

// // Create a Translation Matrix
// mat4 translation(vec3 v);

// mat4 scale(vec3 v);

// // Create a Look-At Matrix
// mat4 lookat(vec3 pos, vec3 target, vec3 up);

// }; // namespace matrix