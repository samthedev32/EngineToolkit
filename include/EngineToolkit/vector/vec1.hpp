#pragma once

#include <math.h>

namespace EngineToolkit {

// 1D Vector
#ifdef ETK_VECTOR_DOUBLE_PRECISION
typedef double vec1;
#else
typedef float vec1;
#endif

// Radian-Degree Conversion Functions
#define rads(d) (d * M_PI / 180.0f)
#define degs(r) (r * 180.0f / M_PI)

} // namespace EngineToolkit