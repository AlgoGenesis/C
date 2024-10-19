#include <stdio.h>

#define N 3  // Size of the square matrix
#define ROWS 3  // Number of rows
#define COLS 3  // Number of columns

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// In-place transpose for a square matrix
void transposeInPlace(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

// Transpose a matrix recursively
void transposeRecursive(int matrix[N][N], int i, int j) {
    if (i >= N) return;

    // Swap the elements
    if (j < i) {
        int temp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = temp;
    }

    // Recurse for next element
    if (j < N - 1) {
        transposeRecursive(matrix, i, j + 1);
    } else {
        transposeRecursive(matrix, i + 1, 0);
    }
}

// Transpose into a new matrix (works for both square and non-square matrices)
void transposeNewMatrix(int matrix[ROWS][COLS], int result[COLS][ROWS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int matrix[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Original matrix:\n");
    printMatrix(N, N, matrix);  // Fix: Provide rows, cols, and the matrix

    // Approach 1: In-place transpose
    transposeInPlace(matrix);
    printf("\nMatrix after in-place transpose:\n");
    printMatrix(N, N, matrix);

    // Approach 2: Recursive transpose (will swap it back)
    transposeRecursive(matrix, 0, 0);
    printf("\nMatrix after recursive transpose (back to original):\n");
    printMatrix(N, N, matrix);

    // Approach 3: Transpose into a new matrix
    int transposed[COLS][ROWS];  // Result matrix of size [COLS][ROWS]
    transposeNewMatrix(matrix, transposed);
    printf("\nMatrix after transpose into a new matrix:\n");
    printMatrix(COLS, ROWS, transposed);  // Print the new transposed matrix

    return 0;
}
