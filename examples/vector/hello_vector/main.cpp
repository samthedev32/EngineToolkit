#include <EngineToolkit/vector/vector.hpp>
#include <cstdio>

using namespace EngineToolkit;

int main() {
  vec<3> a;
  for (int i = 0; i < 3; i++)
    a[i] = (i + 1) * 2;

  vec<4> c = a.to<4>();

  for (int i = 0; i < 4; i++)
    printf("%f\n", c[i]);
}