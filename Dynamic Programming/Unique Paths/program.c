#include <stdio.h>
#include <stdlib.h>

int uniquePaths(int m, int n) {
    // Create a 2D array to store the number of paths
    int** dp = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        dp[i] = (int*)malloc(n * sizeof(int));
    }

    // Initialize the first row and first column
    for (int i = 0; i < m; i++) dp[i][0] = 1; // Only one way to reach each cell in the first column
    for (int j = 0; j < n; j++) dp[0][j] = 1; // Only one way to reach each cell in the first row

    // Fill the dp array using the recurrence relation
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; // Sum of paths from top and left
        }
    }

    int result = dp[m - 1][n - 1];

    // Free allocated memory
    for (int i = 0; i < m; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    int m = 3, n = 2; // Grid size
    int result = uniquePaths(m, n);
    printf("Number of unique paths: %d\n", result);
    return 0;
}
