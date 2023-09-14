#pragma once

#include <EngineToolkit/vector/vec1.hpp>

namespace EngineToolkit {

template <unsigned int cols, unsigned int rows> struct mat {
  vec1 data[cols][rows];
};

} // namespace EngineToolkit