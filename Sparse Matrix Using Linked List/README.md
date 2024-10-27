# Sparse Matrix Representation Using Linked List

This project implements a sparse matrix using a linked list in C. Sparse matrices are matrices in which the majority of elements are zero, and using a linked list provides an efficient way to store only the non-zero elements, saving memory and improving performance.

## Features

- **Node Structure**: Each node stores the row, column, and value of a non-zero element in the matrix, along with a pointer to the next node.
- **Efficient Storage**: Only non-zero elements are stored, making this implementation space-efficient for sparse matrices.
- **Linked List Operations**:
  - Insert non-zero elements into the linked list.
  - Display the matrix by reconstructing it from the linked list.
  - Free the linked list memory upon program exit.

## Code Structure

- **Node Definition**: Each node contains:
  - `row` and `col`: Position of the element in the matrix.
  - `value`: The non-zero value of the element.
  - `next`: Pointer to the next node in the linked list.
  
- **Functions**:
  - `createNode`: Creates and initializes a new node with given row, column, and value.
  - `insertNode`: Adds a new non-zero element to the linked list.
  - `displaySparseMatrix`: Displays the matrix by traversing the linked list and printing elements row by row.
  - `freeList`: Frees the memory used by the linked list.

