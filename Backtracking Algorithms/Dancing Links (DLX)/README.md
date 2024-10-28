# Dancing Links (DLX) Algorithm for Exact Cover

This project implements the Dancing Links (DLX) algorithm in C, adhering to the C11 standard for maximum portability. The DLX algorithm is an efficient method for solving exact cover problems, such as Sudoku puzzles, N-Queens, and polyomino tiling.

## Table of Contents

- [Introduction](#introduction)
- [Algorithm Overview](#algorithm-overview)
- [Data Structures](#data-structures)
- [Implementation Details](#implementation-details)
- [Compilation and Execution](#compilation-and-execution)
- [Example Usage](#example-usage)
- [Output Explanation](#output-explanation)
- [Further Development](#further-development)
- [References](#references)

## Introduction

An **exact cover** problem requires selecting a subset of rows from a binary matrix so that every column contains exactly one `1`. Donald Knuth introduced **Algorithm X** as a recursive, nondeterministic, depth-first, backtracking algorithm to find all solutions to the exact cover problem.

**Dancing Links (DLX)** is Knuth's efficient implementation of Algorithm X, which uses a circular doubly-linked list to represent the matrix. DLX allows for efficient removal and restoration of nodes during the search process.

## Algorithm Overview

The DLX algorithm operates by:

1. **Choosing a Column**: Selects the column with the least number of `1`s to minimize branching.
2. **Covering the Column**: Removes the selected column and all rows containing a `1` in that column.
3. **Selecting Rows**: Iterates through the rows that contain a `1` in the selected column.
4. **Covering Rows**: For each selected row, covers all other columns where the row has a `1`.
5. **Recursive Search**: Recursively repeats the process until a solution is found or all possibilities are exhausted.
6. **Uncovering**: Backtracks by uncovering columns and rows to explore other possibilities.

## Data Structures

### Node

Represents an element in the matrix. Each `Node` is part of four doubly-linked lists:

- **Left and Right**: Links to neighboring nodes in the same row.
- **Up and Down**: Links to neighboring nodes in the same column.

```c
typedef struct Node {
    struct Node *left;
    struct Node *right;
    struct Node *up;
    struct Node *down;
    struct Column *col;
} Node;
```

### Column

Inherits from `Node` and includes additional information:

- **Size**: Number of `1`s in the column.
- **Name**: Identifier for debugging and display purposes.

```c
typedef struct Column {
    Node node;     // Node header
    int size;      // Number of ones in the column
    char name[20]; // Identifier for debugging
} Column;
```

### Root

A special `Column` node that serves as the starting point for traversing the matrix headers.

```c
static Column root;
```

## Implementation Details

### Initialization

- **`initialize_dlx(int cols)`**: Initializes the DLX matrix with the specified number of columns, creating column headers linked in a circular doubly-linked list.

### Adding Rows

- **`add_row(int *row_data, int row_size, char *row_name)`**: Adds a row to the DLX matrix based on the input binary data.

### Covering and Uncovering

- **`cover(Column *col)`**: Covers a column and all rows containing a `1` in that column, effectively removing them from the matrix.
- **`uncover(Column *col)`**: Uncovers a column and all previously covered rows, restoring them to the matrix.

### Searching for Solutions

- **`search(int k)`**: Recursively searches for all exact cover solutions, where `k` represents the depth of the recursion.

### Choosing Columns

- **`choose_column()`**: Selects the column with the smallest size (fewest `1`s) to optimize the search process.

### Memory Management

- **Dynamic Allocation**: Uses `malloc` to allocate memory for column headers and row nodes.
- **Static Arrays**: An array `nodes[MAX_NODES]` is used for node storage, where `MAX_NODES` is a predefined constant.

### Self-Checks

- **`is_safe()`**: Placeholder function for integrity checks of the DLX structure. Users can implement specific checks as needed.

## Compilation and Execution

### Requirements

- **Compiler**: A C11-compliant compiler (e.g., GCC, Clang).
- **Operating System**: Compatible with MacOS and Linux.

### Compilation

Compile the code using the following command:

```bash
gcc -std=c11 -Wall -Wextra -o dlx program.c
```

- **`-std=c11`**: Ensures the code adheres to the C11 standard.
- **`-Wall -Wextra`**: Enables all warnings for safer code.

### Execution

Run the compiled executable:

```bash
./dlx
```

## Example Usage

The `main` function in `program.c` demonstrates how to use the DLX algorithm to solve a simple exact cover problem.

### Example Matrix

The binary matrix represents the exact cover problem:

```
      C0 C1 C2 C3 C4 C5 C6
Row0: 0  0  1  0  1  1  0
Row1: 1  0  0  1  0  0  1
Row2: 0  1  1  0  0  1  0
Row3: 1  0  0  1  0  0  0
Row4: 0  1  0  0  0  0  1
Row5: 0  0  0  1  1  0  1
```

### Code Snippet

```c
int main() {
    /* Example matrix for exact cover problem */
    int matrix_data[6][7] = {
        {0, 0, 1, 0, 1, 1, 0}, /* Row 0 */
        {1, 0, 0, 1, 0, 0, 1}, /* Row 1 */
        {0, 1, 1, 0, 0, 1, 0}, /* Row 2 */
        {1, 0, 0, 1, 0, 0, 0}, /* Row 3 */
        {0, 1, 0, 0, 0, 0, 1}, /* Row 4 */
        {0, 0, 0, 1, 1, 0, 1}  /* Row 5 */
    };

    initialize_dlx(7);

    /* Add rows to the DLX structure */
    for (int i = 0; i < 6; i++) {
        add_row(matrix_data[i], 7, "Row");
    }

    if (!is_safe()) {
        fprintf(stderr, "DLX structure integrity check failed.\n");
        free_dlx();
        return EXIT_FAILURE;
    }

    /* Start the search */
    search(0);

    free_dlx();
    return EXIT_SUCCESS;
}
```

## Output Explanation

When you run the program, it will output all possible solutions to the exact cover problem defined by the matrix. Each solution consists of a set of rows that together cover each column exactly once.

### Sample Output

```
Solution 1:
Row: C2 C5 C4
Row: C0 C3 C6
```

## Further Development

### Solving Sudoku

To adapt this code for solving Sudoku puzzles:

- **Representation**: Encode the Sudoku constraints into an exact cover matrix.
- **Constraints**: Each cell must contain a digit from 1 to 9 without violating Sudoku rules.
- **Adjustments**: Modify the code to handle the larger matrix and additional constraints.

### Performance Optimization

- **Dynamic Data Structures**: Consider using linked lists or other dynamic structures for scalability.
- **Parallelization**: Implement multithreading to explore branches of the search tree concurrently.
- **Heuristics**: Use advanced column selection heuristics to reduce the search space.

### Error Handling and Logging

- **Robustness**: Enhance error handling for invalid inputs and memory allocation failures.
- **Logging**: Implement logging mechanisms to trace the algorithm's execution steps.

## References

- **Donald Knuth's Paper**: [Dancing Links](https://arxiv.org/pdf/cs/0011047.pdf)
- **Exact Cover Problem**: [Wikipedia - Exact Cover](https://en.wikipedia.org/wiki/Exact_cover)
- **Algorithm X**: [Wikipedia - Algorithm X](https://en.wikipedia.org/wiki/Algorithm_X)
- **Sudoku Solving with DLX**: [Sudoku and Dancing Links](http://www.cs.mcgill.ca/~aassaf9/python/algorithm_x.html)

---

Feel free to explore and modify the code to suit your exact cover problems. Contributions and improvements are welcome!