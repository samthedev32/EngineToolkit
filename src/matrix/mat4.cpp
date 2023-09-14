#include <EngineToolkit/matrix/mat4.hpp>

#include <stdlib.h>
#include <string.h>

namespace EngineToolkit {

// ---- Constructors

mat4::mat4(float v) { *this = v; }
mat4::mat4(mat4 const &m) { *this = m; }

// ---- Destructor

mat4::~mat4() { *this = 0.0f; }

// ---- Operators

void mat4::operator=(const mat4 m) {
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      this->m[i][j] = m.m[i][j];
}

bool mat4::operator==(const mat4 m) const {
  for (int c = 0; c < 4; c++)
    for (int r = 0; r < 4; r++)
      if (this->m[r][c] != m.m[r][c])
        return false;
  return true;
}

bool mat4::operator!=(const mat4 m) const { return !(*this == m); }

mat4 mat4::operator*(const mat4 m) const {
  mat4 matrix;
  for (int c = 0; c < 4; c++)
    for (int r = 0; r < 4; r++)
      matrix.m[r][c] = this->m[r][0] * m.m[0][c] + this->m[r][1] * m.m[1][c] +
                       this->m[r][2] * m.m[2][c] + this->m[r][3] * m.m[3][c];
  return matrix;
}

vec3 mat4::operator*(const vec3 v) const {
  return vec3(v.x * this->m[0][0] + v.y * this->m[1][0] + v.z * this->m[2][0] +
                  1 * this->m[3][0],
              v.x * this->m[0][1] + v.y * this->m[1][1] + v.z * this->m[2][1] +
                  1 * this->m[3][1],
              v.x * this->m[0][2] + v.y * this->m[1][2] + v.z * this->m[2][2] +
                  1 * this->m[3][2]);
}

void mat4::operator*=(const mat4 m) { *this = *this * m; }

// TODO: test
void mat4::inverse() {
  mat4 matrix = *this;
  this->m[0][0] = matrix.m[0][0];
  this->m[0][1] = matrix.m[1][0];
  this->m[0][2] = matrix.m[2][0];
  this->m[0][3] = 0.0f;
  this->m[1][0] = matrix.m[0][1];
  this->m[1][1] = matrix.m[1][1];
  this->m[1][2] = matrix.m[2][1];
  this->m[1][3] = 0.0f;
  this->m[2][0] = matrix.m[0][2];
  this->m[2][1] = matrix.m[1][2];
  this->m[2][2] = matrix.m[2][2];
  this->m[2][3] = 0.0f;
  this->m[3][0] =
      -(matrix.m[3][0] * this->m[0][0] + matrix.m[3][1] * this->m[1][0] +
        matrix.m[3][2] * this->m[2][0]);
  this->m[3][1] =
      -(matrix.m[3][0] * this->m[0][1] + matrix.m[3][1] * this->m[1][1] +
        matrix.m[3][2] * this->m[2][1]);
  this->m[3][2] =
      -(matrix.m[3][0] * this->m[0][2] + matrix.m[3][1] * this->m[1][2] +
        matrix.m[3][2] * this->m[2][2]);
  this->m[3][3] = 1.0f;
}

mat4 mat4::identity() {
  mat4 matrix;

  for (int i = 0; i < 4; i++)
    matrix.m[i][i] = 1.0f;

  return matrix;
}

mat4 mat4::rotationX(float rad) {
  mat4 matrix;
  matrix.m[0][0] = 1.0f;
  matrix.m[1][1] = cosf(rad);
  matrix.m[1][2] = sinf(rad);
  matrix.m[2][1] = -sinf(rad);
  matrix.m[2][2] = cosf(rad);
  matrix.m[3][3] = 1.0f;
  return matrix;
}

mat4 mat4::rotationY(float rad) {
  mat4 matrix;
  matrix.m[0][0] = cosf(rad);
  matrix.m[0][2] = sinf(rad);
  matrix.m[2][0] = -sinf(rad);
  matrix.m[1][1] = 1.0f;
  matrix.m[2][2] = cosf(rad);
  matrix.m[3][3] = 1.0f;
  return matrix;
}

mat4 mat4::rotationZ(float rad) {
  mat4 matrix;
  matrix.m[0][0] = cosf(rad);
  matrix.m[0][1] = sinf(rad);
  matrix.m[1][0] = -sinf(rad);
  matrix.m[1][1] = cosf(rad);
  matrix.m[2][2] = 1.0f;
  matrix.m[3][3] = 1.0f;
  return matrix;
}

mat4 mat4::rotation(vec3 rad) {
  mat4 matrix, x, y, z;

  x = rotationX(rad.x);
  y = rotationY(rad.y);
  z = rotationZ(rad.z);

  matrix = identity();
  matrix = x * y;
  matrix = matrix * z;

  return matrix;
}

mat4 mat4::translation(vec3 v) {
  mat4 matrix;
  matrix.m[0][0] = 1.0f;
  matrix.m[1][1] = 1.0f;
  matrix.m[2][2] = 1.0f;
  matrix.m[3][3] = 1.0f;
  matrix.m[3][0] = v.x;
  matrix.m[3][1] = v.y;
  matrix.m[3][2] = v.z;
  return matrix;
}

mat4 mat4::scale(vec3 v) {
  mat4 matrix;
  matrix.m[0][0] = v.x;
  matrix.m[1][1] = v.y;
  matrix.m[2][2] = v.z;
  matrix.m[3][3] = 1.0f;
  return matrix;
}

mat4 mat4::perspective(float fovrads, float aspect, float near, float far) {
  float tanHalfFov = tan(fovrads / 2.0f);

  mat4 result;
  result.m[0][0] = 1.0f / (aspect * tanHalfFov);
  result.m[1][1] = 1.0f / (tanHalfFov);
  result.m[2][2] = -(far + near) / (far - near);
  result.m[2][3] = -1.0f;
  result.m[3][2] = -(2.0f * far * near) / (far - near);
  return result;
}

mat4 mat4::ortho(float left, float right, float bottom, float top, float near,
                 float far) {
  mat4 result = identity();
  result.m[0][0] = 2.0f / (right - left);
  result.m[1][1] = 2.0f / (top - bottom);
  result.m[2][2] = -2.0f / (far - near);
  result.m[3][0] = -(right + left) / (right - left);
  result.m[3][1] = -(top + bottom) / (top - bottom);
  result.m[3][2] = -(far + near) / (far - near);
  return result;
}

mat4 mat4::lookat(vec3 pos, vec3 target, vec3 up) {
  vec3 f = (target - pos).normalize();
  vec3 s = vec3::cross(f, up).normalize();
  vec3 u = vec3::cross(s, f);

  mat4 result = identity();
  result.m[0][0] = s.x;
  result.m[1][0] = s.y;
  result.m[2][0] = s.z;
  result.m[0][1] = u.x;
  result.m[1][1] = u.y;
  result.m[2][1] = u.z;
  result.m[0][2] = -f.x;
  result.m[1][2] = -f.y;
  result.m[2][2] = -f.z;
  result.m[3][0] = -vec3::dot(s, pos);
  result.m[3][1] = -vec3::dot(u, pos);
  result.m[3][2] = vec3::dot(f, pos);
  return result;
}

} // namespace EngineToolkit