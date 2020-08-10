
#include <cstdio>
#include <cmath>

// Epsilon for comparing floating point numbers.
const float eps = 1e-8;

int main() {
    // 0...N - 1 is x coordinates, N...2N - 1 is y coordinates.
    float vertexes[6];
    for (int i = 0; i < 3; ++i) {
        scanf("%f %f", &vertexes[i], &vertexes[3 + i]);
    }

    // Find the area of give polygon.
    float area =
          (vertexes[0] - vertexes[1]) * (vertexes[3 + 1] - vertexes[3 + 2])
        - (vertexes[1] - vertexes[2]) * (vertexes[3 + 0] - vertexes[3 + 1]);
    area = abs(area) / 2;

    // If area is near zero, then polygon does not exist.
    if (area <= eps) {
        printf("Triangle does not exist");
    } else {
        printf("%f", area);
    }
}
