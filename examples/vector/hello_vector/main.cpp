#include <EngineToolkit/vector/vector.hpp>
#include <cstdio>

#include <EngineToolkit/math/math.hpp>

using namespace EngineToolkit;

int main() {
  vec3 a;

  a.x = 2;
  a.y = 7.67;
  a.z = 45.1;
  vec<3> b(a);

  printf("Fast:     ");
  for (int i = 0; i < 3; i++)
    printf("%.2f ", a[i]);

  printf("\nFlexible: ");
  for (int i = 0; i < 3; i++)
    printf("%.2f ", b[i]);
  printf("\n");
}