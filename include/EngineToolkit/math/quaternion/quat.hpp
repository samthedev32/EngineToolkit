#pragma once

#include <EngineToolkit/math/vector/vec3.hpp>
#include <EngineToolkit/math/vector/vec4.hpp>

#include <EngineToolkit/math/matrix/mat3.hpp>
#include <EngineToolkit/math/matrix/mat4.hpp>

namespace EngineToolkit {

// Quaternions
struct quat {
  vec4 q;

  // Constructors & Destructor

  quat();
  quat(vec1 x, vec1 y, vec1 z, vec1 w);
  quat(vec3 euler);
  quat(vec4 q);
  quat(mat3 m);
  quat(mat4 m);

  ~quat();

  // Arithmetic Operators

  quat operator+(const quat &v) const;
  quat operator-(const quat &v) const;
  quat operator*(const quat &v) const;
  quat operator/(const quat &v) const;

  // Assignment Operators

  void operator=(const quat &v);
  void operator+=(const quat &v);
  void operator-=(const quat &v);
  void operator*=(const quat &v);
  void operator/=(const quat &v);

  // Relational Operators

  bool operator==(const quat &v) const;
  bool operator!=(const quat &v) const;
  bool operator>(const quat &v) const;
  bool operator<(const quat &v) const;
  bool operator>=(const quat &v) const;
  bool operator<=(const quat &v) const;

  // Other Operators

  vec1 operator[](uint8_t i) const;
  vec1 &operator[](uint8_t i);

  // Functions (Instance Methods)

  vec1 length() const;
  quat normalize() const;
  quat conjugate() const;
  quat inverse() const;

  vec3 toVec3() const;
  mat3 toMat3() const;
  mat4 toMat4() const;

  // Functions (Static)

  static quat slerp(quat a, quat b, vec1 blend);
  static quat nlerp(quat a, quat b, vec1 blend);
};

} // namespace EngineToolkit