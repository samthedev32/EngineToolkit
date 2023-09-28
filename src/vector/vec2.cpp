#include <EngineToolkit/vector/vec2.hpp>

namespace EngineToolkit {
// Constructors

vec2::vec2(vec1 xy) {
  // TODO
}

vec2::vec2(vec1 x, vec1 y) {
  // TODO
}

vec2::~vec2() {
  // TODO
}

// Arithmetic Operators

vec2 vec2::operator+(const vec2 &v) const {
  // TODO
}
vec2 vec2::operator-(const vec2 &v) const {
  // TODO
}
vec2 vec2::operator*(const vec2 &v) const {
  // TODO
}
vec2 vec2::operator/(const vec2 &v) const {
  // TODO
}
vec2 vec2::operator%(const vec2 &v) const {
  // TODO
}

// Assignment Operators

void vec2::operator=(const vec2 &v) {
  // TODO
}
void vec2::operator+=(const vec2 &v) {
  // TODO
}
void vec2::operator-=(const vec2 &v) {
  // TODO
}
void vec2::operator*=(const vec2 &v) {
  // TODO
}
void vec2::operator/=(const vec2 &v) {
  // TODO
}
void vec2::operator%=(const vec2 &v) {
  // TODO
}

// Relational Operators

bool vec2::operator==(const vec2 &v) const {
  // TODO
}
bool vec2::operator!=(const vec2 &v) const {
  // TODO
}
bool vec2::operator>(const vec2 &v) const {
  // TODO
}
bool vec2::operator<(const vec2 &v) const {
  // TODO
}
bool vec2::operator>=(const vec2 &v) const {
  // TODO
}
bool vec2::operator<=(const vec2 &v) const {
  // TODO
}

// Other Operators

vec1 vec2::operator[](uint8_t i) const {
  // TODO
}
vec1 &vec2::operator[](uint8_t i) {
  // TODO
}

void vec2::operator++() {
  // TODO
}
void vec2::operator--() {
  // TODO
}

// vec2 vec2*::operator->() { return this{ // TODO } }
// const vec2 vec2*::operator->() const { return this{ // TODO } }

// Functions (Instance Methods)

vec1 vec2::length() const {
  // TODO
}
vec2 vec2::normalize() const {
  // TODO
}
vec2 vec2::clamp(vec2 min, vec2 max) const {
  // TODO
}

// Functions (Static)

vec1 vec2::distance(vec2 a, vec2 b) {
  // TODO
}
vec1 vec2::dot(vec2 a, vec2 b) {
  // TODO
}
vec2 vec2::lerp(vec2 a, vec2 b, vec1 blend) {
  // TODO
}

} // namespace EngineToolkit