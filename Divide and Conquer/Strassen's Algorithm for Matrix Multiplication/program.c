#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix of size n x n
int** allocateMatrix(int n) {
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }
    return matrix;
}

// Function to free the memory allocated for a matrix
void freeMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to add two matrices
void addMatrix(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract matrix B from matrix A
void subtractMatrix(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Recursive function implementing Strassen's algorithm
void strassen(int** A, int** B, int** C, int n) {
    if (n == 1) {
        // Base case: if the matrix is 1x1, multiply directly
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;

    // Allocate memory for submatrices
    int** A11 = allocateMatrix(newSize);
    int** A12 = allocateMatrix(newSize);
    int** A21 = allocateMatrix(newSize);
    int** A22 = allocateMatrix(newSize);
    int** B11 = allocateMatrix(newSize);
    int** B12 = allocateMatrix(newSize);
    int** B21 = allocateMatrix(newSize);
    int** B22 = allocateMatrix(newSize);
    int** C11 = allocateMatrix(newSize);
    int** C12 = allocateMatrix(newSize);
    int** C21 = allocateMatrix(newSize);
    int** C22 = allocateMatrix(newSize);
    int** M1 = allocateMatrix(newSize);
    int** M2 = allocateMatrix(newSize);
    int** M3 = allocateMatrix(newSize);
    int** M4 = allocateMatrix(newSize);
    int** M5 = allocateMatrix(newSize);
    int** M6 = allocateMatrix(newSize);
    int** M7 = allocateMatrix(newSize);
    int** TempA = allocateMatrix(newSize);
    int** TempB = allocateMatrix(newSize);

    // Divide matrices A and B into 4 submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Compute the 7 products using Strassen's algorithm
    addMatrix(A11, A22, TempA, newSize);         // TempA = A11 + A22
    addMatrix(B11, B22, TempB, newSize);         // TempB = B11 + B22
    strassen(TempA, TempB, M1, newSize);         // M1 = (A11 + A22) * (B11 + B22)

    addMatrix(A21, A22, TempA, newSize);         // TempA = A21 + A22
    strassen(TempA, B11, M2, newSize);           // M2 = (A21 + A22) * B11

    subtractMatrix(B12, B22, TempB, newSize);    // TempB = B12 - B22
    strassen(A11, TempB, M3, newSize);           // M3 = A11 * (B12 - B22)

    subtractMatrix(B21, B11, TempB, newSize);    // TempB = B21 - B11
    strassen(A22, TempB, M4, newSize);           // M4 = A22 * (B21 - B11)

    addMatrix(A11, A12, TempA, newSize);         // TempA = A11 + A12
    strassen(TempA, B22, M5, newSize);           // M5 = (A11 + A12) * B22

    subtractMatrix(A21, A11, TempA, newSize);    // TempA = A21 - A11
    addMatrix(B11, B12, TempB, newSize);         // TempB = B11 + B12
    strassen(TempA, TempB, M6, newSize);         // M6 = (A21 - A11) * (B11 + B12)

    subtractMatrix(A12, A22, TempA, newSize);    // TempA = A12 - A22
    addMatrix(B21, B22, TempB, newSize);         // TempB = B21 + B22
    strassen(TempA, TempB, M7, newSize);         // M7 = (A12 - A22) * (B21 + B22)

    // Calculate C11, C12, C21, C22
    addMatrix(M1, M4, TempA, newSize);           // TempA = M1 + M4
    subtractMatrix(TempA, M5, TempB, newSize);   // TempB = TempA - M5
    addMatrix(TempB, M7, C11, newSize);          // C11 = M1 + M4 - M5 + M7

    addMatrix(M3, M5, C12, newSize);             // C12 = M3 + M5

    addMatrix(M2, M4, C21, newSize);             // C21 = M2 + M4

    addMatrix(M1, M3, TempA, newSize);           // TempA = M1 + M3
    subtractMatrix(TempA, M2, TempB, newSize);   // TempB = TempA - M2
    addMatrix(TempB, M6, C22, newSize);          // C22 = M1 + M3 - M2 + M6

    // Combine the 4 submatrices into the result matrix C
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    // Free allocated memory for submatrices
    freeMatrix(A11, newSize);
    freeMatrix(A12, newSize);
    freeMatrix(A21, newSize);
    freeMatrix(A22, newSize);
    freeMatrix(B11, newSize);
    freeMatrix(B12, newSize);
    freeMatrix(B21, newSize);
    freeMatrix(B22, newSize);
    freeMatrix(C11, newSize);
    freeMatrix(C12, newSize);
    freeMatrix(C21, newSize);
    freeMatrix(C22, newSize);
    freeMatrix(M1, newSize);
    freeMatrix(M2, newSize);
    freeMatrix(M3, newSize);
    freeMatrix(M4, newSize);
    freeMatrix(M5, newSize);
    freeMatrix(M6, newSize);
    freeMatrix(M7, newSize);
    freeMatrix(TempA, newSize);
    freeMatrix(TempB, newSize);
}

int main() {
    int n;
    printf("Enter the size of matrices (must be power of 2): ");
    scanf("%d", &n);

    // Allocate memory for matrices A, B, and result C
    int** A = allocateMatrix(n);
    int** B = allocateMatrix(n);
    int** C = allocateMatrix(n);

    // Input elements for matrix A
    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

        // Input elements for matrix B
    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    // Call Strassen's algorithm to multiply matrices A and B, storing the result in C
    strassen(A, B, C, n);

    // Output the resultant matrix
    printf("Resultant matrix after multiplication:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory for matrices A, B, and C
    freeMatrix(A, n);
    freeMatrix(B, n);
    freeMatrix(C, n);

    return 0;
}
