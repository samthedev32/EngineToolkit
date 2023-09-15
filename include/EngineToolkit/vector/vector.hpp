#pragma once

#include <cstdarg>
#include <cstdint>
#include <vector>

namespace EngineToolkit {

#define ETK_VECTOR_TEMPLATE template <uint8_t D, typename T>

// XD Vector
template <uint8_t D, typename T = float> struct vec {
  T data[D];

  // ---- Constructors

  vec(T v = 0);
  vec(std::vector<T> v);
  vec(vec const &v);

  // ---- Destructor

  ~vec();

  // ---- Operators

  vec operator+(const vec v) const;
  vec operator-(const vec v) const;
  vec operator*(const vec v) const;
  vec operator/(const vec v) const;

  void operator+=(const vec v);
  void operator-=(const vec v);
  void operator*=(const vec v);
  void operator/=(const vec v);

  void operator=(const vec v);

  bool operator==(const vec v) const;
  bool operator!=(const vec v) const;

  T operator[](int i) const;
  T &operator[](int i);

  // ---- Functions (Instance Methods)

  // Convert to Different Dimension
  template <uint8_t nD> vec<nD, T> to() {
    vec<nD, T> out;
    for (uint8_t i = 0; i < std::min(D, nD); i++)
      out.data[i] = this->data[i];
    return out;
  }

  // Length
  T length();

  // Normalize
  vec normalize();

  // ---- Functions (Static)

  // Distance
  static T distance(vec a, vec b);

  // Dot Product
  static T dot(vec a, vec b);

  // Linearly Interpolate
  static vec lerp(vec a, vec b, T blend);

  // ---- Functions (Dimension-Specific)

  // Cross Product
  static vec<3> cross(vec<3> a, vec<3> b);
};

// -------- Implementation

// ---- Constructors

ETK_VECTOR_TEMPLATE vec<D, T>::vec(T v) {
  for (int i = 0; i < D; i++)
    this->data[i] = v;
}

ETK_VECTOR_TEMPLATE vec<D, T>::vec(std::vector<T> v) {
  memcpy(this->data, v.data(), std::min(D, v.size()));
}

ETK_VECTOR_TEMPLATE vec<D, T>::vec(vec<D, T> const &v) {
  for (int i = 0; i < D; i++)
    this->data[i] = v[i];
}

// ---- Destructor

ETK_VECTOR_TEMPLATE vec<D, T>::~vec() {}

// ---- Operators

ETK_VECTOR_TEMPLATE
vec<D, T> vec<D, T>::operator+(const vec<D, T> v) const {
  vec<D, T> ret;
  for (int i = 0; i < D; i++)
    ret.p[i] = this->data[i] + v.p[i];
  return ret;
}

ETK_VECTOR_TEMPLATE
vec<D, T> vec<D, T>::operator-(const vec<D, T> v) const {
  vec<D, T> ret;
  for (int i = 0; i < D; i++)
    ret.p[i] = this->data[i] - v.p[i];
  return ret;
}

ETK_VECTOR_TEMPLATE
vec<D, T> vec<D, T>::operator*(const vec<D, T> v) const {
  vec<D, T> ret;
  for (int i = 0; i < D; i++)
    ret.p[i] = this->data[i] * v.p[i];
  return ret;
}

ETK_VECTOR_TEMPLATE
vec<D, T> vec<D, T>::operator/(const vec<D, T> v) const {
  vec<D, T> ret;
  for (int i = 0; i < D; i++)
    ret.p[i] = this->data[i] / v.p[i];
  return ret;
}

ETK_VECTOR_TEMPLATE
void vec<D, T>::operator+=(const vec<D, T> v) {
  for (int i = 0; i < D; i++)
    this->data[i] += v.p[i];
}

ETK_VECTOR_TEMPLATE
void vec<D, T>::operator-=(const vec<D, T> v) {
  for (int i = 0; i < D; i++)
    this->data[i] -= v.p[i];
}

ETK_VECTOR_TEMPLATE
void vec<D, T>::operator*=(const vec<D, T> v) {
  for (int i = 0; i < D; i++)
    this->data[i] *= v.p[i];
}

ETK_VECTOR_TEMPLATE
void vec<D, T>::operator/=(const vec<D, T> v) {
  for (int i = 0; i < D; i++)
    this->data[i] /= v.p[i];
}

ETK_VECTOR_TEMPLATE
void vec<D, T>::operator=(const vec<D, T> v) {
  for (int i = 0; i < D; i++)
    this->data[i] = v.p[i];
}

ETK_VECTOR_TEMPLATE
bool vec<D, T>::operator==(const vec<D, T> v) const {
  for (int i = 0; i < D; i++)
    if (this->data[i] != v.p[i])
      return false;
  return true;
}

ETK_VECTOR_TEMPLATE
bool vec<D, T>::operator!=(const vec<D, T> v) const { return *this != v; }

// ---- Indexing

ETK_VECTOR_TEMPLATE T vec<D, T>::operator[](int i) const {
  return this->data[i % D];
}

ETK_VECTOR_TEMPLATE T &vec<D, T>::operator[](int i) {
  return this->data[i % D];
}

// ---- Functions (Instance Methods)

ETK_VECTOR_TEMPLATE T vec<D, T>::length() {
  return sqrtf(vec<D, T>::dot(*this, *this));
}

ETK_VECTOR_TEMPLATE vec<D, T> vec<D, T>::normalize() {
  return *this / this->length();
}

// ---- Functions (Static)

ETK_VECTOR_TEMPLATE
T vec<D, T>::distance(vec<D, T> a, vec<D, T> b) {
  vec<D, T> dist = a - b;
  T out;
  for (int i = 0; i < D; i++)
    out += dist[i] * dist[i];
  return sqrt(out);
}

ETK_VECTOR_TEMPLATE
T vec<D, T>::dot(vec<D, T> a, vec<D, T> b) {
  T out;
  for (int i = 0; i < D; i++)
    out += a[i] * b[i];
  return out;
}

ETK_VECTOR_TEMPLATE
vec<D, T> vec<D, T>::lerp(vec<D, T> a, vec<D, T> b, T blend) {
  vec<D, T> out;
  for (int i = 0; i < D; i++)
    out[i] = a[i] + (b[i] - a[i]) * blend;
  return out;
}

// Common Types
typedef vec<2> vec2;
typedef vec<3> vec3;
typedef vec<4> vec4;

} // namespace EngineToolkit