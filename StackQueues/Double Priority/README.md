# Double Priority Queue in C

This project implements a **Double Priority Queue** in C using **two heaps**: a min-heap to manage the smallest elements and a max-heap to manage the largest elements. It allows efficient retrieval and removal of both the minimum and maximum elements.

## Features

- **Efficient Insertions and Removals**: Inserting into the queue and removing the minimum or maximum element are efficient operations, performed in logarithmic time.
- **Dynamic Data Structure**: Supports dynamic insertion and removal of elements while maintaining order.

## Data Structure

- **Min-Heap**: Tracks the smallest element for fast `removeMin()` operation.
- **Max-Heap**: Tracks the largest element for fast `removeMax()` operation.

## How It Works

- Each element is inserted into both the min-heap and the max-heap.
- When the minimum element is removed, it is extracted from the min-heap, and when the maximum element is removed, it is extracted from the max-heap.

## Functions

- `insert(int value)`: Inserts an element into both heaps.
- `removeMin()`: Removes and returns the smallest element.
- `removeMax()`: Removes and returns the largest element.

## Compilation and Usage

1. **Compile the code**:
   ```bash
   gcc -o double_priority_queue double_priority_queue.c
