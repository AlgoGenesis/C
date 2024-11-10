# Explanation

Two Stacks (stack1 and stack2): stack1 is used for enqueue operations, while stack2 is used for dequeue operations.
Enqueue Operation: Pushes the element onto stack1.
Dequeue Operation: If stack2 is empty, all elements from stack1 are transferred to stack2, reversing their order to maintain the FIFO property. The top element of stack2 is then popped to simulate dequeue.
Display Operation: Prints elements in stack2 from top to bottom (front of the queue) followed by stack1 from bottom to top (end of the queue).

# Complexity

Time Complexity:
Enqueue:
𝑂
(
1
)
O(1)
Dequeue:
𝑂
(
𝑛
)
O(n) in the worst case (when transferring elements between stacks)
Space Complexity:
𝑂
(
𝑛
)
O(n) where
𝑛
n is the total number of elements in the queue.
This approach ensures that the queue behaves like a circular queue when combined with proper logic for handling full and empty cases.
