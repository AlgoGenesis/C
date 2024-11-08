# Matrix Inversion in C

This C program implements matrix inversion using Gaussian elimination. It takes a square matrix as input and computes its inverse if it exists.

## Description

The program defines a fixed-size square matrix and uses Gaussian elimination to find its inverse. If the matrix is singular (i.e., it does not have an inverse), the program will output an error message.

### Features

- Computes the inverse of a square matrix using Gaussian elimination.
- Handles singular matrices gracefully by checking for zero diagonal elements.
- Prints both the original matrix and its inverse.

## Usage

1. Clone the repository or download the source code.
2. Open the code in your preferred C compiler or IDE.
3. Modify the `matrix` array in the `main` function to test with different matrices.
4. Compile and run the program.

### Example

Given the matrix:

| 4 7 2 | | 3 5 1 | | 2 4 1 |

The output will be the inverse of the matrix if it exists.

## Time and Space Complexity

### Time Complexity

The time complexity of the Gaussian elimination algorithm for matrix inversion is:

- **O(n³)**, where `n` is the number of rows (or columns) in the square matrix. This complexity arises from the nested loops used to perform row operations.

### Space Complexity

The space complexity of the algorithm is:

- **O(n²)**, as it requires additional storage for the inverse matrix and a temporary matrix for calculations.

## Requirements

- A C compiler (e.g., GCC)
- Basic understanding of C programming

