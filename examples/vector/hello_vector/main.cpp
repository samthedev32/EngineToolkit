#include <EngineToolkit/core/vector.hpp>
#include <cstdio>

using namespace EngineToolkit;

int main() {
  vec<3> a(0);
  for (int i = 0; i < 3; i++)
    a[i] = (i + 1) * 2;

  vec<2> b = a;
  b += a * b;
  // b += 3.0f;

  printf("%f %f %f %i\n", b[0], b[1], b->x, a > b);
}