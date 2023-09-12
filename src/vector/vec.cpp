#include <EngineToolkit/vector/vec.hpp>

// ---- Constructors

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
  return sqrt(dist.x * dist.x + dist.y * dist.y + dist.z * dist.z);
}

template <unsigned int dimensions>
vec<dimensions> vec<dimensions>::normalize() {
  return *this / this->length();
}

// ---- Functions (Static)

template <unsigned int dimensions>
vec1 vec<dimensions>::dot(vec<dimensions> a, vec<dimensions> b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

template <unsigned int dimensions>
vec<dimensions> vec<dimensions>::lerp(vec<dimensions> a, vec<dimensions> b,
                                      vec1 blend) {
  return {a.x + (b.x - a.x) * blend, a.y + (b.y - a.y) * blend,
          a.z + (b.z - a.z) * blend};
}