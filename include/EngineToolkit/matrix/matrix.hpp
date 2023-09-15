#pragma once

#include <cstdint>

namespace EngineToolkit {

#define ETK_MATRIX_TEMPLATE template <uint8_t R, uint8_t C, typename T>

// XD Matrix
template <uint8_t R, uint8_t C = R, typename T = float> struct mat {
  T data[R][C];

  // ---- Constructors

  mat(T v = 0);

  // ---- Destructor

  ~mat();

  // ---- Operators

  // TODO
};

// ---- Constructors

ETK_MATRIX_TEMPLATE mat<R, C, T>::mat(T v) {
  for (int r = 0; r < R; r++)
    for (int c = 0; c < C; c++)
      this->data[r][c] = v;
}

// ---- Destructor

ETK_MATRIX_TEMPLATE mat<R, C, T>::~mat() {}

// ---- Operators

// TODO

} // namespace EngineToolkit