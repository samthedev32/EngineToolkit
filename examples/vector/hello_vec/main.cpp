#include <EngineToolkit/vector/vector.hpp>
#include <cstdio>

using namespace EngineToolkit;

int main() {
  vec2 v;

  v += vec2(1, 2);

  printf("%f %f %f\n", v[0], v[1], v[2]);
}