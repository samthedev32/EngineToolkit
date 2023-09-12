#include <EngineToolkit/vector/vec4.hpp>

// ---- Constructors

vec4::vec4(vec1 x, vec1 y, vec1 z, vec1 w) {
  this->x = x, this->y = y, this->z = z, this->w = w;
}
vec4::vec4(vec1 v[4]) {
  this->x = v[0], this->y = v[1], this->z = v[2], this->w = v[3];
}

vec4::vec4(vec1 v) { this->x = v, this->y = v, this->z = v, this->w = v; }
vec4::vec4(vec2 v) {
  this->x = v.x, this->y = v.y, this->z = 0.0f, this->w = 0.0f;
}
vec4::vec4(vec3 v) {
  this->x = v.x, this->y = v.y, this->z = v.z, this->w = 0.0f;
}

// vec4 ---- Operator Overloading

// [+] Operator
vec4 vec4::operator+(const vec4 v) const {
  vec4 ret;
  ret.p[0] = this->p[0] + v.p[0];
  ret.p[1] = this->p[1] + v.p[1];
  ret.p[2] = this->p[2] + v.p[2];
  return ret;
}

// [-] Operator
vec4 vec4::operator-(const vec4 v) const {
  vec4 ret;
  ret.p[0] = this->p[0] - v.p[0];
  ret.p[1] = this->p[1] - v.p[1];
  ret.p[2] = this->p[2] - v.p[2];
  return ret;
}

// [*] Operator
vec4 vec4::operator*(const vec4 v) const {
  vec4 ret;
  ret.p[0] = this->p[0] * v.p[0];
  ret.p[1] = this->p[1] * v.p[1];
  ret.p[2] = this->p[2] * v.p[2];
  return ret;
}

// [/] Operator
vec4 vec4::operator/(const vec4 v) const {
  vec4 ret;
  ret.p[0] = this->p[0] / v.p[0];
  ret.p[1] = this->p[1] / v.p[1];
  ret.p[2] = this->p[2] / v.p[2];
  return ret;
}

// [+=] Operator
void vec4::operator+=(const vec4 v) {
  this->p[0] += v.p[0];
  this->p[1] += v.p[1];
  this->p[2] += v.p[2];
}

// [-=] Operator
void vec4::operator-=(const vec4 v) {
  this->p[0] -= v.p[0];
  this->p[1] -= v.p[1];
  this->p[2] -= v.p[2];
}

// [*=] Operator
void vec4::operator*=(const vec4 v) {
  this->p[0] *= v.p[0];
  this->p[1] *= v.p[1];
  this->p[2] *= v.p[2];
}

// [/=] Operator
void vec4::operator/=(const vec4 v) {
  this->p[0] /= v.p[0];
  this->p[1] /= v.p[1];
  this->p[2] /= v.p[2];
}

// [=] Operator
void vec4::operator=(const vec4 v) {
  this->p[0] = v.p[0];
  this->p[1] = v.p[1];
  this->p[2] = v.p[2];
}

// [==] Operator
bool vec4::operator==(const vec4 v) const {
  return this->p[0] == v.p[0] && this->p[1] == v.p[1] && this->p[2] == v.p[2];
}

// [!=] Operator
bool vec4::operator!=(const vec4 v) const {
  return this->p[0] != v.p[0] || this->p[1] != v.p[1] || this->p[2] != v.p[2];
}

// vec4 ---- Indexing

// vec2[id] Get Operator
vec1 vec4::operator[](int i) const { return this->p[i % 3]; }

// vec2[id] Set Operator
vec1 &vec4::operator[](int i) { return this->p[i % 3]; }

// vec4 ---- Functions (Instance Methods)

// Length
vec1 vec4::length() { return sqrtf(vec4::dot(*this, *this)); }

// Distance
vec1 vec4::distance(vec4 v) {
  vec4 dist = *this - b;
  return sqrt(dist.x * dist.x + dist.y * dist.y + dist.z * dist.z);
}

// Normalize
vec4 vec4::normalize() { return *this / this->length(); }

// vec4 ---- Functions (Static)

// Dot Product
vec1 vec4::dot(vec4 a, vec4 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

// Linearly Interpolate
vec4 vec4::lerp(vec4 a, vec4 b, vec1 blend) {
  return {a.x + (b.x - a.x) * blend, a.y + (b.y - a.y) * blend,
          a.z + (b.z - a.z) * blend};
}

// ---- MISC

// Get Data
vec1 *vec4::data() { return &x; }