#pragma once

#include "mat.hpp"

namespace EngineToolkit {

// Quaternions
struct quat {
  union {
    vec<4> q;

    struct {
      float x, y, z, w;
    };
  };

  // Constructors & Destructor

  quat();
  quat(float x, float y, float z, float w);
  quat(vec<3> euler);
  quat(vec<4> q);
  quat(mat<3> m);
  quat(mat<4> m);

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

  float operator[](uint8_t i) const;
  float &operator[](uint8_t i);

  // Functions (Instance Methods)

  float length() const;
  quat normalize() const;
  quat conjugate() const;
  quat inverse() const;

  vec<3> toVec3() const;
  mat<3> toMat3() const;
  mat<4> toMat4() const;

  // Functions (Static)

  static quat slerp(quat a, quat b, float blend);
  static quat nlerp(quat a, quat b, float blend);
};

} // namespace EngineToolkit