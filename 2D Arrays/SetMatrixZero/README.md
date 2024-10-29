# Set Matrix Zero

## Problem Statement
Given a matrix, if an element in the matrix is `0`, you must set its entire row and column to `0`. The task is to modify the matrix in place to achieve this result.

### Example
Input:
matrix = [[1,1,1], [1,0,1], [1,1,1]]

Output:
[[1,0,1], [0,0,0], [1,0,1]]

### Explanation
Since `matrix[1][1]` is `0`, the entire row and column where this element is located are set to `0`.

---

## Code Explanation

The C program provided below takes the matrix dimensions and elements as input and sets rows and columns to zero according to the problem statement.

### Code Flow
1. **Input Matrix Dimensions and Elements**: The user enters the matrix dimensions (`rows` and `cols`) and the elements.
2. **Identifying Rows and Columns for Zeroing**:
   - Two arrays, `rowFlag` and `colFlag`, are used to keep track of which rows and columns should be set to zero.
   - In a first pass through the matrix, if a `0` is found at any position `matrix[i][j]`, the program marks the respective row and column in `rowFlag` and `colFlag`.
3. **Setting Rows and Columns to Zero**:
   - In a second pass through the matrix, if a row or column is marked in the `rowFlag` or `colFlag`, all elements in that row or column are set to zero.
4. **Output Modified Matrix**: The program prints the modified matrix with the correct rows and columns set to zero.

### Example Usage

#### Input
Enter the number of rows and columns: 3 3 Enter the elements of the matrix: 1 1 1 1 0 1 1 1 1

#### Output
Original Matrix: 1 1 1 1 0 1 1 1 1

Modified Matrix: 1 0 1 0 0 0 1 0 1


---

## Complexity Analysis
- **Time Complexity**: `O(rows * cols)` for both passes over the matrix.
- **Space Complexity**: `O(rows + cols)` for the additional `rowFlag` and `colFlag` arrays used to mark rows and columns to be zeroed.




