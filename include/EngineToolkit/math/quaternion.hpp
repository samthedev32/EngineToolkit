#pragma once

#include <EngineToolkit/math/vector/vec4.hpp>

namespace EngineToolkit {

struct Quaternion {
  vec4 q;

  vec1 length() const;

  Quaternion normalize() const;
};

} // namespace EngineToolkit