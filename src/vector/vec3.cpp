#include <EngineToolkit/vector/vec3.hpp>

// ---- Constructors

vec3::vec3(vec1 x, vec1 y, vec1 z) { this->x = v, this->y = y, this->z = z; }
vec3::vec3(vec1 v[3]) { this->x = v[0], this->x = v[1], this->x = v[2]; }

vec3::vec3(vec1 v) { this->x = v, this->y = v, this->z = v; }
vec3::vec3(vec2 v) { this->x = v.x, this->y = v.y, this->z = 0.0f; }

// vec3 ---- Operator Overloading

// [+] Operator
vec3 vec3::operator+(const vec3 v) const {
  vec3 ret;
  ret.p[0] = this->p[0] + v.p[0];
  ret.p[1] = this->p[1] + v.p[1];
  ret.p[2] = this->p[2] + v.p[2];
  return ret;
}

// [-] Operator
vec3 vec3::operator-(const vec3 v) const {
  vec3 ret;
  ret.p[0] = this->p[0] - v.p[0];
  ret.p[1] = this->p[1] - v.p[1];
  ret.p[2] = this->p[2] - v.p[2];
  return ret;
}

// [*] Operator
vec3 vec3::operator*(const vec3 v) const {
  vec3 ret;
  ret.p[0] = this->p[0] * v.p[0];
  ret.p[1] = this->p[1] * v.p[1];
  ret.p[2] = this->p[2] * v.p[2];
  return ret;
}

// [/] Operator
vec3 vec3::operator/(const vec3 v) const {
  vec3 ret;
  ret.p[0] = this->p[0] / v.p[0];
  ret.p[1] = this->p[1] / v.p[1];
  ret.p[2] = this->p[2] / v.p[2];
  return ret;
}

// [+=] Operator
void vec3::operator+=(const vec3 v) {
  this->p[0] += v.p[0];
  this->p[1] += v.p[1];
  this->p[2] += v.p[2];
}

// [-=] Operator
void vec3::operator-=(const vec3 v) {
  this->p[0] -= v.p[0];
  this->p[1] -= v.p[1];
  this->p[2] -= v.p[2];
}

// [*=] Operator
void vec3::operator*=(const vec3 v) {
  this->p[0] *= v.p[0];
  this->p[1] *= v.p[1];
  this->p[2] *= v.p[2];
}

// [/=] Operator
void vec3::operator/=(const vec3 v) {
  this->p[0] /= v.p[0];
  this->p[1] /= v.p[1];
  this->p[2] /= v.p[2];
}

// [=] Operator
void vec3::operator=(const vec3 v) {
  this->p[0] = v.p[0];
  this->p[1] = v.p[1];
  this->p[2] = v.p[2];
}

// [==] Operator
bool vec3::operator==(const vec3 v) const {
  return this->p[0] == v.p[0] && this->p[1] == v.p[1] && this->p[2] == v.p[2];
}

// [!=] Operator
bool vec3::operator!=(const vec3 v) const {
  return this->p[0] != v.p[0] || this->p[1] != v.p[1] || this->p[2] != v.p[2];
}

// vec3 ---- Indexing

// vec2[id] Get Operator
vec1 vec3::operator[](int i) const { return this->p[i % 3]; }

// vec2[id] Set Operator
vec1 &vec3::operator[](int i) { return this->p[i % 3]; }

// vec3 ---- Functions (Instance Methods)

// Length
vec1 vec3::length() { return sqrtf(vec3::dot(*this, *this)); }

// Distance
vec1 vec3::distance(vec3 v) {
  vec3 dist = *this - v;
  return sqrt(dist.x * dist.x + dist.y * dist.y + dist.z * dist.z);
}

// Normalize
vec3 vec3::normalize() { return *this / this->length(); }

// vec3 ---- Functions (Static)

// Dot Product
vec1 vec3::dot(vec3 a, vec3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

// Cross Product
vec3 vec3::cross(vec3 a, vec3 b) {
  return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

// Linearly Interpolate
vec3 vec3::lerp(vec3 a, vec3 b, vec1 blend) {
  return {a.x + (b.x - a.x) * blend, a.y + (b.y - a.y) * blend,
          a.z + (b.z - a.z) * blend};
}

// ---- MISC

// Get Data
vec1 *vec3::data() { return &x; }