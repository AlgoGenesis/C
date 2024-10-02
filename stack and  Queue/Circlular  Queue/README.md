# Circular Queue Implementation in C

This project implements a Circular Queue data structure in C. The Circular Queue is designed for efficient management of a fixed-size buffer, providing constant time complexity for both enqueue and dequeue operations.

## Features

- **Dynamic Size**: The circular queue can be initialized with a specified size.
- **Efficient Operations**: Supports enqueue and dequeue operations in O(1) time.
- **Error Handling**: Includes error handling for queue overflow and underflow conditions.
- **Display Functionality**: Provides a method to visualize the elements in the queue.

## Data Structure

### CircularQueue

The CircularQueue structure consists of:
- `size`: The maximum number of elements the queue can hold.
- `front`: The index of the front element in the queue.
- `rear`: The index of the rear element in the queue.
- `Q`: A pointer to the array that stores the queue elements.

## Getting Started

### Prerequisites

- A C compiler (e.g., GCC, Clang)
- Basic knowledge of C programming

### Compilation

To compile the code, navigate to the project directory and run:

```bash
gcc -o circular_queue program.c
