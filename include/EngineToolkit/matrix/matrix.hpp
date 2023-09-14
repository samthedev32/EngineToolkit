#pragma once

namespace EngineToolkit {

template <unsigned int R, unsigned int C, typename T = float> struct mat {
  T data[R][C];
};

} // namespace EngineToolkit