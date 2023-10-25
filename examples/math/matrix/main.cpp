#include <EngineToolkit/math/mat.hpp>
#include <cstdio>

using namespace EngineToolkit;

int main() {
    mat<4> a = mat<4>::identity();
    mat<4> b(a);

    printf("Fast:\n");
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++)
            printf("%f ", a(r, c));
        printf("\n");
    }

    printf("Flexible:\n");
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++)
            printf("%f ", b(r, c));
        printf("\n");
    }

    return 0;
}