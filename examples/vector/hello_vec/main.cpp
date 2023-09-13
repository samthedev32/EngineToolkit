#include <EngineToolkit/vector/vec.hpp>
#include <cstdio>

using namespace EngineToolkit;

int main() {
  vec<5> v;
  v[0] = 1;
  v[1] = 3;

  printf("%f %f %f\n", v[0], v[1], v[2]);
}