#pragma once

#ifndef ENGINETK_INCLUDE_VECTOR
#error This fil SHOULD NOT be included
#endif

struct vec;

// ---- Constructors

// Create Vector with Init Value
template <uint8_t D, typedef T> vec<D, T>::vec(T v = 0) { *this = v; }

// Create Vector from Other Vector
template <uint8_t D, Arithmetic T> VEC_FUNC vec<D, T>::vec(vec<inD, inT> v) {
  *this = v;
}

// ---- Destructor

~vec() {}

// ---- Arithmetic Operators

// Addition
VEC_FUNC
vec<D, T> vec<D, T>::operator+(const vec<inD, inT> &v) const {
  vec<D, T> ret;
  for (uint8_t i = 0; i < std::min(D, inD); i++)
    ret.data[i] = this->data[i] + v.data[i];
  return ret;
}

// Subtraction
VEC_FUNC
vec<D, T> vec<D, T>::operator-(const vec<inD, inT> &v) const {
  vec<D, T> ret;
  for (uint8_t i = 0; i < D; i++)
    ret.data[i] = this->data[i] - v.data[i];
  return ret;
}

// Multiplication
VEC_FUNC
vec<D, T> vec<D, T>::operator*(const vec<inD, inT> &v) const {
  vec<D, T> ret;
  for (uint8_t i = 0; i < D; i++)
    ret.data[i] = this->data[i] * v.data[i];
  return ret;
}

// Division
VEC_FUNC
vec<D, T> vec<D, T>::operator/(const vec<inD, inT> &v) const {
  vec<D, T> ret;
  for (uint8_t i = 0; i < D; i++)
    ret.data[i] = this->data[i] / v.data[i];
  return ret;
}

// Modulo
VEC_FUNC
vec<D, T> vec<D, T>::operator%(const vec<inD, inT> &v) const {
  vec<D, T> ret;
  for (uint8_t i = 0; i < D; i++)
    ret.data[i] = this->data[i] % v.data[i];
  return ret;
}

// ---- Increment & Decrement Operators

// Increase
VEC_FUNC void vec<D, T>::operator++() {
  for (uint8_t i = 0; i < D; i++)
    this->data[i]++;
}

// Decrease
VEC_FUNC void vec<D, T>::operator--() {
  for (uint8_t i = 0; i < D; i++)
    this->data[i]--;
}

// Negation
vec<D, T> vec<D, T>::operator-() const { return *this * -1.0f; }

// ---- Assignment Operators

// Set
// TODO: validate
VEC_FUNC void vec<D, T>::operator=(const vec<inD, inT> v) {
  for (uint8_t i = 0; i < D; i++)
    if (i < inD)
      this->data[i] = v.data[i];
    else
      this->data[i] = 0;
}

// Addition
VEC_FUNC void vec<D, T>::operator+=(const vec<inD, inT> v) {
  *this = *this + v;
}

// Subtraction
VEC_FUNC void vec<D, T>::operator-=(const vec<inD, inT> v) {
  *this = *this - v;
}

// Multiplication
VEC_FUNC void vec<D, T>::operator*=(const vec<inD, inT> v) {
  *this = *this * v;
}

// Division
VEC_FUNC void vec<D, T>::operator/=(const vec<inD, inT> v) {
  *this = *this / v;
}

// Modulo
VEC_FUNC void vec<D, T>::operator%=(const vec<inD, inT> v) {
  *this = *this % v;
}

// // ---- Relational Operators

// Is Equal To
VEC_FUNC
bool vec<D, T>::operator==(const vec<inD, inT> v) const {
  for (uint8_t i = 0; i < D; i++)
    if (this->data[i] != v.data[i])
      return false;
  return true;
}

// Not Equal To
VEC_FUNC
bool vec<D, T>::operator!=(const vec<inD, inT> v) const {
  return !(*this == v);
}

// Greater Than
VEC_FUNC
bool vec<D, T>::operator>(const vec<inD, inT> v) const {
  return this->length() > v.length();
}

// Less Than
VEC_FUNC
bool vec<D, T>::operator<(const vec<inD, inT> v) const {
  return this->length() < v.length();
}

// // Greater Than or Equal To
// VEC_FUNC
// bool vec<D, T>::operator>=(const vec<inD, inT> v) const {
//   return this->length() >= v.length();
// }

// // Less Than or Equal To
// VEC_FUNC
// bool vec<D, T>::operator<=(const vec<inD, inT> v) const {
//   return this->length() <= v.length();
// }

// ---- Indexing

T vec<D, T>::operator[](uint8_t i) const { return this->data[i % D]; }

T &vec<D, T>::operator[](uint8_t i) { return this->data[i % D]; }

// ---- Constructors

// ---- Destructor

// ~vec() {}

// // ---- Operators

// // ---- Indexing

// // ---- Functions (Instance Methods)

// T length() { return sqrtf(dot(*this, *this)); }

// vec<D> normalize() { return *this / this->length(); }

// // ---- Functions (Static)

// T distance(vec a, vec b) {
//   vec<D> dist = a - b;
//   T out;
//   for (uint8_t i = 0; i < D; i++)
//     out += dist[i] * dist[i];
//   return sqrt(out);
// }

// T dot(vec a, vec b) {
//   T out;
//   for (uint8_t i = 0; i < D; i++)
//     out += a[i] * b[i];
//   return out;
// }

// vec<D> lerp(vec a, vec b blend) {
//   vec<D> out;
//   for (uint8_t i = 0; i < D; i++)
//     out[i] = a[i] + (b[i] - a[i]) * blend;
//   return out;
// }

#undef template < uint8_t inD>

// ---- Common Types

// 2 Dimensional Vector
typedef vec<2> vec2;

// 3 Dimensional Vector
typedef vec<3> vec3;

// 4 Dimensional Vector
typedef vec<4> vec4;