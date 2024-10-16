# Tuple Representation of Sparse Matrix 

## Description

This project demonstrates how to efficiently represent a sparse matrix using tuple form. A sparse matrix has a significant number of zero elements, and storing only the non-zero elements reduces memory usage and improves computational efficiency.

Each non-zero element of the matrix is stored as a tuple:

row index

column index

value (non-zero element)


This representation optimizes storage and allows for faster matrix operations, especially when working with very large matrices.

## Problem Defination

Given a dense matrix, convert it into its sparse form by storing only non-zero elements as a list of tuples. The problem is particularly useful when dealing with matrices that contain a high number of zero elements to minimize storage and processing time.

Input

A 2D matrix (dense form) of size M x N with potentially many zero elements.

Output

A list of tuples where each tuple represents a non-zero element in the format:

(row, column, value)


Example:

For the matrix:

1 0 0
0 0 2
3 0 0

The sparse representation is:

[(0, 0, 1), (1, 2, 2), (2, 0, 3)]

### Algorithm Review

1. Initialization:

Create an empty list to store the non-zero elements as tuples.



2. Matrix Traversal:

Traverse the matrix row by row and column by column.

For each element, if it is non-zero, append a tuple (row, column, value) to the list.



3. Sparse Matrix Creation:

The final sparse matrix is a list of all the non-zero elements in tuple form, representing the positions and values of these elements.

### Time Complexity

Time Complexity: O(M * N)

Where M is the number of rows and N is the number of columns in the matrix.

The algorithm traverses the entire matrix once to identify non-zero elements.


