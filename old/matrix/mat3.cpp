#include <EngineToolkit/matrix/mat3.hpp>

#include <stdlib.h>
#include <string.h>

namespace EngineToolkit {

// ---- Constructors

mat3::mat3(float v) { *this = v; }
mat3::mat3(mat3 const &m) { *this = m; }

// ---- Destructor

mat3::~mat3() { *this = 0.0f; }

// ---- Operators

void mat3::operator=(const mat3 m) {
  for (int c = 0; c < 3; c++)
    for (int r = 0; r < 3; r++)
      this->m[r][c] = m.m[r][c];
}

bool mat3::operator==(const mat3 m) const {
  for (int c = 0; c < 3; c++)
    for (int r = 0; r < 3; r++)
      if (this->m[r][c] != m.m[r][c])
        return false;
  return true;
}

bool mat3::operator!=(const mat3 m) const { return !(*this == m); }

// TODO
// mat3 mat3::operator*(const mat3 m) {
//   mat3 matrix;
//   for (int c = 0; c < 3; c++)
//     for (int r = 0; r < 3; r++)
//       matrix.m[r][c] = this->m[r][0] * m.m[0][c] + this->m[r][1] * m.m[1][c]
//       +
//                        this->m[r][2] * m.m[2][c] + this->m[r][3] * m.m[3][c];
//   return matrix;
// }

// ---- Operator Overloading (vec3)

// [*] Operator (vec3)
// vec3 mat3::operator*(const vec3 v) {
//   return vec3(v.x * this->m[0][0] + v.y * this->m[1][0] + v.z * this->m[2][0]
//   +
//                   1 * this->m[3][0],
//               v.x * this->m[0][1] + v.y * this->m[1][1] + v.z * this->m[2][1]
//               +
//                   1 * this->m[3][1],
//               v.x * this->m[0][2] + v.y * this->m[1][2] + v.z * this->m[2][2]
//               +
//                   1 * this->m[3][2]);
// }
// TODO

// Create an Identity Matrix
mat3 mat3::identity() {
  mat3 matrix;

  for (int i = 0; i < 3; i++)
    matrix.m[i][i] = 1.0f;

  return matrix;
}

// Inverse a Matrix
// mat3 mat3::inverse(mat3 m) {
//   mat3 matrix;
//   matrix.m[0][0] = m.m[0][0];
//   matrix.m[0][1] = m.m[1][0];
//   matrix.m[0][2] = m.m[2][0];
//   matrix.m[0][3] = 0.0f;
//   matrix.m[1][0] = m.m[0][1];
//   matrix.m[1][1] = m.m[1][1];
//   matrix.m[1][2] = m.m[2][1];
//   matrix.m[1][3] = 0.0f;
//   matrix.m[2][0] = m.m[0][2];
//   matrix.m[2][1] = m.m[1][2];
//   matrix.m[2][2] = m.m[2][2];
//   matrix.m[2][3] = 0.0f;
//   matrix.m[3][0] = -(m.m[3][0] * matrix.m[0][0] + m.m[3][1] * matrix.m[1][0]
//   +
//                      m.m[3][2] * matrix.m[2][0]);
//   matrix.m[3][1] = -(m.m[3][0] * matrix.m[0][1] + m.m[3][1] * matrix.m[1][1]
//   +
//                      m.m[3][2] * matrix.m[2][1]);
//   matrix.m[3][2] = -(m.m[3][0] * matrix.m[0][2] + m.m[3][1] * matrix.m[1][2]
//   +
//                      m.m[3][2] * matrix.m[2][2]);
//   matrix.m[3][3] = 1.0f;
//   return matrix;
// }
// TODO

// Create a Perspective Matrix
// mat3 mat3::perspective(float fovrads, float aspect, float near, float far) {
//   float tanHalfFov = tan(fovrads / 2.0f);

//   mat3 result;
//   result.m[0][0] = 1.0f / (aspect * tanHalfFov);
//   result.m[1][1] = 1.0f / (tanHalfFov);
//   result.m[2][2] = -(far + near) / (far - near);
//   result.m[2][3] = -1.0f;
//   result.m[3][2] = -(2.0f * far * near) / (far - near);
//   return result;
// }
// TODO

// Create an Orthographic Projection Matrix
//   mat3 mat3::ortho(float left, float right, float bottom, float top, float
//   near,
//                    float far) {
//     mat3 result = identity();
//     result.m[0][0] = 2.0f / (right - left);
//     result.m[1][1] = 2.0f / (top - bottom);
//     result.m[2][2] = -2.0f / (far - near);
//     result.m[3][0] = -(right + left) / (right - left);
//     result.m[3][1] = -(top + bottom) / (top - bottom);
//     result.m[3][2] = -(far + near) / (far - near);
//     return result;
//   }
// TODO

// TODO
// Create an X Rotation Matrix
//   mat3 mat3::rotationX(float rad) {
//     mat3 matrix;
//     matrix.m[0][0] = 1.0f;
//     matrix.m[1][1] = cosf(rad);
//     matrix.m[1][2] = sinf(rad);
//     matrix.m[2][1] = -sinf(rad);
//     matrix.m[2][2] = cosf(rad);
//     matrix.m[3][3] = 1.0f;
//     return matrix;
//   }

//   // Create a Y Rotation Matrix
//   mat3 mat3::rotationY(float rad) {
//     mat3 matrix;
//     matrix.m[0][0] = cosf(rad);
//     matrix.m[0][2] = sinf(rad);
//     matrix.m[2][0] = -sinf(rad);
//     matrix.m[1][1] = 1.0f;
//     matrix.m[2][2] = cosf(rad);
//     matrix.m[3][3] = 1.0f;
//     return matrix;
//   }

//   // Create a Z Rotation Matrix
//   mat3 mat3::rotationZ(float rad) {
//     mat3 matrix;
//     matrix.m[0][0] = cosf(rad);
//     matrix.m[0][1] = sinf(rad);
//     matrix.m[1][0] = -sinf(rad);
//     matrix.m[1][1] = cosf(rad);
//     matrix.m[2][2] = 1.0f;
//     matrix.m[3][3] = 1.0f;
//     return matrix;
//   }

//   // Create a Rotation Matrix
//   mat3 mat3::rotation(vec3 rad) {
//     mat3 matrix, x, y, z;

//     x = rotationX(rad.x);
//     y = rotationY(rad.y);
//     z = rotationZ(rad.z);

//     matrix = identity();
//     matrix = x * y;
//     matrix = matrix * z;

//     return matrix;
//   }

//   // Create a Translation Matrix
//   mat3 mat3::translation(vec3 v) {
//     mat3 matrix;
//     matrix.m[0][0] = 1.0f;
//     matrix.m[1][1] = 1.0f;
//     matrix.m[2][2] = 1.0f;
//     matrix.m[3][3] = 1.0f;
//     matrix.m[3][0] = v.x;
//     matrix.m[3][1] = v.y;
//     matrix.m[3][2] = v.z;
//     return matrix;
//   }

//   mat3 mat3::scale(vec3 v) {
//     mat3 matrix;
//     matrix.m[0][0] = v.x;
//     matrix.m[1][1] = v.y;
//     matrix.m[2][2] = v.z;
//     matrix.m[3][3] = 1.0f;
//     return matrix;
//   }

//   // Create a Look-At Matrix
//   mat3 mat3::lookat(vec3 pos, vec3 target, vec3 up) {
//     vec3 f = (target - pos).normalize();
//     vec3 s = vec3::cross(f, up).normalize();
//     vec3 u = vec3::cross(s, f);

//     mat3 result = identity();
//     result.m[0][0] = s.x;
//     result.m[1][0] = s.y;
//     result.m[2][0] = s.z;
//     result.m[0][1] = u.x;
//     result.m[1][1] = u.y;
//     result.m[2][1] = u.z;
//     result.m[0][2] = -f.x;
//     result.m[1][2] = -f.y;
//     result.m[2][2] = -f.z;
//     result.m[3][0] = -vec3::dot(s, pos);
//     result.m[3][1] = -vec3::dot(u, pos);
//     result.m[3][2] = vec3::dot(f, pos);
//     return result;
//   }

} // namespace EngineToolkit