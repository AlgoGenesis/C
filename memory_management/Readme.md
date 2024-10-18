# Memory Management in C

This repository provides an example of how to manage memory dynamically in C using `malloc`, `calloc`, `realloc`, and `free`. Understanding memory management is crucial in C programming to prevent memory leaks and ensure efficient use of memory.

## Problem Statement

Memory management is an essential aspect of C programming. Properly allocating and deallocating memory is necessary to avoid memory leaks and undefined behavior. This example demonstrates the use of various memory allocation functions available in C.

## Code Explanation

The provided code demonstrates:

- **Dynamic Memory Allocation using `malloc`**: Allocates a specified number of bytes and returns a pointer to the first byte.
- **Dynamic Memory Allocation using `calloc`**: Allocates memory for an array of elements, initializing all bytes to zero.
- **Reallocating Memory using `realloc`**: Changes the size of previously allocated memory, allowing for dynamic adjustment of data structures.
- **Deallocating Memory using `free`**: Releases allocated memory, preventing memory leaks.

## Example

Here's a snippet of the output you can expect from the code:

arr_malloc[0] = 1 arr_malloc[1] = 2 arr_malloc[2] = 3 arr_malloc[3] = 4 arr_malloc[4] = 5 arr_calloc[0] = 0 arr_calloc[1] = 0 arr_calloc[2] = 0 arr_calloc[3] = 0 arr_calloc[4] = 0 After reallocation: arr_malloc[0] = 1 arr_malloc[1] = 2 arr_malloc[2] = 3 arr_malloc[3] = 4 arr_malloc[4] = 5 arr_malloc[5] = 6 arr_malloc[6] = 7 arr_malloc[7] = 8 arr_malloc[8] = 9 arr_malloc[9] = 10



## Time Complexity

- **`malloc` and `calloc`**: O(1) - These operations have constant time complexity since they do not depend on the size of the memory being allocated.
- **`realloc`**: O(n) - The complexity can vary. If the reallocation occurs in the same memory block, it's O(1). If a new block is allocated, it involves copying existing data, leading to O(n).
- **`free`**: O(1) - Freeing memory is a constant time operation.

## Conclusion

Proper memory management is critical in C programming to ensure optimal performance and resource utilization. This example illustrates how to use dynamic memory allocation functions effectively.

### Usage

To compile and run the code, use the following commands:

```bash
gcc memory_management.c -o memory_management
./memory_management
