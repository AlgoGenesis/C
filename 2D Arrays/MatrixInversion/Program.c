#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 1e-9 // Small tolerance for floating-point comparison

// Function to print a matrix of size N x N
void printMatrix(float **matrix, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%8.4f ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to invert a matrix of size N x N
int invertMatrix(float **matrix, float **inverse, int N) {
    float **temp = (float **)malloc(N * sizeof(float *));
    for (int i = 0; i < N; i++) {
        temp[i] = (float *)malloc(N * sizeof(float));
    }

    // Initialize the inverse as the identity matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j)
                inverse[i][j] = 1.0;
            else
                inverse[i][j] = 0.0;
        }
    }

    // Copy the original matrix to a temporary matrix
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            temp[i][j] = matrix[i][j];

    for (int i = 0; i < N; i++) {
        // Make the diagonal contain all 1s
        float diag = temp[i][i];
        if (fabs(diag) < EPSILON) {
            printf("Matrix is singular or close to singular and cannot be inverted.\n");
            return -1; // Failure
        }

        for (int j = 0; j < N; j++) {
            temp[i][j] /= diag;
            inverse[i][j] /= diag;
        }

        // Eliminate column entries
        for (int k = 0; k < N; k++) {
            if (k != i) {
                float factor = temp[k][i];
                for (int j = 0; j < N; j++) {
                    temp[k][j] -= factor * temp[i][j];
                    inverse[k][j] -= factor * inverse[i][j];
                }
            }
        }
    }

    // Free the temporary matrix
    for (int i = 0; i < N; i++) {
        free(temp[i]);
    }
    free(temp);

    return 0; // Success
}

int main() {
    int N;

    // Input the matrix size
    printf("Enter the size of the matrix: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Invalid matrix size.\n");
        return 1;
    }

    // Dynamic memory allocation for matrix and its inverse
    float **matrix = (float **)malloc(N * sizeof(float *));
    float **inverse = (float **)malloc(N * sizeof(float *));
    for (int i = 0; i < N; i++) {
        matrix[i] = (float *)malloc(N * sizeof(float));
        inverse[i] = (float *)malloc(N * sizeof(float));
    }

    // Input the matrix elements
    printf("Enter the elements of the matrix (%d x %d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (scanf("%f", &matrix[i][j]) != 1) {
                printf("Invalid input for matrix element.\n");
                return 1;
            }
        }
    }

    // Print the original matrix
    printf("Original Matrix:\n");
    printMatrix(matrix, N);

    // Invert the matrix
    if (invertMatrix(matrix, inverse, N) == 0) {
        // Print the inverse matrix
        printf("Inverse Matrix:\n");
        printMatrix(inverse, N);
    }

    // Free dynamically allocated memory
    for (int i = 0; i < N; i++) {
        free(matrix[i]);
        free(inverse[i]);
    }
    free(matrix);
    free(inverse);

    return 0;
}
