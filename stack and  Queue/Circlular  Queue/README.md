# Circular Queue Implementation in C

## Description

This project implements a Circular Queue data structure in C. A Circular Queue allows for efficient use of storage by connecting the end of the queue back to the beginning, enabling the reuse of space from dequeued elements. It operates on the First-In-First-Out (FIFO) principle.

## Features

- **Dynamic Size**: The circular queue can be initialized with a specified size.
- **Efficient Operations**: Supports enqueue and dequeue operations in O(1) time.
- **Error Handling**: Includes error handling for queue overflow and underflow conditions.
- **Display Functionality**: Provides a method to visualize the elements in the queue.

## Problem Definition

### Given:
- An integer array that will be managed using the circular queue structure.

### Objective:
- Implement basic queue operations such as enqueue, dequeue, and display.

## Algorithm Overview

1. **Initialize Queue**: Allocate memory for the queue and set initial front and rear indices.
2. **Enqueue Operation**: Add an element to the rear of the queue. If the queue is full, display an overflow message.
3. **Dequeue Operation**: Remove an element from the front of the queue. If the queue is empty, display an underflow message.
4. **Display Queue**: Print the elements of the queue from front to rear.

## Time Complexity

- **Enqueue**: O(1) - Constant time complexity for adding an element.
- **Dequeue**: O(1) - Constant time complexity for removing an element.
- **Display**: O(n) - Linear time complexity to display all elements.

## Implementation

### Prerequisites

- A C compiler (e.g., GCC, Clang)
- Basic knowledge of C programming

### Compilation

To compile the code, navigate to the project directory and run:

```bash
gcc -o circular_queue circular_queue.c
