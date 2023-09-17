#pragma once

#include <cmath>

// Radian-Degree Conversion Functions
#define rads(d) (d * M_PI / 180.0f)
#define degs(r) (r * 180.0f / M_PI)

// Sigmoid Function
#define sig(x) 1.0 / (1.0 + pow(M_E, -x))

namespace EngineToolkit {}; // namespace EngineToolkit