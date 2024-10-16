#include <stdio.h>
#include <limits.h>

// Function to find the maximum falling path sum
int maxFallingPathSum(int** matrix, int n, int m) {
    // Create two arrays to store the current and previous row values
    int prev[m], cur[m];

    // Initialize prev row with the first row of the matrix
    for (int j = 0; j < m; j++) {
        prev[j] = matrix[0][j];
    }

    // Iterate over the rows starting from the second row
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Get the maximum from the three possible previous cells
            int down = prev[j]; // directly above
            int downLeft = (j > 0) ? prev[j - 1] : INT_MIN; // above-left
            int downRight = (j < m - 1) ? prev[j + 1] : INT_MIN; // above-right

            // Calculate the current cell value
            cur[j] = matrix[i][j] + (down > downLeft ? (down > downRight ? down : downRight) : (downLeft > downRight ? downLeft : downRight));
        }

        // Copy current row to previous row for the next iteration
        for (int j = 0; j < m; j++) {
            prev[j] = cur[j];
        }
    }

    // Find the maximum value in the last row
    int maxSum = INT_MIN;
    for (int j = 0; j < m; j++) {
        if (prev[j] > maxSum) {
            maxSum = prev[j];
        }
    }

    return maxSum;
}

int main() {
    // Example input
    int n = 3, m = 3;
    int matrix[3][3] = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    
    // Convert to pointer to array of pointers for function compatibility
    int* matPtrs[3];
    for (int i = 0; i < 3; i++) {
        matPtrs[i] = matrix[i];
    }

    int result = maxFallingPathSum(matPtrs, n, m);
    printf("Maximum Falling Path Sum: %d\n", result);

    return 0;
}
