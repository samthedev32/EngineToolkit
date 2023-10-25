#pragma once

#include <EngineToolkit/math/math.hpp>

namespace EngineToolkit {

class Transform {
  vec<3> position;
  quat rotation;

  Transform();
  Transform(const Transform *transform);

  void rotate(quat amount);
  void rotate(vec<3> amount);
  void rotate(float amount, vec<3> scale);

  void translate(vec<3> amount);
  void translate(float amount, vec<3> scale);

  void scale(vec<3> amount);
  void scale(float amount, vec<3> scale);

  // TODO
};

} // namespace EngineToolkit