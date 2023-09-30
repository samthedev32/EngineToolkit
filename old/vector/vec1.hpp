#pragma once

#include <math.h>

namespace EngineToolkit {

// 1D Vector
typedef float vec1;

// Radian-Degree Conversion Functions
#define rads(d) (d * M_PI / 180.0f)
#define degs(r) (r * 180.0f / M_PI)
// TODO: move from here

} // namespace EngineToolkit