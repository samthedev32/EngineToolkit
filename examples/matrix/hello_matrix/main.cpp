#include <EngineToolkit/matrix/matrix.hpp>
#include <cstdio>

using namespace EngineToolkit;

int main() {
  mat<4> a;

  a = mat<4>::identity();

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++)
      printf("%f ", a(i, j));
    printf("\n");
  }
}