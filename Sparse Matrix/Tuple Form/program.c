#include <stdio.h>

#define MAX 10 // Maximum size of the matrix

void sparseToTuple(int sparse[MAX][MAX], int rows, int cols) {
    int tuple[MAX * MAX][3]; // Maximum non-zero elements can be rows * cols
    int k = 0; // Counter for the 3-tuple array

    // Traverse through the matrix to find non-zero elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (sparse[i][j] != 0) {
                tuple[k][0] = i;         // Row index
                tuple[k][1] = j;         // Column index
                tuple[k][2] = sparse[i][j]; // Non-zero value
                k++;
            }
        }
    }

    // Print the 3-tuple form
    printf("3-tuple form:\n");
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < k; i++) {
        printf("%d\t%d\t%d\n", tuple[i][0], tuple[i][1], tuple[i][2]);
    }
}

int main() {
    int sparse[MAX][MAX];
    int rows, cols;

    // Input matrix dimensions
    printf("Enter number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    // Input matrix elements
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &sparse[i][j]);
        }
    }

    // Convert sparse matrix to 3-tuple form
    sparseToTuple(sparse, rows, cols);

    return 0;
}