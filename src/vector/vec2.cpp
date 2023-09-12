#include <vectors/vector/vec2.hpp>

// ---- Constructors

vec2::vec2(vec1 x, vec1 y) { this->x = x, this->y = y; }
vec2::vec2(vec1 v[2]) { this->x = v[0], this->y = v[1]; }

vec2::vec2(vec1 v) { this->x = v, this->y = v; }

// vec2 ---- Operator Overloading

// [+] vec2::operator
vec2 vec2::operator+(const vec2 v) const {
    vec2 ret;
    ret.p[0] = this->p[0] + v.p[0];
    ret.p[1] = this->p[1] + v.p[1];
    return ret;
}

// [-] vec2::operator
vec2 vec2::operator-(const vec2 v) const {
    vec2 ret;
    ret.p[0] = this->p[0] - v.p[0];
    ret.p[1] = this->p[1] - v.p[1];
    return ret;
}

// [*] vec2::operator
vec2 vec2::operator*(const vec2 v) const {
    vec2 ret;
    ret.p[0] = this->p[0] * v.p[0];
    ret.p[1] = this->p[1] * v.p[1];
    return ret;
}

// [/] vec2::operator
vec2 vec2::operator/(const vec2 v) const {
    vec2 ret;
    ret.p[0] = this->p[0] / v.p[0];
    ret.p[1] = this->p[1] / v.p[1];
    return ret;
}

// [+=] vec2::operator
void vec2::operator+=(const vec2 v) {
    this->p[0] += v.p[0];
    this->p[1] += v.p[1];
}

// [-=] vec2::operator
void vec2::operator-=(const vec2 v) {
    this->p[0] -= v.p[0];
    this->p[1] -= v.p[1];
}

// [*=] vec2::operator
void vec2::operator*=(const vec2 v) {
    this->p[0] *= v.p[0];
    this->p[1] *= v.p[1];
}

// [/=] vec2::operator
void vec2::operator/=(const vec2 v) {
    this->p[0] /= v.p[0];
    this->p[1] /= v.p[1];
}

// [=] vec2::operator
void vec2::operator=(const vec2 v) {
    this->p[0] = v.p[0];
    this->p[1] = v.p[1];
}

// [==] vec2::operator
bool vec2::operator==(const vec2 v) const {
    return this->p[0] == v.p[0] && this->p[1] == v.p[1];
}

// [!=] vec2::operator
bool vec2::operator!=(const vec2 v) const {
    return this->p[0] != v.p[0] || this->p[1] != v.p[1];
}

// vec2 ---- Indexing

// vec2[id] Get Operator
vec1 vec2::operator[](int i) const { return this->p[i % 2]; }

// vec2[id] Set Operator
vec1 &vec2::operator[](int i) { return this->p[i % 2]; }

// vec2 ---- Functions (Instance Methods)

// Length
vec1 vec2::length() { return sqrtf(vec2::dot(*this, *this)); }

// Normalize
vec2 vec2::normalize() { return *this / this->length(); }

// vec2 ---- Functions (Static)

// Distance
vec1 vec2::distance(vec2 a, vec2 b) {
    vec2 dist = a - b;
    return sqrt(dist.x * dist.x + dist.y * dist.y);
}

// Dot Product
vec1 vec2::dot(vec2 a, vec2 b) { return a.x * b.x + a.y * b.y; }

// Linearly Interpolate
vec2 vec2::lerp(vec2 a, vec2 b, vec1 blend) {
    return {a.x + (b.x - a.x) * blend, a.y + (b.y - a.y) * blend};
}

// ---- MISC

// Get Data
vec1 *vec2::data() { return &x; }