#include <stdio.h>

#define MAX 10 // maximum size 

void rotate(int mat[MAX][MAX], int row, int c) {
    for (int i = 0; i < row / 2; i++) {
        for (int j = 0; j < c; j++) {
            // Swapping
            int temp = mat[i][j];
            mat[i][j] = mat[row - i - 1][c - j - 1];
            mat[row - i - 1][c - j - 1] = temp;
        }
    }

    if (row % 2 != 0) {
        for (int j = 0; j < c / 2; j++) {
            int temp = mat[row / 2][j];
            mat[row / 2][j] = mat[row / 2][c - j - 1];
            mat[row / 2][c - j - 1] = temp;
        }
    }
}

void printm(int mat[MAX][MAX], int row, int c) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat[MAX][MAX];
    int row, c;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &row, &c);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("Original Matrix:\n");
    printm(mat, row, c); 

    rotate(mat, row, c);

    printf("Matrix after 180-degree rotation:\n");
    printm(mat, row, c); 
    return 0;
}
