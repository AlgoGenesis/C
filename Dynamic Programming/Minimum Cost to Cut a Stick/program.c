#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Comparison function for qsort (used to sort the cuts array)
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int minCost(int n, int* cuts, int cutsSize) {
    int* c = (int*)malloc((cutsSize + 2) * sizeof(int));
    for (int i = 0; i < cutsSize; i++) {
        c[i + 1] = cuts[i];
    }
    c[0] = 0;
    c[cutsSize + 1] = n;
    qsort(c, cutsSize + 2, sizeof(int), compare);

    int dp[cutsSize + 2][cutsSize + 2];
    for (int i = 0; i < cutsSize + 2; i++) {
        for (int j = 0; j < cutsSize + 2; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 2; i < cutsSize + 2; i++) {
        for (int j = i - 2; j >= 0; j--) {
            dp[j][i] = INT_MAX;
            for (int k = j + 1; k < i; k++) {
                int cost = c[i] - c[j] + dp[j][k] + dp[k][i];
                if (cost < dp[j][i]) {
                    dp[j][i] = cost;
                }
            }
        }
    }

    int result = dp[0][cutsSize + 1];
    free(c);
    return result;
}

int main() {
    int cuts[] = {1, 3, 4, 5};
    int n = 7;
    int cutsSize = sizeof(cuts) / sizeof(cuts[0]);
    int result = minCost(n, cuts, cutsSize);
    printf("Minimum cost to cut the stick is %d\n", result);
    return 0;
}
