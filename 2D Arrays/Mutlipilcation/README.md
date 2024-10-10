# 2D Arrays(Multiplication) 

## Description
Matrix multiplication is a binary operation that produces a matrix from two matrices. For two matrices to be multiplied, the number of columns in the first matrix must be equal to the number of rows in the second matrix. The resulting matrix will have dimensions based on the number of rows of the first matrix and the number of columns of the second matrix.

## Formula:
For matrices A and B of the same dimensions C[i][j]=A[i][j]XB[i][j]
Where:
i is the row index j is the column index
C[i][j] in the resulting matrix is calculated as:

            k=1
C[i][j]=    ∑A[i][k]×B[k][j]
            n

## Example:
If we have two 2x2 matrices:
Matrix A:

        1 2
        3 4 
 

Matrix B:

        5 6
        7 8

Their mutliplication will be:

Matrix C:


        1x5 + 2x7    1x6 + 2x8              19  22
                                    ==   
        3x5 + 7x4    3x6 + 4x8              43  50

## Program Explanation:
In this program, we:

Prompt the user to input the dimensions of the two matrices.
Ensure that the number of columns of the first matrix matches the number of rows of the second matrix.
Input the elements of both matrices.
Multiply the matrices by taking the dot product of rows of the first matrix with columns of the second matrix.
Display the resulting matrix.
