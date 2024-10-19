#include <stdio.h>

void transpose(int matrix[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Swap matrix[i][j] with matrix[j][i]
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

void reverse_rows(int matrix[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            // Swap elements in the row to reverse
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - 1 - j];
            matrix[i][n - 1 - j] = temp;
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the square matrix (n x n): ");
    scanf("%d", &n);

    int matrix[100][100]; // We assume max size as 100x100 for simplicity

    // Input the matrix elements
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Perform matrix transpose
    transpose(matrix, n);

    // Reverse each row to complete the 90-degree rotation
    reverse_rows(matrix, n);

    // Output the rotated matrix
    printf("Rotated Matrix (90 degrees clockwise):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
