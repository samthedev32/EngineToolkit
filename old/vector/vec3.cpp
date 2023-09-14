#include <EngineToolkit/vector/vec3.hpp>

namespace EngineToolkit {

// ---- Constructors

vec3::vec3(vec1 x, vec1 y, vec1 z) { this->x = v, this->y = y, this->z = z; }
vec3::vec3(vec1 v[3]) { this->x = v[0], this->x = v[1], this->x = v[2]; }

vec3::vec3(vec1 v) { this->x = v, this->y = v, this->z = v; }
vec3::vec3(vec2 v) { this->x = v.x, this->y = v.y, this->z = 0.0f; }

// ---- Destructor

vec3::~vec3() {}

// ---- Operators

vec3 vec3::operator+(const vec3 v) const {
  return {this->x + v.x, this->y + v.y, this->z + v.z};
}

vec3 vec3::operator-(const vec3 v) const {
  return {this->x - v.x, this->y - v.y, this->z - v.z};
}

vec3 vec3::operator*(const vec3 v) const {
  return {this->x * v.x, this->y * v.y, this->z * v.z};
}

vec3 vec3::operator/(const vec3 v) const {
  return {this->x / v.x, this->y / v.y, this->z / v.z};
}

void vec3::operator+=(const vec3 v) { *this = *this + v; }
void vec3::operator-=(const vec3 v) { *this = *this - v; }
void vec3::operator*=(const vec3 v) { *this = *this * v; }
void vec3::operator/=(const vec3 v) { *this = *this / v; }

void vec3::operator=(const vec3 v) {
  this->x = v.x;
  this->y = v.y;
  this->z = v.z;
}

bool vec3::operator==(const vec3 v) const {
  return this->x == v.x && this->y == v.y && this->z == v.z;
}

bool vec3::operator!=(const vec3 v) const { return !(*this == v); }

// ---- Indexing

vec1 vec3::operator[](int i) const { return this->data[i % 3]; }
vec1 &vec3::operator[](int i) { return this->data[i % 3]; }

// ---- Functions (Instance Methods)

vec1 vec3::length() { return sqrtf(dot(*this, *this)); }

vec3 vec3::normalize() { return *this / this->length(); }

// ---- Functions (Static)

vec1 vec3::distance(vec3 a, vec3 b) { return sqrt(dot(a - b, a - b)); }

vec1 vec3::dot(vec3 a, vec3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

vec3 vec3::cross(vec3 a, vec3 b) {
  return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

vec3 vec3::lerp(vec3 a, vec3 b, vec1 blend) {
  return {a.x + (b.x - a.x) * blend, a.y + (b.y - a.y) * blend,
          a.z + (b.z - a.z) * blend};
}

} // namespace EngineToolkit