# Queue Implementation in C

This program demonstrates a simple implementation of a queue using a linked list in C. The queue supports the following operations:
- Enqueue (add data to the queue)
- Dequeue (remove data from the queue)
- Display (print the entire queue)
- Check if the queue is empty
- Peek (view the front element without removing it)
- Exit (terminate the program and free allocated memory)

## Features
- Dynamic memory allocation using `malloc()`
- FIFO (First In, First Out) structure using a linked list
- Memory cleanup through recursive deallocation (`freeQueue` function)

## Code Overview

The program contains the following functions:

- **`Display()`**: Displays the entire queue.
- **`IsEmpty()`**: Checks whether the queue is empty.
- **`Enqueue()`**: Adds an element to the rear of the queue.
- **`Dequeue()`**: Removes and returns the front element of the queue.
- **`Peek()`**: Returns the front element without removing it.
- **`freeQueue()`**: Recursively frees the memory allocated for the queue nodes.
