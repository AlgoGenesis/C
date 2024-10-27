# Min-Heap Implementation in C

This repository contains an implementation of a Min-Heap in C. A **Min-Heap** is a binary tree where the value of each parent node is less than or equal to the values of its children, ensuring that the minimum element is always at the root.

## Features
- **Insert elements (push)**
- **Remove the minimum element (pop)**
- **Retrieve the minimum element (top)**
- **Check if the heap is empty (empty)**
- **Get the current size of the heap (size)**

## How It Works
The Min-Heap is represented as an array, and we maintain the heap property by using **up-heapify** and **down-heapify** methods:
- **up_heapify()** is used when a new element is inserted, to move it to its correct position by comparing it with its parent.
- **down_heapify()** is used when the root element is removed, to restore the heap property by moving elements downwards.

## Functions Overview

1. **create_heap(Heap *heap)**:  
   Initializes a new heap with an initial capacity of 2.

2. **push(Heap *heap, int x)**:  
   Inserts a new element into the heap. If the heap reaches its capacity, it automatically resizes.

3. **pop(Heap *heap)**:  
   Removes the minimum element (root) from the heap and reorders the heap.

4. **top(Heap *heap)**:  
   Retrieves the minimum element in the heap without removing it. If the heap is empty, it returns `INT_MAX`.

5. **empty(Heap *heap)**:  
   Returns `1` if the heap is empty, otherwise returns `0`.

6. **size(Heap *heap)**:  
   Returns the current number of elements in the heap.

## How to Use

1. Clone the repository:
    ```bash
    git clone https://github.com/your-repo-url/min-heap-c.git
    ```

2. Compile the program using any C compiler. For example, with `gcc`:
    ```bash
    gcc -o min_heap min_heap.c
    ```

3. Run the program:
    ```bash
    ./min_heap
    ```

## Example

```c
int main() {
    Heap *head = create_heap(head);
    push(head, 10);
    printf("Pushing element : 10\n");
    push(head, 3);
    printf("Pushing element : 3\n");
    push(head, 2);
    printf("Pushing element : 2\n");
    push(head, 8);
    printf("Pushing element : 8\n");
    printf("Top element = %d \n", top(head));  // Outputs: 2
    push(head, 1);
    printf("Pushing element : 1\n");
    push(head, 7);
    printf("Pushing element : 7\n");
    printf("Top element = %d \n", top(head));  // Outputs: 1
    pop(head);
    printf("Popping an element.\n");
    printf("Top element = %d \n", top(head));  // Outputs: 2
    pop(head);
    printf("Popping an element.\n");
    printf("Top element = %d \n", top(head));  // Outputs: 3
    return 0;
}
```

## Memory Management
The heap dynamically resizes based on the number of elements. It grows when more elements are added and shrinks when enough elements are removed to free unused memory.

## Requirements
- C compiler (e.g., GCC)
- Standard C libraries

## Use Cases of Min-Heap
A Min-Heap is a fundamental data structure with several practical applications in computer science. Here are some common use cases:

## Priority Queues:

Use Case: Min-Heaps are commonly used to implement priority queues where the element with the smallest value has the highest priority.
Example: In a job scheduling system, tasks with the lowest time requirement might be prioritized and processed first. Using a Min-Heap, the scheduler can efficiently extract the next task to process.

## Dijkstra’s Shortest Path Algorithm:

Use Case: Min-Heaps are used in Dijkstra’s algorithm to find the shortest paths from a source node to all other nodes in a graph.
Example: In a navigation system like Google Maps, a Min-Heap can help find the shortest route between locations by always expanding the node with the smallest distance first.

## Heap Sort:

Use Case: Min-Heaps can be used for sorting an array in ascending order.
Example: By inserting all elements into a Min-Heap and then extracting them one by one, the result is a sorted list of elements in ascending order.

## Finding the K Smallest/Largest Elements:

Use Case: Min-Heaps are used to find the K smallest or K largest elements in a collection.
Example: In a large dataset of student grades, a Min-Heap can help find the top K students with the highest scores by maintaining a heap of size K for the largest elements.

## Merging Multiple Sorted Arrays:

Use Case: Min-Heaps can efficiently merge multiple sorted arrays into a single sorted array.
Example: In external sorting (used when data is too large to fit into memory), Min-Heaps help merge sorted chunks of data.

## Event Simulation Systems:

Use Case: Min-Heaps are useful in event-driven simulation systems to determine the next event to process.
Example: In a network packet simulation, events might include packet arrivals or departures. A Min-Heap can be used to process events based on their timestamps, ensuring the simulation proceeds in chronological order.
---
