#include <EngineToolkit/math/quat.hpp>
#include <cstdio>

using namespace EngineToolkit;

int main(int argc, char *argv[]) {
  quat q(vec<3>(0, 90, 0));

  printf("Quaternion: %f %f %f %f\n", q.x, q.y, q.z, q.w);

  vec<3> e = (q * q).toVec3();

  printf("Euler: %f %f %f\n", e->x, e->y, e->z);

  return 0;
}