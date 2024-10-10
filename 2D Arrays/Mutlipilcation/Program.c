#include <stdio.h>

int main() {
    int rows1, cols1, rows2, cols2;
    
    printf("Enter the number of rows and columns of the first matrix:\n");
    scanf("%d %d", &rows1, &cols1);
    
    printf("Enter the number of rows and columns of the second matrix:\n");
    scanf("%d %d", &rows2, &cols2);
    
    if (cols1 != rows2) {
        printf("Error: Column of first matrix must be equal to row of second matrix for multiplication.\n");
        return 1;
    }

    int matrix1[rows1][cols1], matrix2[rows2][cols2], result[rows1][cols2];

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
        }
    }

    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            printf("Element at [%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("Element at [%d][%d]: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("Resulting matrix after multiplication:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
