# Blocking Queue in C

This project implements a **Blocking Queue** in C, which allows safe concurrent access by multiple threads. The queue blocks enqueue operations when it is full and blocks dequeue operations when it is empty, making it ideal for producer-consumer scenarios.

## Features

- **Thread-Safe**: Uses mutexes and condition variables to ensure safe access from multiple threads.
- **Blocking Operations**: Automatically blocks enqueue and dequeue operations based on the queue state.
- **Circular Buffer**: Implements the queue as a circular buffer for efficient memory usage.

## Data Structure

- **Circular Buffer**: The underlying structure is a fixed-size circular buffer, allowing efficient reuse of space.

## Functions

- `createQueue(int capacity)`: Initializes the Blocking Queue with a given capacity.
- `enqueue(BlockingQueue* queue, int item)`: Adds an item to the queue; blocks if the queue is full.
- `dequeue(BlockingQueue* queue)`: Removes and returns the item at the front of the queue; blocks if the queue is empty.
- `destroyQueue(BlockingQueue* queue)`: Frees resources associated with the queue.

## Compilation and Usage

1. **Compile the code**:
   ```bash
   gcc -o blocking_queue blocking_queue.c -lpthread
