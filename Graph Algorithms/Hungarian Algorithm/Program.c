#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define N 4  // Define the number of tasks and workers

int cost[N][N] = {
    {9, 2, 7, 8},
    {6, 4, 3, 7},
    {5, 8, 1, 8},
    {7, 6, 9, 4}
};

int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to implement the Hungarian Algorithm
void hungarian_algorithm() {
    int u[N], v[N], p[N], way[N], minv[N];
    bool used[N];
    int i, j, k, l, j1, delta;
    
    for (i = 0; i < N; i++) {
        u[i] = v[i] = 0;
        p[i] = way[i] = -1;
    }

    for (i = 0; i < N; i++) {
        p[0] = i;
        j1 = 0;
        for (j = 0; j < N; j++) {
            minv[j] = INT_MAX;
            used[j] = false;
        }

        do {
            used[j1] = true;
            int i0 = p[j1], delta = INT_MAX;
            j1 = -1;

            for (j = 1; j < N; j++) {
                if (!used[j]) {
                    int cur = cost[i0][j] - u[i0] - v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j1;
                    }
                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }

            for (j = 0; j < N; j++) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }

        } while (p[j1] != -1);

        do {
            int j2 = way[j1];
            p[j1] = p[j2];
            j1 = j2;
        } while (j1);
    }

    int result = -v[0];
    printf("Minimum cost: %d\n", result);
    printf("Optimal assignment:\n");
    for (j = 1; j < N; j++) {
        printf("Worker %d assigned to task %d\n", p[j] + 1, j);
    }
}

int main() {
    hungarian_algorithm();
    return 0;
}
