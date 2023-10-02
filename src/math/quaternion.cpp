#include <EngineToolkit/math/quaternion.hpp>

namespace EngineToolkit {

vec1 Quaternion::length() const { return this->q.length(); }

Quaternion Quaternion::normalize() const { return {this->q / this->length()}; }

} // namespace EngineToolkit