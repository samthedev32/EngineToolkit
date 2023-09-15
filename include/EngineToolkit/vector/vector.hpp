#pragma once

#include <cmath>
#include <cstdarg>
#include <cstdint>
#include <vector>

namespace EngineToolkit {

// Vector Type
typedef float vecT;

// Variable Dimension Vector
template <uint8_t D = 3> struct vec {
  vecT data[D];

  // Constructors & Destructor

  vec(vecT v = 0);
  vec(std::vector<vecT> v);
  template <uint8_t inD> vec(vec<inD> v);

  ~vec();

  // Arithmetic Operators

  template <uint8_t inD> vec<D> operator+(const vec<inD> &v) const;
  template <uint8_t inD> vec<D> operator-(const vec<inD> &v) const;
  template <uint8_t inD> vec<D> operator*(const vec<inD> &v) const;
  template <uint8_t inD> vec<D> operator/(const vec<inD> &v) const;
  template <uint8_t inD> vec<D> operator%(const vec<inD> &v) const;

  // Assignment Operators

  template <uint8_t inD> void operator=(const vec<inD> &v);
  template <uint8_t inD> void operator+=(const vec<inD> &v);
  template <uint8_t inD> void operator-=(const vec<inD> &v);
  template <uint8_t inD> void operator*=(const vec<inD> &v);
  template <uint8_t inD> void operator/=(const vec<inD> &v);
  template <uint8_t inD> void operator%=(const vec<inD> &v);

  // Relational Operators

  template <uint8_t inD> bool operator==(const vec<inD> &v) const;
  template <uint8_t inD> bool operator!=(const vec<inD> &v) const;
  template <uint8_t inD> bool operator>(const vec<inD> &v) const;
  template <uint8_t inD> bool operator<(const vec<inD> &v) const;
  template <uint8_t inD> bool operator>=(const vec<inD> &v) const;
  template <uint8_t inD> bool operator<=(const vec<inD> &v) const;

  // Other Operators

  vecT operator[](uint8_t i) const;
  vecT &operator[](uint8_t i);

  void operator++();
  void operator--();

  // Functions (Instance Methods)

  vecT length() const;
  vec normalize() const;

  // Functions (Static)

  static vecT distance(vec a, vec b);
  static vecT dot(vec a, vec b);
  static vec lerp(vec a, vec b, vecT blend);

  // Functions (Dimension-Specific)

  static vec<3> cross(vec<3> a, vec<3> b);
};

typedef vec<2> vec2;
typedef vec<3> vec3;
typedef vec<4> vec4;

// Constructors & Destructor

template <uint8_t D> vec<D>::vec(vecT v) {
  for (uint8_t i = 0; i < D; i++)
    this->data[i] = v;
}

template <uint8_t D> vec<D>::vec(std::vector<vecT> v) {
  for (int i = 0; i < D; i++)
    this->data[i] = i < v.size() ? v[i] : 0;
}

template <uint8_t D> template <uint8_t inD> vec<D>::vec(vec<inD> v) {
  *this = v;
}

template <uint8_t D> vec<D>::~vec() {}

// Arithmetic Operators

template <uint8_t D>
template <uint8_t inD>
vec<D> vec<D>::operator+(const vec<inD> &v) const {
  vec<D> ret;
  for (uint8_t i = 0; i < std::min(D, inD); i++)
    ret.data[i] = this->data[i] + v.data[i];
  return ret;
}

template <uint8_t D>
template <uint8_t inD>
vec<D> vec<D>::operator-(const vec<inD> &v) const {
  vec<D> ret;
  for (uint8_t i = 0; i < std::min(D, inD); i++)
    ret.data[i] = this->data[i] - v.data[i];
  return ret;
}

template <uint8_t D>
template <uint8_t inD>
vec<D> vec<D>::operator*(const vec<inD> &v) const {
  vec<D> ret;
  for (uint8_t i = 0; i < std::min(D, inD); i++)
    ret.data[i] = this->data[i] * v.data[i];
  return ret;
}

template <uint8_t D>
template <uint8_t inD>
vec<D> vec<D>::operator/(const vec<inD> &v) const {
  vec<D> ret;
  for (uint8_t i = 0; i < std::min(D, inD); i++)
    ret.data[i] = this->data[i] / v.data[i];
  return ret;
}

template <uint8_t D>
template <uint8_t inD>
vec<D> vec<D>::operator%(const vec<inD> &v) const {
  vec<D> ret;
  for (uint8_t i = 0; i < std::min(D, inD); i++)
    ret.data[i] = this->data[i] % v.data[i];
  return ret;
}

// Assignment Operators

template <uint8_t D>
template <uint8_t inD>
void vec<D>::operator=(const vec<inD> &v) {
  for (uint8_t i = 0; i < D; i++)
    this->data[i] = i < inD ? v.data[i] : 0;
}

template <uint8_t D>
template <uint8_t inD>
void vec<D>::operator+=(const vec<inD> &v) {
  *this = *this + v;
}

template <uint8_t D>
template <uint8_t inD>
void vec<D>::operator-=(const vec<inD> &v) {
  *this = *this - v;
}

template <uint8_t D>
template <uint8_t inD>
void vec<D>::operator*=(const vec<inD> &v) {
  *this = *this * v;
}

template <uint8_t D>
template <uint8_t inD>
void vec<D>::operator/=(const vec<inD> &v) {
  *this = *this / v;
}

template <uint8_t D>
template <uint8_t inD>
void vec<D>::operator%=(const vec<inD> &v) {
  *this = *this % v;
}

// Relational Operators

template <uint8_t D>
template <uint8_t inD>
bool vec<D>::operator==(const vec<inD> &v) const {
  for (uint8_t i = 0; i < D; i++)
    if (this->data[i] != v.data[i])
      return false;
  return true;
}

template <uint8_t D>
template <uint8_t inD>
bool vec<D>::operator!=(const vec<inD> &v) const {
  for (uint8_t i = 0; i < D; i++)
    if (this->data[i] == v.data[i])
      return false;
  return true;
}

template <uint8_t D>
template <uint8_t inD>
bool vec<D>::operator>(const vec<inD> &v) const {
  return false;
}

template <uint8_t D>
template <uint8_t inD>
bool vec<D>::operator<(const vec<inD> &v) const {
  return false;
}

template <uint8_t D>
template <uint8_t inD>
bool vec<D>::operator>=(const vec<inD> &v) const {
  return false;
}

template <uint8_t D>
template <uint8_t inD>
bool vec<D>::operator<=(const vec<inD> &v) const {
  return false;
}

// Other Operators

template <uint8_t D> vecT vec<D>::operator[](uint8_t i) const {
  return this->data[i % D];
}

template <uint8_t D> vecT &vec<D>::operator[](uint8_t i) {
  return this->data[i % D];
}

template <uint8_t D> void vec<D>::operator++() { *this += 1.0f; }

template <uint8_t D> void vec<D>::operator--() { *this -= 1.0f; }

// Functions (Instance Methods)

template <uint8_t D> vecT vec<D>::length() const {
  return sqrtf(dot(*this, *this));
}

template <uint8_t D> vec<D> vec<D>::normalize() const {
  return *this / this->length();
}

// Functions (Static)

template <uint8_t D> vecT vec<D>::distance(vec a, vec b) {
  vecT out;

  vec<D> dist = a - b;
  for (uint8_t i = 0; i < D; i++)
    out += dist[i] * dist[i];

  return sqrt(out);
}

template <uint8_t D> vecT vec<D>::dot(vec a, vec b) {
  vecT out;

  for (uint8_t i = 0; i < D; i++)
    out += a[i] * b[i];

  return out;
}

template <uint8_t D> vec<D> vec<D>::lerp(vec<D> a, vec<D> b, vecT blend) {
  vec<D> out;

  for (uint8_t i = 0; i < D; i++)
    out[i] = a.data[i] + (b.data[i] - a.data[i]) * blend;

  return out;
}

// Functions (Dimension-Specific)

template <uint8_t D> vec<3> vec<D>::cross(vec<3> a, vec<3> b) {
  return std::vector<vecT>({a.data[1] * b.data[2] - a.data[2] * b.data[1],
                            a.data[2] * b.data[0] - a.data[0] * b.data[2],
                            a.data[0] * b.data[1] - a.data[1] * b.data[0]});
}

} // namespace EngineToolkit