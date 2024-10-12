#include <stdio.h>
int main()
{
    int rows ;
    int cols ;
    int target ;
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
    printf("Enter element to be searched: ");
    scanf("%d",&target);
    int k =0;
        for(int i=0;i<rows;i++){
            for(int j =0;j<cols;j++){
                if(matrix[i][j]==target){

                    k++;
                    break;
                }
                
            }
        }
        if(k==0){
            printf("Element not found");

        }else{
            printf("Element found");
        }
    return 0;
}