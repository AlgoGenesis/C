#include <stdio.h>

// Function to count the number of ways to reach the bottom-right cell (m-1, n-1) 
// from the top-left cell (0, 0) in a grid of size m x n
int countWays(int m, int n) {
    
    // Create a 2D array to store the number of ways to reach each cell
    int dp[m][n];

    // Initialize the first cell
    dp[0][0] = 1;

    // Fill the first row and first column
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue; // Skip the first cell
            dp[i][j] = 0;
            if (i > 0) dp[i][j] += dp[i - 1][j]; // From above
            if (j > 0) dp[i][j] += dp[i][j - 1]; // From left
        }
    }

    // Return the number of ways to reach the bottom-right cell
    return dp[m - 1][n - 1];
}

int main() {
    int m = 3;
    int n = 2;

    // Call the countWays function and print the result
    printf("Number of ways to reach (%d, %d): %d\n", m - 1, n - 1, countWays(m, n));

    return 0;
}

