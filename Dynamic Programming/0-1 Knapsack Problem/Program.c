#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int weights[], int values[], int n) {
    int dp[n+1][W+1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i-1] <= w)
                dp[i][w] = max(values[i-1] + dp[i-1][w - weights[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    return dp[n][W];
}

int main() {
    int values[] = {1, 4, 5, 7};
    int weights[] = {1, 3, 4, 5};
    int W = 7;
    int n = sizeof(values) / sizeof(values[0]);

    printf("Maximum value in Knapsack = %d\n", knapsack(W, weights, values, n));
    return 0;
}
