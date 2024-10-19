#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix
int** allocate_matrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to free a matrix
void free_matrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to input matrix elements
void input_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element at [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to multiply two matrices
void multiply_matrices(int** matrix1, int** matrix2, int** result, int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to print the matrix
void print_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    // Input dimensions for the first matrix
    printf("Enter the number of rows and columns of the first matrix:\n");
    if (scanf("%d %d", &rows1, &cols1) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    // Input dimensions for the second matrix
    printf("Enter the number of rows and columns of the second matrix:\n");
    if (scanf("%d %d", &rows2, &cols2) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    // Check matrix multiplication condition
    if (cols1 != rows2) {
        printf("Error: Column of first matrix must be equal to row of second matrix for multiplication.\n");
        return 1;
    }

    // Allocate memory for matrices and result matrix
    int** matrix1 = allocate_matrix(rows1, cols1);
    int** matrix2 = allocate_matrix(rows2, cols2);
    int** result = allocate_matrix(rows1, cols2);

    // Input matrices
    printf("Enter elements of the first matrix:\n");
    input_matrix(matrix1, rows1, cols1);

    printf("Enter elements of the second matrix:\n");
    input_matrix(matrix2, rows2, cols2);

    // Perform matrix multiplication
    multiply_matrices(matrix1, matrix2, result, rows1, cols1, cols2);

    // Output the result
    printf("Resulting matrix after multiplication:\n");
    print_matrix(result, rows1, cols2);

    // Free allocated memory
    free_matrix(matrix1, rows1);
    free_matrix(matrix2, rows2);
    free_matrix(result, rows1);

    return 0;
}
