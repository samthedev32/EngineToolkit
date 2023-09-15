#include <EngineToolkit/matrix/matrix.hpp>
#include <cstdio>

using namespace EngineToolkit;

int main() {
  mat<4> a;
  mat<3> b = a.to<3>();

  mat<4> c = a * b;
}