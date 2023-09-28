#include <EngineToolkit/vector/vec3.hpp>

namespace EngineToolkit {

// Constructors

vec3::vec3(vec1 xyz) {
  // TODO
}
vec3::vec3(vec1 x, vec1 y, vec1 z) {
  // TODO
}

vec3::~vec3() {
  // TODO
}

// Arithmetic Operators

vec3 vec3::operator+(const vec3 &v) const {
  // TODO
}
vec3 vec3::operator-(const vec3 &v) const {
  // TODO
}
vec3 vec3::operator*(const vec3 &v) const {
  // TODO
}
vec3 vec3::operator/(const vec3 &v) const {
  // TODO
}
vec3 vec3::operator%(const vec3 &v) const {
  // TODO
}

// Assignment Operators

void vec3::operator=(const vec3 &v) {
  // TODO
}
void vec3::operator+=(const vec3 &v) {
  // TODO
}
void vec3::operator-=(const vec3 &v) {
  // TODO
}
void vec3::operator*=(const vec3 &v) {
  // TODO
}
void vec3::operator/=(const vec3 &v) {
  // TODO
}
void vec3::operator%=(const vec3 &v) {
  // TODO
}

// Relational Operators

bool vec3::operator==(const vec3 &v) const {
  // TODO
}
bool vec3::operator!=(const vec3 &v) const {
  // TODO
}
bool vec3::operator>(const vec3 &v) const {
  // TODO
}
bool vec3::operator<(const vec3 &v) const {
  // TODO
}
bool vec3::operator>=(const vec3 &v) const {
  // TODO
}
bool vec3::operator<=(const vec3 &v) const {
  // TODO
}

// Other Operators

vec1 vec3::operator[](uint8_t i) const {
  // TODO
}
vec1 &vec3::operator[](uint8_t i) {
  // TODO
}

void vec3::operator++() {
  // TODO
}
void vec3::operator--() {
  // TODO
}

// vec3 vec3*::operator->() { return this{ // TODO } }
// const vec3 vec3*::operator->() const { return this{ // TODO } }

// Functions (Instance Methods)

vec1 vec3::length() const {
  // TODO
}
vec3 vec3::normalize() const {
  // TODO
}
vec3 vec3::clamp(vec3 min, vec3 max) const {
  // TODO
}

// Functions (Static)

vec1 vec3::distance(vec3 a, vec3 b) {
  // TODO
}
vec1 vec3::dot(vec3 a, vec3 b) {
  // TODO
}
vec3 vec3::lerp(vec3 a, vec3 b, vec1 blend) {
  // TODO
}
vec3 vec3::cross(vec3 a, vec3 b) {
  // TODO
}

} // namespace EngineToolkit