#include <stdio.h>
int main()
{
    int rows ;
    int cols ;
    int target ;
    int i=0;
    int j=0;
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
    int k=0;
        int n= cols-1;
        while(i<rows && j<cols){
            if(matrix[i][j]==target){
                k++;
                break;
            }else if(matrix[i][j]<target){
                if(j==n){
                    j=0;
                    i++;
                }else{

                j++;
                }
            }
            else{
                j=0;
                i++;
            }
        }
        if(k==0){
            printf("Element not found");

        }else{
            printf("Element found");
        }
    return 0;
}