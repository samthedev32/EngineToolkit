#include <EngineToolkit/math/math.hpp>

/**
 * Euler-quat Conversions borrowed from:
 * https://en.wikipedia.org/wiki/Conversion_between_quaternions_and_Euler_angles
 */

namespace EngineToolkit {

// Constructors & Destructor

quat::quat() { this->q = {0, 0, 0, 1}; }

quat::quat(float x, float y, float z, float w) { this->q = {x, y, z, w}; }

quat::quat(vec<3> euler) {
  float cr = cosf(rads(euler->x) * 0.5);
  float sr = sinf(rads(euler->x) * 0.5);
  float cp = cosf(rads(euler->y) * 0.5);
  float sp = sinf(rads(euler->y) * 0.5);
  float cy = cosf(rads(euler->z) * 0.5);
  float sy = sinf(rads(euler->z) * 0.5);

  // TODO: fix
  this->q->x = sr * cp * cy - cr * sp * sy;
  this->q->y = cr * sp * cy + sr * cp * sy;
  this->q->z = cr * cp * sy - sr * sp * cy;
  this->w = cr * cp * cy + sr * sp * sy;
}

quat::quat(vec<4> q) { this->q = q; }

quat::quat(mat<3> m) {}

quat::quat(mat<4> m) {}

quat::~quat() {}

// Arithmetic Operators

quat quat::operator+(const quat &v) const { return this->q + v.q; }

quat quat::operator-(const quat &v) const { return this->q - v.q; }

quat quat::operator*(const quat &v) const {
  // Hamilton Product
  // TODO: fix
  return {this->w * v.x + this->x * v.w + this->y * v.z - this->q->z * v.y,
          this->w * v.q->y + this->q->y * v.w + this->z * v.q->x -
              this->q->x * v.q->z,
          this->w * v.q->z + this->q->z * v.w + this->q->x * v.q->y -
              this->q->y * v.q->x,
          this->w * v.w - this->q->x * v.q->x - this->q->y * v.q->y -
              this->q->z * v.q->z};
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

float quat::operator[](uint8_t i) const { return this->q[i]; }
float &quat::operator[](uint8_t i) { return this->q[i]; }

// Functions (Instance Methods)

float quat::length() const { return this->q.length(); }

quat quat::normalize() const { return this->q / this->length(); }

quat quat::conjugate() const {}
quat quat::inverse() const {
  // TODO: verify
  return {(vec<4>){-this->x, -this->y, -this->z, this->w} / length()};
}

vec<3> quat::toVec3() const {
  vec<3> angles;

  // roll (x-axis rotation)
  float sinr_cosp = 2 * (this->w * this->x + this->y * this->z);
  float cosr_cosp = 1 - 2 * (this->x * this->x + this->y * this->y);
  angles->x = atan2(sinr_cosp, cosr_cosp);

  // pitch (y-axis rotation)
  float sinp = sqrt(1 + 2 * (this->w * this->y - this->x * this->z));
  float cosp = sqrt(1 - 2 * (this->w * this->y - this->x * this->z));
  angles->y = 2 * atan2(sinp, cosp) - M_PI / 2;

  // yaw (z-axis rotation)
  float siny_cosp = 2 * (this->w * this->z + this->x * this->y);
  float cosy_cosp = 1 - 2 * (this->y * this->y + this->z * this->z);
  angles->z = atan2(siny_cosp, cosy_cosp);

  return degs(angles);
}

// Functions (Static)

quat quat::slerp(quat a, quat b, float blend) {}
quat quat::nlerp(quat a, quat b, float blend) {}

} // namespace EngineToolkit