#pragma once

#include <EngineToolkit/math/vector/vec3.hpp>
#include <EngineToolkit/math/vector/vec4.hpp>

#include <EngineToolkit/math/matrix/mat3.hpp>
#include <EngineToolkit/math/matrix/mat4.hpp>

namespace EngineToolkit {

// Quaternions
struct Quaternion {
  vec4 q;

  // Constructors & Destructor

  Quaternion();
  Quaternion(vec1 x, vec1 y, vec1 z, vec1 w);
  Quaternion(vec3 euler);
  Quaternion(vec4 q);
  Quaternion(mat3 m);
  Quaternion(mat4 m);

  ~Quaternion();

  // Arithmetic Operators

  Quaternion operator+(const Quaternion &v) const;
  Quaternion operator-(const Quaternion &v) const;
  Quaternion operator*(const Quaternion &v) const;
  Quaternion operator/(const Quaternion &v) const;

  // Assignment Operators

  void operator=(const Quaternion &v);
  void operator+=(const Quaternion &v);
  void operator-=(const Quaternion &v);
  void operator*=(const Quaternion &v);
  void operator/=(const Quaternion &v);

  // Relational Operators

  bool operator==(const Quaternion &v) const;
  bool operator!=(const Quaternion &v) const;
  bool operator>(const Quaternion &v) const;
  bool operator<(const Quaternion &v) const;
  bool operator>=(const Quaternion &v) const;
  bool operator<=(const Quaternion &v) const;

  // Other Operators

  vec1 operator[](uint8_t i) const;
  vec1 &operator[](uint8_t i);

  // Functions (Instance Methods)

  vec1 length() const;
  Quaternion normalize() const;
  Quaternion conjugate() const;
  Quaternion inverse() const;

  vec3 toVec3() const;
  mat3 toMat3() const;
  mat4 toMat4() const;

  // Functions (Static)

  static Quaternion slerp(Quaternion a, Quaternion b, vec1 blend);
  static Quaternion nlerp(Quaternion a, Quaternion b, vec1 blend);
};

} // namespace EngineToolkit