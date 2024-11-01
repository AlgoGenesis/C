#Definition

In C, a priority queue is a special type of queue where each element has a priority associated with it. Elements with higher priority are served before elements with lower priority. If two elements have the same priority, they are served based on their order in the queue (depending on whether it's a min-heap or max-heap).

A priority queue can be implemented in various ways, but one of the most efficient implementations is using a binary heap:
    Max-Heap: In a max-heap, the element with the highest priority (maximum value) is at the root of the heap, making it easy to access and remove.
    Min-Heap: In a min-heap, the element with the lowest priority (minimum value) is at the root.

#Operations in a Priority Queue
    Insert (Enqueue): Insert an element into the priority queue while maintaining the heap property.
    Remove (Dequeue): Remove the element with the highest priority (root element in a max-heap or min-heap).
    Peek: Access the highest-priority element without removing it.
    
#Explanation of Code
    enqueue: Inserts a new element at the end of the heap array and then "bubbles up" to restore the min-heap property.
    dequeue: Removes the root (smallest) element and replaces it with the last element in the array, then "bubbles down" to maintain the min-heap.
    peek: Returns the highest-priority element without removing it.

#Complexity Analysis
    Insertion (enqueue): O(log⁡n)O(logn) because it may require "bubbling up."
    Deletion (dequeue): O(log⁡n)O(logn) due to "bubbling down."
    Peek: O(1)O(1) since the root is always the highest-priority element.

This implementation offers a simple, efficient way to manage a priority queue in C using a min-heap.
