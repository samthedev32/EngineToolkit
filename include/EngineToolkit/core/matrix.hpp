#pragma once

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <vector>

#include "vector.hpp"

namespace EngineToolkit {

// Matrix Type
typedef float matT;

// Variable Dimension Matrix
template <uint8_t R, uint8_t C = R> struct mat {
    matT data[R][C];

    // Constructors & Destructor

    mat(matT v = 0);
    mat(std::vector<std::vector<matT>> m);
    template <uint8_t inR, uint8_t inC = inR> mat(mat<inR, inC> m);

    ~mat();

    // Arithmetic Operators

    mat<R, C> operator+(mat<R, C> m) const;
    mat<R, C> operator-(mat<R, C> m) const;
    // matrix division is not a standard operation; TODO
    template <uint8_t inR, uint8_t inC = inR>
    mat<MAX(R, inR), MAX(C, inC)> operator*(mat<inR, inC> m) const;

    template <uint8_t inD> vec<inD> operator*(vec<inD> v) const;

    // Assignment Operators

    template <uint8_t inR, uint8_t inC = inR> void operator=(mat<inR, inC> m);
    template <uint8_t inR, uint8_t inC = inR> void operator*=(mat<inR, inC> m);

    // Relational Operators

    template <uint8_t inR, uint8_t inC = inR>
    bool operator==(mat<inR, inC> m) const;
    template <uint8_t inR, uint8_t inC = inR>
    bool operator!=(mat<inR, inC> m) const;

    // Other Operators

    matT operator()(uint8_t row, uint8_t col) const;
    matT &operator()(uint8_t row, uint8_t col);

    // Functions (Instance Methods)

    bool isSquare() const;
    void inverse();
    matT sum() const;

    // Functions (Static)

    static mat<R> identity();

    static mat rotationX(float rad);
    static mat rotationY(float rad);
    static mat rotationZ(float rad);
    static mat rotation(vec<3> rad);

    static mat translation(vec<3> v);
    static mat scale(vec<3> v);

    // Functions (Dimension-Specific)

    static mat<4> perspective(float fovrads, float aspect, float near,
                              float far);

    static mat<4> ortho(float left, float right, float bottom, float top,
                        float fnear, float ffar);

    static mat<4> lookat(vec<3> pos, vec<3> target,
                         vec<3> up = {0.0f, 1.0f, 0.0f});
};

// Constructors & Destructor

template <uint8_t R, uint8_t C> mat<R, C>::mat(matT v) {
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            this->data[r][c] = v;
}

template <uint8_t R, uint8_t C>
mat<R, C>::mat(std::vector<std::vector<matT>> m) {
    for (uint8_t r = 0; r < R; r++)
        for (uint8_t c = 0; c < C; c++)
            this->data[r][c] = r < m.size() && c < m[r].size() ? m[r][c] : 0;
}

template <uint8_t R, uint8_t C>
template <uint8_t inR, uint8_t inC>
mat<R, C>::mat(mat<inR, inC> m) {
    *this = m;
}

template <uint8_t R, uint8_t C> mat<R, C>::~mat() {}

// Arithmetic Operators

template <uint8_t R, uint8_t C>
mat<R, C> mat<R, C>::operator+(mat<R, C> m) const {
    mat<R, C> out;

    for (uint8_t r = 0; r < R; r++)
        for (uint8_t c = 0; c < C; c++)
            out.data[r][c] = this->data[r][c] + m.data[r][c];

    return out;
}

template <uint8_t R, uint8_t C>
mat<R, C> mat<R, C>::operator-(mat<R, C> m) const {
    mat<R, C> out;

    for (uint8_t r = 0; r < R; r++)
        for (uint8_t c = 0; c < C; c++)
            out.data[r][c] = this->data[r][c] - m.data[r][c];

    return out;
}

template <uint8_t R, uint8_t C>
template <uint8_t inR, uint8_t inC>
mat<MAX(R, inR), MAX(C, inC)> mat<R, C>::operator*(mat<inR, inC> m) const {
    mat<MAX(R, inR), MAX(C, inC)> out;

    if (C != inR)
        return out;

    for (uint8_t r = 0; r < MAX(R, inR); r++)
        for (uint8_t c = 0; c < MAX(C, inC); c++)
            for (uint8_t k = 0; k < C; k++)
                out.data[r][c] += this->data[r][k] * m.data[k][c];

    // TODO: bugfix

    return out;
}

template <uint8_t R, uint8_t C>
template <uint8_t inD>
vec<inD> mat<R, C>::operator*(vec<inD> v) const {
    vec<inD> out;

    // TODO

    return out;
}

// Assignment Operators

template <uint8_t R, uint8_t C>
template <uint8_t inR, uint8_t inC>
void mat<R, C>::operator=(mat<inR, inC> m) {
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            this->data[r][c] = r < inR && c < inC ? m.data[r][c] : 0;
}

template <uint8_t R, uint8_t C>
template <uint8_t inR, uint8_t inC>
void mat<R, C>::operator*=(mat<inR, inC> m) {
    *this = *this * m;
}

// Relational Operators

template <uint8_t R, uint8_t C>
template <uint8_t inR, uint8_t inC>
bool mat<R, C>::operator==(mat<inR, inC> m) const {
    for (int r = 0; r < std::min(R, inR); r++)
        for (int c = 0; c < std::min(C, inC); c++)
            if (this->data[r][c] != m.data[r][c])
                return false;
    return true;
}

template <uint8_t R, uint8_t C>
template <uint8_t inR, uint8_t inC>
bool mat<R, C>::operator!=(mat<inR, inC> m) const {
    for (int r = 0; r < std::min(R, inR); r++)
        for (int c = 0; c < std::min(C, inC); c++)
            if (this->data[r][c] == m.data[r][c])
                return false;
    return true;
}

// Other Operators

template <uint8_t R, uint8_t C>
matT mat<R, C>::operator()(uint8_t row, uint8_t col) const {
    return this->data[row % R][col % C];
}

template <uint8_t R, uint8_t C>
matT &mat<R, C>::operator()(uint8_t row, uint8_t col) {
    return this->data[row % R][col % C];
}

// Functions (Instance Methods)

template <uint8_t R, uint8_t C> bool mat<R, C>::isSquare() const {
    return R == C;
}

void inverse();

matT sum();

// Functions (Static)

template <uint8_t R, uint8_t C> mat<R, R> mat<R, C>::identity() {
    mat<R> out;

    for (uint8_t rc = 0; rc < R; rc++)
        out.data[rc][rc] = 1;

    return out;
}

// Functions (Dimension-Specific)

template <uint8_t R, uint8_t C>
mat<4> mat<R, C>::perspective(float fovrads, float aspect, float near,
                              float far) {
    float tanHalfFov = tan(fovrads / 2.0f);

    mat<4> out;
    out.data[0][0] = 1.0f / (aspect * tanHalfFov);
    out.data[1][1] = 1.0f / (tanHalfFov);
    out.data[2][2] = -(far + near) / (far - near);
    out.data[2][3] = -1.0f;
    out.data[3][2] = -(2.0f * far * near) / (far - near);
    return out;
}

template <uint8_t R, uint8_t C>
mat<4> mat<R, C>::ortho(float left, float right, float bottom, float top,
                        float near, float far) {
    mat<4> out = identity();
    out.data[0][0] = 2.0f / (right - left);
    out.data[1][1] = 2.0f / (top - bottom);
    out.data[2][2] = -2.0f / (far - near);
    out.data[3][0] = -(right + left) / (right - left);
    out.data[3][1] = -(top + bottom) / (top - bottom);
    out.data[3][2] = -(far + near) / (far - near);
    return out;
}

template <uint8_t R, uint8_t C>
mat<4> mat<R, C>::lookat(vec<3> pos, vec<3> target, vec<3> up) {
    vec<3> f = (target - pos).normalize();
    vec<3> s = vec<3>::cross(f, up).normalize();
    vec<3> u = vec<3>::cross(s, f);

    mat<4> out = identity();
    out.data[0][0] = s[0];
    out.data[1][0] = s[1];
    out.data[2][0] = s[2];
    out.data[0][1] = u[0];
    out.data[1][1] = u[1];
    out.data[2][1] = u[2];
    out.data[0][2] = -f[0];
    out.data[1][2] = -f[1];
    out.data[2][2] = -f[2];
    out.data[3][0] = -vec<3>::dot(s, pos);
    out.data[3][1] = -vec<3>::dot(u, pos);
    out.data[3][2] = vec<3>::dot(f, pos);
    return out;
}

} // namespace EngineToolkit