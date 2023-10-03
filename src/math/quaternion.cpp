#include <EngineToolkit/math/quaternion.hpp>

namespace EngineToolkit {

// Constructors & Destructor

Quaternion::Quaternion() { q = {0, 0, 0, 1}; }

Quaternion::Quaternion(vec1 x, vec1 y, vec1 z, vec1 w) { q = {x, y, z, w}; }

Quaternion::Quaternion(vec3 euler) {
  // TODO: verify
  q.x = sin(euler.z / 2) * cos(euler.y / 2) * cos(euler.x / 2) -
        cos(euler.z / 2) * sin(euler.y / 2) * sin(euler.x / 2);
  q.y = cos(euler.z / 2) * sin(euler.y / 2) * cos(euler.x / 2) +
        sin(euler.z / 2) * cos(euler.y / 2) * sin(euler.x / 2);
  q.z = cos(euler.z / 2) * cos(euler.y / 2) * sin(euler.x / 2) -
        sin(euler.z / 2) * sin(euler.y / 2) * cos(euler.x / 2);
  q.w = cos(euler.z / 2) * cos(euler.y / 2) * cos(euler.x / 2) +
        sin(euler.z / 2) * sin(euler.y / 2) * sin(euler.x / 2);
}

Quaternion::Quaternion(vec4 q) { this->q = q; }

Quaternion::Quaternion(mat3 m) {}

Quaternion::Quaternion(mat4 m) {}

Quaternion::~Quaternion() {}

// Arithmetic Operators

Quaternion Quaternion::operator+(const Quaternion &v) const { return q + v.q; }
Quaternion Quaternion::operator-(const Quaternion &v) const { return q - v.q; }

Quaternion Quaternion::operator*(const Quaternion &v) const {
  // Hamilton Product
  // TODO: verify
  return {q.w * v.q.x + q.x * v.q.w + q.y * v.q.z - q.z * v.q.y,
          q.w * v.q.y - q.x * v.q.z + q.y * v.q.w + q.z * v.q.x,
          q.w * v.q.z + q.x * v.q.y - q.y * v.q.x + q.z * v.q.w,
          q.w * v.q.w - q.x * v.q.x - q.y * v.q.y - q.z * v.q.z};
}

Quaternion Quaternion::operator/(const Quaternion &v) const {
  return *this * v.inverse();
}

// Assignment Operators

void Quaternion::operator=(const Quaternion &v) { this->q = v.q; }
void Quaternion::operator+=(const Quaternion &v) { *this = *this + v; }
void Quaternion::operator-=(const Quaternion &v) { *this = *this - v; }
void Quaternion::operator*=(const Quaternion &v) { *this = *this * v; }
void Quaternion::operator/=(const Quaternion &v) { *this = *this / v; }

// Relational Operators

bool Quaternion::operator==(const Quaternion &v) const { return q == v.q; }

bool Quaternion::operator!=(const Quaternion &v) const { return q != v.q; }

bool Quaternion::operator>(const Quaternion &v) const {}
bool Quaternion::operator<(const Quaternion &v) const {}
bool Quaternion::operator>=(const Quaternion &v) const {}
bool Quaternion::operator<=(const Quaternion &v) const {}

// Other Operators

vec1 Quaternion::operator[](uint8_t i) const { return q[i]; }
vec1 &Quaternion::operator[](uint8_t i) { return q[i]; }

// Functions (Instance Methods)

vec1 Quaternion::length() const { return this->q.length(); }

Quaternion Quaternion::normalize() const { return this->q / this->length(); }

Quaternion Quaternion::conjugate() const {}
Quaternion Quaternion::inverse() const {
  // TODO: verify
  return {(vec4){-q.x, -q.y, -q.z, q.w} / length()};
}

vec3 Quaternion::toVec3() const {
  // TODO: verify
  // vec1 t0, t1, t2, t3, t4;
  // t0 = +2.0 * (this->q.w * this->q.x + this->q.y * this->q.z);
  // t1 = +1.0 - 2.0 * (this->q.x * this->q.x + this->q.y * this->q.y);
  // t2 = +2.0 * (this->q.w * this->q.y - this->q.z * this->q.x);
  // t2 = +1.0 if t2 > +1.0 else t2;
  // t2 = -1.0 if t2 < -1.0 else t2;
  // t3 = +2.0 * (this->q.w * this->q.z + this->q.x * this->q.y);
  // t4 = +1.0 - 2.0 * (this->q.y * this->q.y + this->q.z * this->q.z);
  // return {atan2(t3, t4), asin(t2), atan2(t0, t1)};
  return {};
}

mat3 Quaternion::toMat3() const {}

mat4 Quaternion::toMat4() const {}

// Functions (Static)

Quaternion Quaternion::slerp(Quaternion a, Quaternion b, vec1 blend) {}
Quaternion Quaternion::nlerp(Quaternion a, Quaternion b, vec1 blend) {}

} // namespace EngineToolkit