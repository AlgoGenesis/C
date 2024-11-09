# Magic Square

## Description

This program checks whether a given square matrix is a Magic Square. A Magic Square is a square matrix in which the sum of every row, column, and both diagonals is the same. The program employs an algorithm to validate this property for any square matrix provided by the user.

```
Example:
Enter the size(between 1 and 10) of the matrix (n x n): 3
Enter the elements of the matrix:
2 7 6
9 5 1
4 3 8

Output:
The matrix is a magic square.
```

### Problem Definition

1.  **Given**:
- A square matrix `matrix[n][n]` with user-defined size `n`.

2.  **Objective**:
- Determine if the matrix satisfies the magic square property: `The sums of each row, each column, and both diagonals must be equal.`

### Algorithm Overview

1. **Input Validation**:
   - Ensure the matrix is square (`n x n`).

2. **Diagonal Calculation and Check**:
   - Compute the sums of the primary(`sumDiag1`) and secondary(`sumDiag2`) diagonals and ensure they are equal.

3. **Row and Column Sum Check**:
   - Calculate the sums for each row(`sumRow`) and column(`sumCol`) and compare them with either of the diagonal sum(`sumDiag1`/`sumDiag2`) to check if they are all equal.

5. **Output Result**:
   - If all checks pass, the matrix is a magic square; otherwise, it is not.

### Key Features

- Validates any `n x n` matrix for the magic square property.
- Modular design with functions for input, processing, and output.
- Handles edge cases, such as invalid matrix sizes or non-square matrices.

### Time Complexity

- **Best case**: `O(n²)`, where `n` is the size of the matrix (all elements are processed once).
- **Worst case**: `O(n²)`, as every row, column, and diagonal must be checked.

### Space Complexity

- `O(1)` (in-place calculations, no additional memory allocation beyond the matrix).

## Implementation

The implementation in C includes:

1. **Input Handling**:
    - Accept user input for the matrix size and its elements.

2. **Functionality**:
    - A function to compute the sums of rows, columns, and diagonals.
    - Logical checks to compare all sums with the reference sum.

3. **Output**:
    - Displays whether the matrix is a magic square or not.

## Usage

- Compile the program using a C compiler (e.g., `gcc magic_square.c -o magic_square`).
- Run the program (`./magic_square`).
- Input the size of the matrix and its elements.
- Observe the output indicating whether the matrix is a magic square.