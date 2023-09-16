#include <EngineToolkit/core/matrix.hpp>
#include <cstdio>

using namespace EngineToolkit;

int main() {
  mat<4> id = mat<4>::perspective(1.0472f, 16.0f / 9, 0.1f, 100.0f);

  for (uint8_t i = 0; i < 4; i++) {
    for (uint8_t j = 0; j < 4; j++)
      printf("%.2f ", id(i, j));
    printf("\n");
  }

  return 0;
}