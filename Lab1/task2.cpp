
#include <cstdio>
#include <cmath>

// Number of vertexes
const int vsN = 4;
const float eps = 1e-8;

// vs parameter stands for distance between x and corresponding y in array.
float areaOfTriangle(float *coords, int vs = 3) {
    
    // We do not care if triangle exists or not, zero area is good as well.
    float area = 
          (coords[0] - coords[1]) * (coords[vs + 1] - coords[vs + 2])
        - (coords[1] - coords[2]) * (coords[vs + 0] - coords[vs + 1]);
    area = abs(area) / 2;

    return area;
}

int main() {
    float coords[8];
    for (int i = 0; i < vsN; ++i) {
        scanf("%f %f", &coords[i], &coords[vsN + i]);
    }

    // Parallelogram area equals two triangles.
    float paraArea = areaOfTriangle(coords, 4) * 2;

    // Read point from input
    float x0, y0;
    scanf("%f %f", &x0, &y0);

    // If sum of 4 triangles equals paraArea, then it is inside
    float sumArea = 0;
    for (int i = 0; i < vsN; ++i) {
        float temp[] = {
            coords[i], coords[(i + 1) % vsN], x0,
            coords[vsN + i], coords[vsN + (i + 1) % vsN], y0
        };
        sumArea += areaOfTriangle(temp);
    }

    if (abs(sumArea - paraArea) <= eps) {
        printf("Inside\n");
    } else {
        printf("Outside\n");
    }
}
