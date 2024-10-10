#include <stdio.h>
int main()
{
    int rows ;
    int cols ;
    printf("Enter no. of rows: ");
    scanf("%d",&rows);
    printf("Enter no. of cols: ");
    scanf("%d",&cols);
    int matrix[rows][cols];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Enter the value of matrix: ");
            scanf("%d",&matrix[i][j]);
        }
        
    }
    int matrix1[rows][cols];
        int j = 0;
        while (j < cols) {
            
                for (int i = 0;i < rows; i++) {
                     int n = rows - 1 -j;
                    matrix1[i][n] = matrix[j][i];
                }
                j++;
            
        }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = matrix1[i][j];
        }
    }

    printf("Rotated Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}