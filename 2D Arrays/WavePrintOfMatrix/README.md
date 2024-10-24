# Row-Wise Wave Print in a Matrix

## Problem Statement
Given a 2D matrix of size n x m, print the matrix in a wave-like manner.

## Example
Given matrix:
A = [
    [11, 12, 13, 14]
    [21, 22, 23, 24]
    [31, 32, 33, 34]
    [41, 42, 43, 44]
]

The wave print output should be:
11 12 13 14 24 23 22 21 31 32 33 34 44 43 42 41

## Approach

# Input
A 2D matrix of size n x m where n is the number of rows and m is the number of columns.

# Output
Single list or sequence of elements representing the matrix in a row-wise wave form.

# Algorithm:
1. Traverse through the rows one by one.
2. For each even-indexed row (0, 2, 4,...), print the elements from left to right.
3. For each odd-indexed row (1, 3, 5,...), print the elements from right to left.
4. Continue until all rows are processed.

_____________________________________________________________

# Column-Wise Wave Print in a Matrix

## Problem Statement
Given a 2D matrix of size n x m, print the matrix in a wave-like manner.

## Example
Given matrix:
A = [
    [11, 12, 13, 14]
    [21, 22, 23, 24]
    [31, 32, 33, 34]
    [41, 42, 43, 44]
]

The wave print output should be:
11, 21, 31, 41, 42, 32, 22, 12, 13, 23, 33, 43, 44, 34, 24, 14

## Approach

# Input
A 2D matrix of size n x m where n is the number of rows and m is the number of columns.

# Output
Single list or sequence of elements representing the matrix in a column-wise wave form.

# Algorithm:
1. Traverse through the columns one by one.
2. For each even-indexed row (0, 2, 4,...), print the elements from top to bottom.
3. For each odd-indexed row (1, 3, 5,...), print the elements from bottom to top.
4. Continue until all columns are processed.

## Complexity (in both cases)
1. Time Complexity: O(n * m), where n is the number of rows and m is the number of columns, since we visit each element exactly once.
2. Space Complexity: O(1), as no extra space is used apart from the input matrix.