#include <EngineToolkit/core/vector.hpp>
#include <cstdio>

#include <EngineToolkit/math/math.hpp>

using namespace EngineToolkit;

int main() {
  vec<3> a(0);
  for (int i = 0; i < 3; i++)
    a[i] = (i + 1) * 2;

  vec<2> b = a;
  b += a * b;
  // b += 3.0f;

  fvec2 c;
  c->x = 5;
  c->y = sig(6);

  b *= c;

  printf("%f %f %lu\n", b->x, b->y, sizeof(b));
}