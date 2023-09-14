#include <EngineToolkit/vector/vec4.hpp>

namespace EngineToolkit {

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

// ---- Destructor

vec4::~vec4() { *this = 0.0f; }

// ---- Operators

vec4 vec4::operator+(const vec4 v) const {
  return {this->x + v.x, this->y + v.y, this->z + v.z, this->w + v.w};
}

vec4 vec4::operator-(const vec4 v) const {
  return {this->x - v.x, this->y - v.y, this->z - v.z, this->w - v.w};
}

vec4 vec4::operator*(const vec4 v) const {
  return {this->x * v.x, this->y * v.y, this->z * v.z, this->w * v.w};
}

vec4 vec4::operator/(const vec4 v) const {
  return {this->x / v.x, this->y / v.y, this->z / v.z, this->w / v.w};
}

void vec4::operator+=(const vec4 v) { *this = *this + v; }
void vec4::operator-=(const vec4 v) { *this = *this - v; }
void vec4::operator*=(const vec4 v) { *this = *this * v; }
void vec4::operator/=(const vec4 v) { *this = *this / v; }

void vec4::operator=(const vec4 v) {
  this->x = v.x;
  this->y = v.y;
  this->z = v.z;
  this->w = v.w;
}

bool vec4::operator==(const vec4 v) const {
  return this->x == v.x && this->y == v.y && this->z == v.z && this->w == v.w;
}

bool vec4::operator!=(const vec4 v) const { return !(*this == v); }

// ---- Indexing

vec1 vec4::operator[](int i) const { return this->data[i % 4]; }
vec1 &vec4::operator[](int i) { return this->data[i % 4]; }

// ---- Functions (Instance Methods)

vec1 vec4::length() { return sqrtf(dot(*this, *this)); }

vec4 vec4::normalize() { return *this / this->length(); }

// ---- Functions (Static)

vec1 vec4::distance(vec4 a, vec4 b) { return sqrt(dot(a - b, a - b)); }

vec1 vec4::dot(vec4 a, vec4 b) {
  return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

vec4 vec4::lerp(vec4 a, vec4 b, vec1 blend) {
  return {a.x + (b.x - a.x) * blend, a.y + (b.y - a.y) * blend,
          a.z + (b.z - a.z) * blend, a.w + (b.w - a.w) * blend};
}

} // namespace EngineToolkit