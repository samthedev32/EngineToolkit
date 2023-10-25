#include <EngineToolkit/math/vec.hpp>
#include <cstdio>

#include <EngineToolkit/math/math.hpp>

using namespace EngineToolkit;

int main() {
  vec<3> a;

  a->x = 2;
  a->y = 7.67;
  a->z = 45.1;

  for (int i = 0; i < 3; i++)
    printf("%.2f ", a[i]);
  printf("\n");
}