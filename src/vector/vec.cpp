#include <EngineToolkit/vector/vec.hpp>

namespace EngineToolkit {

// ---- Constructors

template <unsigned int dimensions> vec<dimensions>::vec(vec1 v[dimensions]) {
  for (int i = 0; i < dimensions; i++)
    this[i] = v[i];
}

template <unsigned int dimensions>
vec<dimensions>::vec(vec<dimensions> const &v) {
  for (int i = 0; i < dimensions; i++)
    this[i] = v[i];
}

// template <unsigned int dimensions>
// vec<dimensions> vec<dimensions>::vec(vec<dimensions> v) const {
//   vec<dimensions> ret;
//   for (int i = 0; i < dimensions; i++)
//     ret.p[i] = this->p[i] + v.p[i];
//   return ret;
// }

// ---- Operator Overloading

template <unsigned int dimensions>
vec<dimensions> vec<dimensions>::operator+(const vec<dimensions> v) const {
  vec<dimensions> ret;
  for (int i = 0; i < dimensions; i++)
    ret.p[i] = this->p[i] + v.p[i];
  return ret;
}

template <unsigned int dimensions>
vec<dimensions> vec<dimensions>::operator-(const vec<dimensions> v) const {
  vec<dimensions> ret;
  for (int i = 0; i < dimensions; i++)
    ret.p[i] = this->p[i] - v.p[i];
  return ret;
}

template <unsigned int dimensions>
vec<dimensions> vec<dimensions>::operator*(const vec<dimensions> v) const {
  vec<dimensions> ret;
  for (int i = 0; i < dimensions; i++)
    ret.p[i] = this->p[i] * v.p[i];
  return ret;
}

template <unsigned int dimensions>
vec<dimensions> vec<dimensions>::operator/(const vec<dimensions> v) const {
  vec<dimensions> ret;
  for (int i = 0; i < dimensions; i++)
    ret.p[i] = this->p[i] / v.p[i];
  return ret;
}

template <unsigned int dimensions>
void vec<dimensions>::operator+=(const vec<dimensions> v) {
  for (int i = 0; i < dimensions; i++)
    this->p[i] += v.p[i];
}

template <unsigned int dimensions>
void vec<dimensions>::operator-=(const vec<dimensions> v) {
  for (int i = 0; i < dimensions; i++)
    this->p[i] -= v.p[i];
}

template <unsigned int dimensions>
void vec<dimensions>::operator*=(const vec<dimensions> v) {
  for (int i = 0; i < dimensions; i++)
    this->p[i] *= v.p[i];
}

template <unsigned int dimensions>
void vec<dimensions>::operator/=(const vec<dimensions> v) {
  for (int i = 0; i < dimensions; i++)
    this->p[i] /= v.p[i];
}

template <unsigned int dimensions>
void vec<dimensions>::operator=(const vec<dimensions> v) {
  for (int i = 0; i < dimensions; i++)
    this->p[i] = v.p[i];
}

template <unsigned int dimensions>
bool vec<dimensions>::operator==(const vec<dimensions> v) const {
  for (int i = 0; i < dimensions; i++)
    if (this->p[i] != v.p[i])
      return false;
  return true;
}

template <unsigned int dimensions>
bool vec<dimensions>::operator!=(const vec<dimensions> v) const {
  return *this != v;
}

// ---- Indexing

template <unsigned int dimensions>
vec1 vec<dimensions>::operator[](int i) const {
  return this->p[i % dimensions];
}

template <unsigned int dimensions> vec1 &vec<dimensions>::operator[](int i) {
  return this->p[i % dimensions];
}

// ---- Functions (Instance Methods)

template <unsigned int dimensions> vec1 vec<dimensions>::length() {
  return sqrtf(vec<dimensions>::dot(*this, *this));
}

template <unsigned int dimensions>
vec1 vec<dimensions>::distance(vec<dimensions> v) {
  vec<dimensions> dist = *this - v;
  vec1 out;
  for (int i = 0; i < dimensions; i++)
    out += dist[i] * dist[i];
  return sqrt(out);
}

template <unsigned int dimensions>
vec<dimensions> vec<dimensions>::normalize() {
  return *this / this->length();
}

// ---- Functions (Static)

template <unsigned int dimensions>
vec1 vec<dimensions>::dot(vec<dimensions> a, vec<dimensions> b) {
  vec1 out;
  for (int i = 0; i < dimensions; i++)
    out += a[i] * b[i];
  return out;
}

template <unsigned int dimensions>
vec<dimensions> vec<dimensions>::lerp(vec<dimensions> a, vec<dimensions> b,
                                      vec1 blend) {
  vec<dimensions> out;
  for (int i = 0; i < dimensions; i++)
    out[i] = a[i] + (b[i] - a[i]) * blend;
  return out;
}

} // namespace EngineToolkit