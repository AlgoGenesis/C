#include <stdio.h>

void generateSpiralMatrix(int n) {
    int matrix[n][n];

    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int value = 1;

    while (top <= bottom && left <= right) {
        // Fill the top row
        for (int i = left; i <= right; i++) {
            matrix[top][i] = value++;
        }
        top++;

        // Fill the right column
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = value++;
        }
        right--;

        // Fill the bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = value++;
            }
            bottom--;
        }

        // Fill the left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = value++;
            }
            left++;
        }
    }

    // Print the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    generateSpiralMatrix(n);

    return 0;
}
