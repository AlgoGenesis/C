# Optimal merge problem

# Overview

This program uses a min-heap data structure to compute the minimum cost of combining elements from an array. The minimum cost is obtained bt repeatedly combinig the two smallest elements until one element remains.

# Data Structure

- Minheap: A structure that holds:
  -- array: A pointer to integer array that represents the heap.
  -- capacity: The maximum number of elements the heap can hold.
  -- size: The current number of elements in the heap.

- Functions:

1. MinHeap createMinHeap(int capacity)\*: Returns a pointer o the newly created Minheap.

2. void swap(int x,int y): swap the values of two integers.
3. void minHeapify(MinHeap minHeap, int idx):This function checks the current node and its children to ensure the smallest value is at the root.
4. void insertMinHeap(MinHeap minHeap,int element): Add the elements at the end and fixes the min-heap property by moving it up the tree.
5. int extractMin(MinHeap minHeap): Repalces the root with the last element , reduces the size and heapify down.

# Memory Management

- Dynamic memory allocation
- Freeing memory
