# Deque Implementation Using Doubly Linked List

This project implements a deque (double-ended queue) using a doubly linked list in C. It supports operations to insert, delete, and display elements from both ends of the deque, providing flexibility for applications that require quick access from either side of the queue.

## Features

- **Insert at Front**: Adds an element at the front of the deque.
- **Insert at Rear**: Adds an element at the rear of the deque.
- **Delete from Front**: Removes an element from the front of the deque.
- **Delete from Rear**: Removes an element from the rear of the deque.
- **Display**: Shows all elements in the deque from front to rear.
- **Destroy**: Frees all allocated memory when exiting the program.

## Code Structure

- **Node Structure**: Each node contains an integer `data` and two pointers, `prev` and `next`, for bidirectional traversal.
- **Deque Structure**: Contains two pointers, `front` and `rear`, pointing to the respective ends of the deque.
- **Functions**:
  - `initializeDeque`: Initializes the deque by setting `front` and `rear` to `NULL`.
  - `isEmpty`: Checks if the deque is empty.
  - `createNode`: Allocates memory for a new node and initializes its data.
  - `insertFront`: Inserts a new element at the front.
  - `insertRear`: Inserts a new element at the rear.
  - `deleteFront`: Deletes an element from the front and returns its value.
  - `deleteRear`: Deletes an element from the rear and returns its value.
  - `display`: Displays the elements in the deque from front to rear.
  - `destroyDeque`: Frees all memory allocated for the deque.


