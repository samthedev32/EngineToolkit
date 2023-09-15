#pragma once

#include <algorithm>
#include <cstdint>
#include <vector>

#include <EngineToolkit/vector/vector.hpp>

namespace EngineToolkit {

#define ETK_MATRIX_TEMPLATE template <uint8_t R, uint8_t C, typename T>

// XD Matrix
template <uint8_t R, uint8_t C = R, typename T = float> struct mat {
  T data[R][C];

  // ---- Constructors

  mat(T v = 0) {
    for (int r = 0; r < R; r++)
      for (int c = 0; c < C; c++)
        this->data[r][c] = v;
  }

  mat(mat const &m) {
    for (int r = 0; r < R; r++)
      for (int c = 0; c < C; c++)
        this->data[r][c] = m.data[r][c];
  }

  // ---- Destructor

  ~mat() {}

  // ---- Operators

  // Set Matrix
  template <uint8_t inR = R, uint8_t inC = inR, typename inT = T>
  void operator=(mat<inR, inC, inT> m) {
    for (int r = 0; r < std::min(R, inR); r++)
      for (int c = 0; c < std::min(C, inC); c++)
        this->data[r][c] = m.data[r][c];
  }

  // Check if 2 Matrices are equal
  template <uint8_t inR = R, uint8_t inC = inR, typename inT = T>
  bool operator==(mat<inR, inC, inT> m) {
    for (int r = 0; r < std::min(R, inR); r++)
      for (int c = 0; c < std::min(C, inC); c++)
        if (this->data[r][c] != m.data[r][c])
          return false;
    return true;
  }

  // Check if 2 Matrices are NOT equal
  template <uint8_t inR = R, uint8_t inC = inR, typename inT = T>
  void operator!=(mat<inR, inC, inT> m) {
    return !(*this == m);
  }

  // Multiply 2 Matrices
  template <uint8_t inR = R, uint8_t inC = inR, typename inT = T>
  mat<std::max(R, inR), std::max(C, inC), inT> operator*(mat<inR, inC, inT> m) {
    mat<std::max(R, inR), std::max(C, inC), inT> out;

    // TODO

    return out;
  }

  // Multiply a Vector by a Matrix
  // TODO: also implement in vector (maybe?)
  // template <uint8_t inD, typename inT = T>
  // vec<inD, inT> operator*(vec<inD, inT> m) {
  //   vec<inD, inT> out;

  //   // TODO

  //   return out;
  // }

  // TODO

  // ---- Functions (Instance Methods)

  // Convert to Different Dimension
  template <uint8_t inR = R, uint8_t inC = inR, typename inT = T>
  mat<inR, inC, inT> to() {
    mat<inR, inC, inT> out;

    for (int r = 0; r < std::min(R, inR); r++)
      for (int c = 0; c < std::min(C, inC); c++)
        out.data[r][c] = this->data[r][c];

    return out;
  }

  // Inverse the Matrix
  void inverse();

  // ---- Functions (Static)

  static mat identity() {
    mat<R, C, T> out;

    // TODO

    return out;
  }
};

} // namespace EngineToolkit