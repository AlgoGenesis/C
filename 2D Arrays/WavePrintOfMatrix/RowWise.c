#include <stdio.h>

void RowWiseWavePrint(int rows, int cols, int matrix[rows][cols]){
    int i, j;
    for(i=0; i<rows; i++){
        if(i % 2 == 0){
            for(j=0; j<cols; j++){
                printf("%d\t", matrix[i][j]);
            }
        }
        else{
            for(j=cols-1; j>=0; j--){
                printf("%d\t", matrix[i][j]);
            }
        }
    }
}

int main(){
    int rows;
    printf("Enter no. of rows: ");
    scanf("%d", &rows);

    int cols;
    printf("Enter no. of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];
    int i, j;
    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
            printf("Enter value: ");
            scanf("%d", &matrix[i][j]);
        }
    }
    
    RowWiseWavePrint(rows, cols, matrix);
}