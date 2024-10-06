#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the Knapsack problem using dynamic programming
int knapsack(int W, int weights[], int values[], int n) {
    // Create a 2D array to store the maximum values for each subproblem
    int dp[n + 1][W + 1];

    // Initialize the first row and column to 0
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int w = 0; w <= W; w++) {
        dp[0][w] = 0;
    }

    // Fill the dp array using dynamic programming
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Return the maximum value in the Knapsack
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