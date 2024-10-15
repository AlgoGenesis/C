#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find the minimum cost to send N people to two cities
int twoCitySchedCost(int** costs, int costsSize) {
    int N = costsSize / 2;
    int dp[2 * N + 1][N + 1][N + 1];

    // Initialize the DP table
    for (int i = 0; i <= 2 * N; ++i) {
        for (int j = 0; j <= N; ++j) {
            for (int k = 0; k <= N; ++k) {
                dp[i][j][k] = INT_MAX; // Set to INT_MAX initially
            }
        }
    }
    
    dp[0][0][0] = 0; // No cost if no one is assigned

    for (int i = 1; i <= 2 * N; ++i) {
        for (int wA = 0; wA <= N; ++wA) {
            for (int wB = 0; wB <= N; ++wB) {
                // If sending the current person to city A
                if (wA > 0 && dp[i - 1][wA - 1][wB] != INT_MAX) {
                    dp[i][wA][wB] = fmin(dp[i][wA][wB], costs[i - 1][0] + dp[i - 1][wA - 1][wB]);
                }
                // If sending the current person to city B
                if (wB > 0 && dp[i - 1][wA][wB - 1] != INT_MAX) {
                    dp[i][wA][wB] = fmin(dp[i][wA][wB], costs[i - 1][1] + dp[i - 1][wA][wB - 1]);
                }
            }
        }
    }
    
    return dp[2 * N][N][N];
}

// Helper function to create a 2D array
int** create2DArray(int rows, int cols) {
    int** array = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        array[i] = (int*)malloc(cols * sizeof(int));
    }
    return array;
}

// Free the allocated 2D array
void free2DArray(int** array, int rows) {
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);
}

int main() {
    // Sample input: costs for sending people to cities A and B
    int costsSize = 4; // Total number of people
    int** costs = create2DArray(costsSize, 2);

    costs[0][0] = 10;  costs[0][1] = 20;
    costs[1][0] = 30;  costs[1][1] = 200;
    costs[2][0] = 50;  costs[2][1] = 30;
    costs[3][0] = 200; costs[3][1] = 50;

    int result = twoCitySchedCost(costs, costsSize);
    printf("Minimum cost: %d\n", result); // Expected output: 370

    // Free allocated memory
    free2DArray(costs, costsSize);
    return 0;
}
