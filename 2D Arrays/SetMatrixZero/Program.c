#include <stdio.h>

#define MAX 100

// Function to print the matrix
void printMatrix(int matrix[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to set the rows and columns to zero where element is zero
void setMatrixZero(int matrix[][MAX], int rows, int cols) {
    int rowFlag[MAX] = {0};  // Array to mark rows to be set to zero
    int colFlag[MAX] = {0};  // Array to mark columns to be set to zero

    // First pass: Identify rows and columns to be zeroed
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                rowFlag[i] = 1;  // Mark row i for zeroing
                colFlag[j] = 1;  // Mark column j for zeroing
            }
        }
    }

    // Second pass: Set identified rows and columns to zero
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (rowFlag[i] == 1 || colFlag[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {
    int matrix[MAX][MAX];
    int rows, cols;

    // Taking input for the dimensions of the matrix
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Taking input for matrix elements
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Original Matrix:\n");
    printMatrix(matrix, rows, cols);

    // Setting the required rows and columns to zero
    setMatrixZero(matrix, rows, cols);

    printf("Modified Matrix:\n");
    printMatrix(matrix, rows, cols);

    return 0;
}
