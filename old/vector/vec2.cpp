#include <EngineToolkit/vector/vec2.hpp>

namespace EngineToolkit {

// ---- Constructors

vec2::vec2(vec1 x, vec1 y) { this->x = x, this->y = y; }
vec2::vec2(vec1 v[2]) { this->x = v[0], this->y = v[1]; }

vec2::vec2(vec1 v) { this->x = v, this->y = v; }

// ---- Destructor

vec2::~vec2() {}

// ---- Operators

vec2 vec2::operator+(const vec2 v) const {
  return {this->x + v.x, this->y + v.y};
}

vec2 vec2::operator-(const vec2 v) const {
  return {this->x - v.x, this->y - v.y};
}

vec2 vec2::operator*(const vec2 v) const {
  return {this->x * v.x, this->y * v.y};
}

vec2 vec2::operator/(const vec2 v) const {
  return {this->x / v.x, this->y / v.y};
}

void vec2::operator+=(const vec2 v) { *this = *this + v; }
void vec2::operator-=(const vec2 v) { *this = *this - v; }
void vec2::operator*=(const vec2 v) { *this = *this * v; }
void vec2::operator/=(const vec2 v) { *this = *this / v; }

void vec2::operator=(const vec2 v) {
  this->x = v.x;
  this->y = v.y;
}

bool vec2::operator==(const vec2 v) const {
  return this->x == v.x && this->y == v.y;
}

bool vec2::operator!=(const vec2 v) const { return !(*this == v); }

// ---- Indexing

vec1 vec2::operator[](int i) const { return this->data[i % 2]; }
vec1 &vec2::operator[](int i) { return this->data[i % 2]; }

// ---- Functions (Instance Methods)

vec1 vec2::length() { return sqrtf(dot(*this, *this)); }

vec2 vec2::normalize() { return *this / this->length(); }

// ---- Functions (Static)

vec1 vec2::distance(vec2 a, vec2 b) { return sqrt(dot(a - b, a - b)); }

vec1 vec2::dot(vec2 a, vec2 b) { return a.x * b.x + a.y * b.y; }

vec2 vec2::lerp(vec2 a, vec2 b, vec1 blend) {
  return {a.x + (b.x - a.x) * blend, a.y + (b.y - a.y) * blend};
}

} // namespace EngineToolkit