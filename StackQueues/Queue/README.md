Queue: Key Concepts
Definition:

A queue is a linear data structure that follows the First In First Out (FIFO) principle, meaning the first element added is the first to be removed.

Implementation:

Can be implemented using arrays or linked lists.
Array-based queues have a fixed size, while linked-list queues can grow dynamically.
Types of Queues:

Simple Queue: Basic FIFO queue.
Circular Queue: Connects the end of the queue back to the front, allowing efficient use of space.
Priority Queue: Elements are dequeued based on priority rather than order of arrival.
Double-Ended Queue (Deque): Allows insertion and deletion from both ends.
Applications:

Task scheduling (in operating systems).
Managing requests in web servers (queue of requests).
Breadth-first search (BFS) in graph algorithms.
Print job management (spooling).
Advantages:

Efficient for managing and processing tasks in order.
Suitable for handling data in a sequential manner.
Disadvantages:

Limited size in array-based implementations (risk of overflow).
Requires extra memory for pointers in linked-list implementations.
Inefficient access to elements in the middle of the queue.
Complexity:

Time Complexity:
Enqueue: O(1)
Dequeue: O(1)
Front: O(1)
Space Complexity: O(n) for n elements in the queue.
