#include <stdio.h>
#include <stdlib.h>

#define SIZE 3 // Change this for different sizes

void printMatrix(float matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%8.4f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int invertMatrix(float matrix[SIZE][SIZE], float inverse[SIZE][SIZE]) {
    float temp[SIZE][SIZE];
    
    // Initialize inverse as the identity matrix
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == j)
                inverse[i][j] = 1.0;
            else
                inverse[i][j] = 0.0;
        }
    }

    // Copy the original matrix to a temporary matrix
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            temp[i][j] = matrix[i][j];

    for (int i = 0; i < SIZE; i++) {
        // Make the diagonal contain all 1s
        float diag = temp[i][i];
        if (diag == 0) {
            printf("Matrix is singular and cannot be inverted.\n");
            return -1; // Failure
        }
        for (int j = 0; j < SIZE; j++) {
            temp[i][j] /= diag;
            inverse[i][j] /= diag;
        }

        // Eliminate column entries
        for (int k = 0; k < SIZE; k++) {
            if (k != i) {
                float factor = temp[k][i];
                for (int j = 0; j < SIZE; j++) {
                    temp[k][j] -= factor * temp[i][j];
                    inverse[k][j] -= factor * inverse[i][j];
                }
            }
        }
    }
    return 0; // Success
}

int main() {
    float matrix[SIZE][SIZE] = {
        {4, 7, 2},
        {3, 5, 1},
        {2, 4, 1}
    };

    float inverse[SIZE][SIZE];

    printf("Original Matrix:\n");
    printMatrix(matrix);

    if (invertMatrix(matrix, inverse) == 0) {
        printf("Inverse Matrix:\n");
        printMatrix(inverse);
    }

    return 0;
}
