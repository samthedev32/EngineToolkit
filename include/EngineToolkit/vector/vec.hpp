#pragma once

#include <EngineToolkit/vector/vec1.hpp>

namespace EngineToolkit {

// XD Vector (X Dimension Vector)
// This is not meant to be used, only for fun/experimental purposes
template <unsigned int dimensions> struct vec {
  vec1 data[dimensions];

  // ---- Constructors

  vec(vec1 v[dimensions] = {});
  vec(vec const &v);

  // ---- Operator Overloading

  vec operator+(const vec v) const;
  vec operator-(const vec v) const;
  vec operator*(const vec v) const;
  vec operator/(const vec v) const;

  void operator+=(const vec v);
  void operator-=(const vec v);
  void operator*=(const vec v);
  void operator/=(const vec v);

  void operator=(const vec v);
  bool operator==(const vec v) const;
  bool operator!=(const vec v) const;

  vec1 operator[](int i) const;
  vec1 &operator[](int i);

  // ---- Functions (Instance Methods)

  // Length
  vec1 length();

  // Distance
  vec1 distance(vec v);

  // Normalize
  vec normalize();

  // ---- Functions (Static)

  // Dot Product
  static vec1 dot(vec a, vec b);

  // Linearly Interpolate
  static vec lerp(vec a, vec b, vec1 blend);
};

} // namespace EngineToolkit