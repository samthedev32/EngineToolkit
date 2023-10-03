#include <EngineToolkit/math/quaternion/quat.hpp>

#include <EngineToolkit/math/math.hpp>

/**
 * Euler-quat Conversions borrowed from:
 * https://en.wikipedia.org/wiki/Conversion_between_quaternions_and_Euler_angles
 */

namespace EngineToolkit {

// Constructors & Destructor

quat::quat() { this->q = {0, 0, 0, 1}; }

quat::quat(vec1 x, vec1 y, vec1 z, vec1 w) { this->q = {x, y, z, w}; }

quat::quat(vec3 euler) {
  vec1 cr = cosf(rads(euler.x) * 0.5);
  vec1 sr = sinf(rads(euler.x) * 0.5);
  vec1 cp = cosf(rads(euler.y) * 0.5);
  vec1 sp = sinf(rads(euler.y) * 0.5);
  vec1 cy = cosf(rads(euler.z) * 0.5);
  vec1 sy = sinf(rads(euler.z) * 0.5);

  // TODO: fix
  this->q.x = sr * cp * cy - cr * sp * sy;
  this->q.y = cr * sp * cy + sr * cp * sy;
  this->q.z = cr * cp * sy - sr * sp * cy;
  this->q.w = cr * cp * cy + sr * sp * sy;
}

quat::quat(vec4 q) { this->q = q; }

quat::quat(mat3 m) {}

quat::quat(mat4 m) {}

quat::~quat() {}

// Arithmetic Operators

quat quat::operator+(const quat &v) const { return this->q + v.q; }

quat quat::operator-(const quat &v) const { return this->q - v.q; }

quat quat::operator*(const quat &v) const {
  // Hamilton Product
  // TODO: verify
  return {this->q.w * v.q.x + this->q.x * v.q.w + this->q.y * v.q.z -
              this->q.z * v.q.y,
          this->q.w * v.q.y - this->q.x * v.q.z + this->q.y * v.q.w +
              this->q.z * v.q.x,
          this->q.w * v.q.z + this->q.x * v.q.y - this->q.y * v.q.x +
              this->q.z * v.q.w,
          this->q.w * v.q.w - this->q.x * v.q.x - this->q.y * v.q.y -
              this->q.z * v.q.z};
}

quat quat::operator/(const quat &v) const { return *this * v.inverse(); }

// Assignment Operators

void quat::operator=(const quat &v) { this->q = v.q; }
void quat::operator+=(const quat &v) { *this = *this + v; }
void quat::operator-=(const quat &v) { *this = *this - v; }
void quat::operator*=(const quat &v) { *this = *this * v; }
void quat::operator/=(const quat &v) { *this = *this / v; }

// Relational Operators

bool quat::operator==(const quat &v) const { return this->q == v.q; }

bool quat::operator!=(const quat &v) const { return this->q != v.q; }

bool quat::operator>(const quat &v) const {}
bool quat::operator<(const quat &v) const {}
bool quat::operator>=(const quat &v) const {}
bool quat::operator<=(const quat &v) const {}

// Other Operators

vec1 quat::operator[](uint8_t i) const { return this->q[i]; }
vec1 &quat::operator[](uint8_t i) { return this->q[i]; }

// Functions (Instance Methods)

vec1 quat::length() const { return this->q.length(); }

quat quat::normalize() const { return this->q / this->length(); }

quat quat::conjugate() const {}
quat quat::inverse() const {
  // TODO: verify
  return {(vec4){-this->q.x, -this->q.y, -this->q.z, this->q.w} / length()};
}

vec3 quat::toVec3() const {
  vec3 angles;

  // roll (x-axis rotation)
  vec1 sinr_cosp = 2 * (this->q.w * this->q.x + this->q.y * this->q.z);
  vec1 cosr_cosp = 1 - 2 * (this->q.x * this->q.x + this->q.y * this->q.y);
  angles.x = atan2(sinr_cosp, cosr_cosp);

  // pitch (y-axis rotation)
  vec1 sinp = sqrt(1 + 2 * (this->q.w * this->q.y - this->q.x * this->q.z));
  vec1 cosp = sqrt(1 - 2 * (this->q.w * this->q.y - this->q.x * this->q.z));
  angles.y = 2 * atan2(sinp, cosp) - M_PI / 2;

  // yaw (z-axis rotation)
  vec1 siny_cosp = 2 * (this->q.w * this->q.z + this->q.x * this->q.y);
  vec1 cosy_cosp = 1 - 2 * (this->q.y * this->q.y + this->q.z * this->q.z);
  angles.z = atan2(siny_cosp, cosy_cosp);

  return degs(angles);
}

mat3 quat::toMat3() const {}

mat4 quat::toMat4() const {}

// Functions (Static)

quat quat::slerp(quat a, quat b, vec1 blend) {}
quat quat::nlerp(quat a, quat b, vec1 blend) {}

} // namespace EngineToolkit