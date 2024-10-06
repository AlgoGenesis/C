Deque: Key Concepts
Definition:

A deque (double-ended queue) is a linear data structure that allows insertion and deletion of elements from both ends (front and rear), following a First In First Out (FIFO) principle, but with greater flexibility.

Implementation:

Can be implemented using arrays or linked lists.
Uses two pointers (front and rear) to manage the ends of the deque.
Advantages:

Flexibility in managing data, allowing efficient access and modifications at both ends.
Suitable for applications that require quick access to both the front and rear elements.
Disadvantages:

Complexity in implementation compared to simple queues or stacks, especially with circular deques.
Requires careful handling of pointers to avoid confusion between empty and full states.
Applications:

Task scheduling (e.g., in operating systems).
Undo mechanisms in applications (like text editors).
Sliding window problems in algorithms.
Managing buffers in data streams.
Complexity:

Time Complexity:
Insert Front: O(1)
Insert Rear: O(1)
Delete Front: O(1)
Delete Rear: O(1)
Peek Front: O(1)
Peek Rear: O(1)
Space Complexity: O(n) for n elements in the deque.
