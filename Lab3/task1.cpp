#include <cstdio>
#include <cmath>

int main() {
    int arr[16];
    for (int i = 0; i < 8; ++i) {
        scanf("%i %i", &arr[i], &arr[8 + i]);
    }

    for (int i = 0; i < 8; ++i) {
        for (int j = i + 1; j < 8; ++j) {
            if (arr[i] == arr[j] || arr[8 + i] == arr[8 + j]) {
                printf("YES\n");
                return 0;
            }
            if (std::abs(arr[i] - arr[j]) == std::abs(arr[8 + i] - arr[8 + j])) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
}
