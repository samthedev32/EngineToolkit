#pragma once

#include <algorithm>
#include <cstdint>
#include <vector>

#include <EngineToolkit/vector/vector.hpp>

#define MAX(a, b) a < b ? b : a

namespace EngineToolkit {

// Matrix Type
typedef float matT;

// Variable Dimension Matrix
template <uint8_t R, uint8_t C = R> struct mat {
  matT data[R][C];

  // Constructors & Destructor

  mat(matT v = 0);
  mat(std::vector<matT> m);
  template <uint8_t inR, uint8_t inC = inR> mat(mat<inR, inC> m);

  ~mat();

  // Arithmetic Operators

  template <uint8_t inR, uint8_t inC = inR>
  mat<MAX(R, inR), MAX(C, inC)> operator*(mat<inR, inC> m) const;
  template <uint8_t inD> vec<inD> operator*(vec<inD> v) const;

  // TODO

  // Assignment Operators

  template <uint8_t inR, uint8_t inC = inR> void operator=(mat<inR, inC> m);
  template <uint8_t inR, uint8_t inC = inR> void operator*=(mat<inR, inC> m);

  // TODO

  // Relational Operators

  template <uint8_t inR, uint8_t inC = inR>
  bool operator==(mat<inR, inC> m) const;
  template <uint8_t inR, uint8_t inC = inR>
  bool operator!=(mat<inR, inC> m) const;

  // TODO

  // Other Operators

  matT operator()(uint8_t row, uint8_t col) const;
  matT &operator()(uint8_t row, uint8_t col);

  // Functions (Instance Methods)

  void inverse();

  // TODO

  // Functions (Static)

  static mat identity();

  // TODO
};

// Constructors & Destructor

template <uint8_t R, uint8_t C> mat<R, C>::mat(matT v) {
  for (int r = 0; r < R; r++)
    for (int c = 0; c < C; c++)
      this->data[r][c] = v;
}

template <uint8_t R, uint8_t C> mat<R, C>::mat(std::vector<matT> m) {}

template <uint8_t R, uint8_t C>
template <uint8_t inR, uint8_t inC>
mat<R, C>::mat(mat<inR, inC> m) {
  *this = m;
}

template <uint8_t R, uint8_t C> mat<R, C>::~mat() {}

// Arithmetic Operators

template <uint8_t R, uint8_t C>
template <uint8_t inR, uint8_t inC>
mat<MAX(R, inR), MAX(C, inC)> mat<R, C>::operator*(mat<inR, inC> m) const {
  mat<MAX(R, inR), MAX(C, inC)> out;

  // TODO

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

} // namespace EngineToolkit