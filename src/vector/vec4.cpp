#include <EngineToolkit/vector/vec4.hpp>

namespace EngineToolkit {

// Constructors

vec4::vec4(vec1 xyzw) {
  // TODO
}
vec4::vec4(vec1 x, vec1 y, vec1 z, vec1 w) {
  // TODO
}

vec4::~vec4() {
  // TODO
}

// Arithmetic Operators

vec4 vec4::operator+(const vec4 &v) const {
  // TODO
}
vec4 vec4::operator-(const vec4 &v) const {
  // TODO
}
vec4 vec4::operator*(const vec4 &v) const {
  // TODO
}
vec4 vec4::operator/(const vec4 &v) const {
  // TODO
}
vec4 vec4::operator%(const vec4 &v) const {
  // TODO
}

// Assignment Operators

void vec4::operator=(const vec4 &v) {
  // TODO
}
void vec4::operator+=(const vec4 &v) {
  // TODO
}
void vec4::operator-=(const vec4 &v) {
  // TODO
}
void vec4::operator*=(const vec4 &v) {
  // TODO
}
void vec4::operator/=(const vec4 &v) {
  // TODO
}
void vec4::operator%=(const vec4 &v) {
  // TODO
}

// Relational Operators

bool vec4::operator==(const vec4 &v) const {
  // TODO
}
bool vec4::operator!=(const vec4 &v) const {
  // TODO
}
bool vec4::operator>(const vec4 &v) const {
  // TODO
}
bool vec4::operator<(const vec4 &v) const {
  // TODO
}
bool vec4::operator>=(const vec4 &v) const {
  // TODO
}
bool vec4::operator<=(const vec4 &v) const {
  // TODO
}

// Other Operators

vec1 vec4::operator[](uint8_t i) const {
  // TODO
}
vec1 &vec4::operator[](uint8_t i) {
  // TODO
}

void vec4::operator++() {
  // TODO
}
void vec4::operator--() {
  // TODO
}

// vec4 vec4::operator->() { return this{ // TODO } }
// const vec4 *vec4::operator->() const { return this{ // TODO } }

// Functions (Instance Methods)

vec1 vec4::length() const {
  // TODO
}
vec4 vec4::normalize() const {
  // TODO
}
vec4 vec4::clamp(vec4 min, vec4 max) const {
  // TODO
}

// Functions (Static)

vec1 vec4::distance(vec4 a, vec4 b) {
  // TODO
}
vec1 vec4::dot(vec4 a, vec4 b) {
  // TODO
}
vec4 vec4::lerp(vec4 a, vec4 b, vec1 blend) {
  // TODO
}

} // namespace EngineToolkit