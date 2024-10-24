#include <stdio.h>

#define MAX_SIZE 100

// Function to find the maximum sum path in a triangle
int maximumSumPath(int triangle[MAX_SIZE][MAX_SIZE], int n) {
    // Start from the second last row and move upwards
    for (int row = n - 2; row >= 0; row--) {
        for (int col = 0; col <= row; col++) {
            // Update the current cell with the maximum sum path
            triangle[row][col] += (triangle[row + 1][col] > triangle[row + 1][col + 1]) ?
                                  triangle[row + 1][col] : triangle[row + 1][col + 1];
        }
    }
    // The top element now contains the maximum sum path
    return triangle[0][0];
}

int main() {
    int triangle[MAX_SIZE][MAX_SIZE];
    int n;

    // Input the number of rows in the triangle
    printf("Enter the number of rows in the triangle: ");
    scanf("%d", &n);

    // Input the triangle values
    printf("Enter the triangle values:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &triangle[i][j]);
        }
    }

    // Calculate the maximum sum path
    int maxSum = maximumSumPath(triangle, n);
    printf("The maximum sum path is: %d\n", maxSum);

    return 0;
}