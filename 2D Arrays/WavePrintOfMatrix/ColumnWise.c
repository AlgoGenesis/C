#include <stdio.h>

void ColWiseWavePrint(int rows, int cols, int matrix[rows][cols]){
    int i, j;
    for(j=0; j<cols; j++){
        if(j % 2 == 0){
            for(i=0; i<rows; i++){
                printf("%d\t", matrix[i][j]);
            }
        }
        else{
            for(i=rows-1; i>=0; i--){
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
    
    ColWiseWavePrint(rows, cols, matrix);
}