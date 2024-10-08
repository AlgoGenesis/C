#include <stdio.h>

// Function to return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem using dynamic programming
int knapsack(int W, int weights[], int values[], int n) {
    // Create a 2D array to store the maximum value for each weight limit and item
    int dp[n + 1][W + 1];
    
    // Build table dp[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0; // No items or 0 capacity leads to 0 value
            } else if (weights[i - 1] <= w) {
                // Maximum of either taking the item or not taking it
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w]; // Can't include this item
            }
        }
    }
    
    // Return the maximum value that can be put in the knapsack
    return dp[n][W];
}

int main() {
    // Number of items and knapsack capacity
    int n = 4;
    int W = 7;
    
    // Weights and values of the items
    int weights[] = {1, 3, 4, 5};
    int values[] = {1, 4, 5, 7};
    
    // Call the knapsack function
    int max_value = knapsack(W, weights, values, n);
    
    // Output the result
    printf("Maximum value in the knapsack: %d\n", max_value);
    
    return 0;
}
