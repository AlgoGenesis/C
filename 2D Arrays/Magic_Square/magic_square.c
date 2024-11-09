#include <stdio.h>
#include <stdbool.h>

bool isMagicSquare(int matrix[][10], int n) {
    int sumDiag1 = 0, sumDiag2 = 0;

    // Calculate the sum of the primary diagonal
    for (int i = 0; i < n; i++) {
        sumDiag1 += matrix[i][i];
    }

    // Calculate the sum of the secondary diagonal
    for (int i = 0; i < n; i++) {
        sumDiag2 += matrix[i][n - i - 1];
    }

    // If the diagonal sums do not match, it is not a magic square
    if (sumDiag1 != sumDiag2) {
        return false;
    }

    // Compare row sums and column sums to the diagonal sum
    for (int i = 0; i < n; i++) {
        int sumRow = 0, sumCol = 0;

        for (int j = 0; j < n; j++) {
            sumRow += matrix[i][j];     // Row Sum
            sumCol += matrix[j][i];     // Column Sum
        }

        if (sumRow != sumDiag1 || sumCol != sumDiag1) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;

    printf("Enter the size(between 1 and 10) of the matrix (n x n): ");
    scanf("%d", &n);

    if (n <= 0 || n > 10) {
        printf("Invalid size! Please enter a size between 1 and 10.\n");
        return 1;
    }

    int matrix[10][10];

    // Input array elements from user
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Print the matrix
    printf("The elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    if (isMagicSquare(matrix, n)) {
        printf("The matrix is a magic square.\n");
    } else {
        printf("The matrix is NOT a magic square.\n");
    }

    return 0;
}
