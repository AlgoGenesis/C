
# Heap Implementation in C

This document provides a detailed explanation of a max-heap data structure implemented in C. This implementation includes functions to insert, remove, and retrieve the maximum element, along with other utility functions.

## Code Overview

This code defines a struct `max_heap` which is used to represent a max-heap. A max-heap is a complete binary tree in which each node is greater than or equal to its child nodes. The implementation uses an array for efficient indexing.

### Struct Definition
```c
typedef struct max_heap {
    int *p;
    int size;
    int count;
} Heap;
```
- `p`: Pointer to an array representing the heap.
- `size`: Current allocated size of the array.
- `count`: Current number of elements in the heap.

### Functions

#### 1. `create_heap(Heap *heap)`
Creates a new max-heap with an initial capacity of 2. Returns a pointer to the heap structure.

#### 2. `down_heapify(Heap *heap, int index)`
Restores the max-heap property by moving the element at the given `index` downwards.

#### 3. `up_heapify(Heap *heap, int index)`
Moves the element at the given `index` upwards to maintain the max-heap property.

#### 4. `push(Heap *heap, int x)`
Inserts a new element `x` into the heap. Resizes the heap array if the current capacity is reached.

#### 5. `pop(Heap *heap)`
Removes the top (maximum) element from the heap and reorders the remaining elements.

#### 6. `top(Heap *heap)`
Returns the maximum element in the heap. Returns `INT_MIN` if the heap is empty.

#### 7. `empty(Heap *heap)`
Checks if the heap is empty.

#### 8. `size(Heap *heap)`
Returns the number of elements currently in the heap.

### Example Usage

```c
Heap *head = create_heap(head);
push(head, 10);
push(head, 3);
push(head, 2);
push(head, 8);
printf("Top element = %d 
", top(head));
pop(head);
printf("After popping, Top element = %d 
", top(head));
```

### Complexity Analysis

#### Time Complexity

| Operation | Time Complexity |
|-----------|-----------------|
| `push`    | O(log n)        |
| `pop`     | O(log n)        |
| `top`     | O(1)            |

- `push` and `pop` involve heapification, which takes `O(log n)` time as elements are moved up or down in the heap.
- `top` is `O(1)` because it only retrieves the maximum element.

#### Space Complexity
- The space complexity is `O(n)`, where `n` is the number of elements in the heap. Additional memory is used only if the array needs to be resized.

### Notes
- The max-heap property is maintained by comparing elements while inserting or deleting nodes.
- Dynamic resizing allows efficient memory usage while maintaining performance.

## Conclusion

This implementation provides efficient methods for a max-heap in C, ideal for priority queue operations where fast access to the maximum element is required.

