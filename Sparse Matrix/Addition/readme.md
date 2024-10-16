# Sparse Matrix Addition (in Tuple form)

## Description

This project demonstrates how to efficiently add two sparse matrices using tuple representation. Sparse matrices have a significant number of zero elements, and storing only the non-zero elements using tuples saves memory and optimizes matrix operations.

Each matrix is represented as a list of tuples, where each tuple contains:

row index

column index

value (the non-zero element)

### Problem Defination

Given two sparse matrices in tuple form, add them together and return the resulting sparse matrix. The addition is performed element-wise, considering only non-zero elements to optimize performance and memory usage.

Input

Two sparse matrices in tuple form, for example:

Matrix 1: [(0, 1, 4), (1, 2, 7), (2, 0, 3)]

Matrix 2: [(0, 1, 5), (2, 0, 6)]


Output

A sparse matrix representing the sum of both input matrices in tuple form:

Result: [(0, 1, 9), (1, 2, 7), (2, 0, 9)]


Algorithm Review

1. Initialize two sparse matrices:

Represented as a list of tuples where each tuple stores the row, column, and value of a non-zero element.



2. Merge the two matrices:

Use a dictionary to store the positions (row, column) as keys and values as the sum of elements from both matrices.

Traverse both matrices, adding corresponding non-zero values if they have the same position.



3. Handle mismatches:

If an element exists in only one of the matrices, it is added directly to the result.



4. Convert back to tuple form:

After summing all non-zero elements, convert the dictionary back into a list of tuples representing the resulting sparse matrix.

### Algorithm Review

Step 1: Create an empty dictionary for storing results.

Step 2: Traverse both matrices:

Add non-zero elements from the first matrix to the dictionary.

For the second matrix, add elements if the position is not in the dictionary, otherwise sum the values.


Step 3: Convert the dictionary back to a list of tuples.

Step 4: Return the resulting list.

### Time Complexity

Time Complexity: O(n + m)

Where n and m are the number of non-zero elements in matrix 1 and matrix 2, respectively.

Each element in both matrices is processed once, and dictionary operations (insert and update) are performed in constant time.
