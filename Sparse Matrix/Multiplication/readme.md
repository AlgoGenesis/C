# Sparse Matrix Multiplication (in Tuple Form)

## Description 

This project provides an efficient method for multiplying two sparse matrices using tuple representation. In a sparse matrix, most elements are zero, so using tuples to store only the non-zero elements reduces both space and computational complexity.

Each matrix is represented as a list of tuples where each tuple contains:

row index

column index

value (non-zero element)

### Problem Defination

Given two sparse matrices in tuple form, multiply them together and return the resulting matrix in sparse (tuple) form. Matrix multiplication involves computing the dot product of rows from the first matrix with columns of the second matrix, but only non-zero elements are considered in this case.

Input

Two sparse matrices in tuple form:

Matrix A (size M x N)

Matrix B (size N x P)


Note: The number of columns in Matrix A must equal the number of rows in Matrix B for matrix multiplication to be valid.

Output

A sparse matrix in tuple form representing the product of Matrix A and Matrix B.

### Algorithm Review 

1. Representation:

Each matrix is stored as a list of tuples, where each tuple contains the row, column, and value of a non-zero element.



2. Matrix Multiplication:

For each non-zero element in Matrix A, find all corresponding non-zero elements in Matrix B that share the same column (column of A = row of B).

Multiply these elements and add their product to the result matrix.



3. Sparse Storage:

Use a dictionary to store the results of the multiplication, where the key is a tuple representing the position (row, column) and the value is the sum of products for that position.



4. Convert back to tuple form:

After performing the multiplication, convert the result from the dictionary back into a list of tuples for the final sparse matrix.


### Time Complexity

ime Complexity: O(n * m)

Where n is the number of non-zero elements in Matrix A and m is the number of non-zero elements in Matrix B.

The multiplication process involves searching for corresponding elements and performing multiplications only for non-zero values, making it efficient.
