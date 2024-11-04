# Definition

In C, a priority queue is a special type of queue where each element has a priority associated with it. Elements with higher priority are served before elements with lower priority. If two elements have the same priority, they are served based on their order in the queue (depending on whether it's a min-heap or max-heap).

A priority queue can be implemented in various ways, but one of the most efficient implementations is using a binary heap:
1) Max-Heap: In a max-heap, the element with the highest priority (maximum value) is at the root of the heap, making it easy to access and remove.
2) Min-Heap: In a min-heap, the element with the lowest priority (minimum value) is at the root.

# Operations in a Priority Queue
1) Insert (Enqueue): Insert an element into the priority queue while maintaining the heap property.
2) Remove (Dequeue): Remove the element with the highest priority (root element in a max-heap or min-heap).
3) Peek: Access the highest-priority element without removing it.

   
    
# Explanation of Code
1) enqueue: Inserts a new element at the end of the heap array and then "bubbles up" to restore the min-heap property.
2) dequeue: Removes the root (smallest) element and replaces it with the last element in the array, then "bubbles down" to maintain the min-heap.
3) peek: Returns the highest-priority element without removing it.

# Complexity Analysis
1) Insertion (enqueue): O(logn) because it may require "bubbling up."
2) Deletion (dequeue): O(logn) due to "bubbling down."
3) Peek: O(1) since the root is always the highest-priority element.

This implementation offers a simple, efficient way to manage a priority queue in C using a min-heap.
