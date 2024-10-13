// Method 2
#include <stdio.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y= temp;
}
int main(){

   int n=4;
   int mat[4][4]= { { 1, 2, 3, 4 },{ 5, 6, 7, 8 },{ 9, 10, 11, 12 },{ 13, 14, 15, 16 } };

   //Rotate the matrix about the main diagonal
   for(int i=0; i<n; i++){
     for(int j=0; j<i; j++)
         swap(&mat[i][j], &mat[j][i]);
    }

   //Rotate the matrix about middle column
   for(int i=0; i<n; i++){
     for(int j=0; j<n/2; j++){
        swap(&mat[i][j], &mat[i][n-j-1]);
     }
   }


   //Print the matrix
   printf("Rotated Matrix :\n");
   for(int i=0; i<n; i++){
     for(int j=0; j<n; j++){
       printf("%d ",mat[i][j]);
     }
     printf("\n");
   }
}
