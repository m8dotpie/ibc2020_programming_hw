#include <cstdio>
#include <algorithm>

const int N = 4;

int main() {
    int distances[N][N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%i", &distances[i][j]);
        }
    }

    int perm[N];
    for (int i = 0; i < N; ++i) {
        perm[i] = i;
    }

    int answer = 1e9 + 7;

    int cnt = 721;
    while (cnt--) {
        int temp = 0;
        for (int i = 0; i < N; ++i) {
            temp += distances[perm[i]][perm[(i + 1) % N]];
        }
        std::next_permutation(perm + 1, perm + N);
        answer = std::min(answer, temp);
    }

    printf("Answer is: %i\n", answer);
}
