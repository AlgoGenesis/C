
# Matrix Transposition in C
This program demonstrates three methods to transpose a 2D matrix in C

### 1. In-Place Transposition (For Square Matrices)

This method directly modifies the original matrix without using extra space
It works by swapping the elements above the diagonal with the elements below it.

For each element matrix[i][j] where i < j (above the diagonal), we swap it with matrix[j][i] (its corresponding element below the diagonal)


### 2. Recursive Transposition

This method is a recursive approach to transpose the matrix. 
It eliminates the need for explicit loops by recursively swapping the elements in a depth-first manner.
The recursion continues swapping elements across the diagonal, moving through the matrix row by row.

It starts from the first row and column and moves recursively across the matrix. The elements above the diagonal are swapped with those below the diagonal.


### 3. Transpose into a New Matrix (For Square and Non-Square Matrices)

In this method a new matrix is created to store the transposed values.
It works by copying the element at position matrix[i][j] in the original matrix into position result[j][i] in the new matrix.

This approach is more flexible because it can handle both square and non-square matrices
The original matrix remains unchanged, and the transposed version is stored in a separate matrix


## Code Explanation

```
void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
```
Function printMatrix: This function takes the number of rows, columns, and a 2D array (matrix) as input. It prints the elements of the matrix in a grid format.

#### // In-place transpose for a square matrix
```
void transposeInPlace(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}
```
Function transposeInPlace: This function transposes a square matrix in place. It swaps the elements across the diagonal by iterating only over the upper triangular part of the matrix. This way, it avoids swapping elements back and forth.

#### // Transpose a matrix recursively
```
void transposeRecursive(int matrix[N][N], int i, int j) {
    if (i >= N) return;

    // Swap the elements
    if (j < i) {
        int temp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = temp;
    }

    // Recurse for next element
    if (j < N - 1) {
        transposeRecursive(matrix, i, j + 1);
    } else {
        transposeRecursive(matrix, i + 1, 0);
    }
}
```
Function transposeRecursive: This function transposes a square matrix using recursion. It checks if the current row index i is within bounds, and swaps elements if the column index j is less than i. It then recurses to the next column or to the next row if it reaches the end of the current row.


#### // Transpose into a new matrix (works for both square and non-square matrices)
```
void transposeNewMatrix(int matrix[ROWS][COLS], int result[COLS][ROWS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}
```
Function transposeNewMatrix: This function creates a new transposed matrix. It takes the original matrix and fills a new result matrix with the transposed values


### Changing input
To change the input, modify the matrix initialization in the main function

#### Usage
```
Copy code

gcc -o program program.c
```

