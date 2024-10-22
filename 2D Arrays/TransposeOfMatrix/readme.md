
Matrix Transposition in C
This program demonstrates three methods to transpose a 2D matrix in C:

1. In-Place Transposition (For Square Matrices)

This method directly modifies the original matrix without using extra space
It works by swapping the elements above the diagonal with the elements below it.

For each element matrix[i][j] where i < j (above the diagonal), we swap it with matrix[j][i] (its corresponding element below the diagonal)


2. Recursive Transposition

This method is a recursive approach to transpose the matrix. 
It eliminates the need for explicit loops by recursively swapping the elements in a depth-first manner.
The recursion continues swapping elements across the diagonal, moving through the matrix row by row.

It starts from the first row and column and moves recursively across the matrix. The elements above the diagonal are swapped with those below the diagonal.


3. Transpose into a New Matrix (For Square and Non-Square Matrices)

In this method a new matrix is created to store the transposed values.
It works by copying the element at position matrix[i][j] in the original matrix into position result[j][i] in the new matrix.

This approach is more flexible because it can handle both square and non-square matrices
The original matrix remains unchanged, and the transposed version is stored in a separate matrix.