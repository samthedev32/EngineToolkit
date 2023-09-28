#include <EngineToolkit/vector/vector.hpp>
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
  c->x = 2;
  c->y = 3;

  b = c * 2;

  printf("%f %f\n", b->x, b->y);
}