# Queue Implementation Using Two Stacks

## Problem Statement
A queue is a data structure that follows the First In First Out (FIFO) principle. However, it can be challenging to implement a queue using only stack operations, which follow the Last In First Out (LIFO) principle. This project implements a queue using two stacks, allowing users to perform standard queue operations like enqueue (adding an element) and dequeue (removing an element).

## Algorithm Approach
The basic idea of implementing a queue using two stacks is as follows:

1. **Two Stacks**: Use two stacks, `stack1` for enqueue operations and `stack2` for dequeue operations.
   
2. **Enqueue Operation**:
   - Push the element onto `stack1`.

3. **Dequeue Operation**:
   - If `stack2` is empty, pop all elements from `stack1` and push them onto `stack2`.
   - Pop the top element from `stack2`.

This approach effectively reverses the order of elements, allowing the first element added to `stack1` to be the first one removed from `stack2`.

## Time Complexity
- **Enqueue Operation**: O(1) – adding an element to `stack1` takes constant time.
- **Dequeue Operation**: O(n) in the worst case when transferring elements from `stack1` to `stack2`. However, the average time complexity remains O(1) for multiple dequeue operations.

## Code Overview
The following C code demonstrates how to implement a queue using two stacks. It includes functions to enqueue and dequeue elements, along with necessary stack operations.
