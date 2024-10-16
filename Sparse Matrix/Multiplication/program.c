#include <stdio.h>

#define MAX 100

// Function to convert sparse matrix to tuple form
int sparseToTuple(int sparse[MAX][MAX], int rows, int cols, int tuple[MAX][3]) {
    int k = 1; 

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (sparse[i][j] != 0) {
                tuple[k][0] = i;     
                tuple[k][1] = j;     
                tuple[k][2] = sparse[i][j]; 
                k++;
            }
        }
    }
    tuple[0][0] = rows;    
    tuple[0][1] = cols;    
    tuple[0][2] = k - 1;   

    return k;  
}

// Function to multiply two sparse matrices in tuple form
void multiplyTuples(int tupleA[MAX][3], int tupleB[MAX][3], int result[MAX][3]) {
    int totalA = tupleA[0][2];
    int totalB = tupleB[0][2];
    int k = 1;  // Index for the result tuple

    if (tupleA[0][1] != tupleB[0][0]) {
        printf("Matrix multiplication not possible due to dimension mismatch.\n");
        return;
    }

    for (int i = 1; i <= totalA; i++) {
        for (int j = 1; j <= totalB; j++) {
            if (tupleA[i][1] == tupleB[j][0]) {
                int row = tupleA[i][0];
                int col = tupleB[j][1];
                int value = tupleA[i][2] * tupleB[j][2];

                // Check if this row and column already exist in the result
                int found = 0;
                for (int x = 1; x < k; x++) {
                    if (result[x][0] == row && result[x][1] == col) {
                        result[x][2] += value; // Add to existing value
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    result[k][0] = row;
                    result[k][1] = col;
                    result[k][2] = value;
                    k++;
                }
            }
        }
    }

    result[0][0] = tupleA[0][0];  // Resultant rows = rows of matrix A
    result[0][1] = tupleB[0][1];  // Resultant columns = columns of matrix B
    result[0][2] = k - 1;         // Total number of non-zero elements in the result
}

// Function to print the tuple form
void printTuple(int tuple[MAX][3]) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i <= tuple[0][2]; i++) {
        printf("%d\t%d\t%d\n", tuple[i][0], tuple[i][1], tuple[i][2]);
    }
}

int main() {
    int sparseA[MAX][MAX], sparseB[MAX][MAX];
    int tupleA[MAX][3], tupleB[MAX][3], result[MAX][3];
    int rowsA, colsA, rowsB, colsB;

    // Input matrix A
    printf("Enter the number of rows and columns for Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter the elements of Matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            scanf("%d", &sparseA[i][j]);
        }
    }

    // Input matrix B
    printf("Enter the number of rows and columns for Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);
    printf("Enter the elements of Matrix B:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            scanf("%d", &sparseB[i][j]);
        }
    }

    // Convert both matrices to tuple form
    sparseToTuple(sparseA, rowsA, colsA, tupleA);
    sparseToTuple(sparseB, rowsB, colsB, tupleB);

    // Multiply the two matrices
    multiplyTuples(tupleA, tupleB, result);

    // Print the result
    printf("Resultant Matrix in 3-tuple form:\n");
    printTuple(result);

    return 0;
}