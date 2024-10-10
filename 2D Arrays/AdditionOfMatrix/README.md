# 2D Arrays(Addition) 

## Description

Matrix addition is the operation of adding two matrices by adding the corresponding elements in each matrix. For two matrices to be added, they must have the same dimensions (i.e., the same number of rows and columns). The sum of two matrices 𝐴
and 𝐵 both of size 𝑚×𝑛 results in a new matrix C, also of size m×n, where each element C[i][j] is the sum of the corresponding elements A[i][j] and B[i][j].

## Formula:

For matrices A and B of the same dimensions C[i][j]=A[i][j]+B[i][j]
Where:
i is the row index j is the column index

## Example:
If we have two 2x2 matrices:
Matrix A:

        1 2
        3 4 
 

Matrix B:

        5 6
        7 8

Their sum will be:

Matrix C:


        1+5    2+6          6   8
                       ==   
        3+7    4+8          10   12

​
 
## Program Explanation:

In this program, we:

Prompt the user to input the dimensions (rows and columns) of the matrices.
Input the elements of both matrices.
Add corresponding elements of both matrices.
Display the resulting matrix.