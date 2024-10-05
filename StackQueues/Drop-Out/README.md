# Drop-Out Queue in C

This project implements a **Drop-Out Queue** in C using a circular buffer. The queue has a fixed size, and when it is full, new elements overwrite the oldest ones, ensuring that only the most recent elements are kept.

## Features

- **Fixed Capacity**: The queue has a fixed maximum capacity.
- **Circular Buffer**: When the queue is full, it overwrites the oldest elements, maintaining the most recent items.
- **Efficient Enqueue and Dequeue**: Insertions and deletions are performed in constant time, O(1).

## Data Structure

- **Circular Buffer**: Implements the queue as a circular array, where the front and rear pointers wrap around to the beginning when they reach the end of the array.

## Functions

- `createQueue(int capacity)`: Initializes the queue with a given capacity.
- `enqueue(DropOutQueue* queue, int item)`: Adds an item to the queue, overwriting the oldest item if the queue is full.
- `dequeue(DropOutQueue* queue)`: Removes and returns the item at the front of the queue.
- `printQueue(DropOutQueue* queue)`: Prints the current contents of the queue.

## Compilation and Usage

1. **Compile the code**:
   ```bash
   gcc -o dropout_queue dropout_queue.c
