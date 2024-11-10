 # Two Stacks to Implement a Queue

This project demonstrates how to implement a queue using two stacks in the C programming language. A queue follows the First-In-First-Out (FIFO) principle, while a stack follows the Last-In-First-Out (LIFO) principle. By using two stacks, we can simulate the behavior of a queue.

## Problem Explanation

The goal is to create a queue using two stacks (`stack1` and `stack2`). The queue will support two main operations:
1. **Enqueue (push)** - Adds an element to the end of the queue.
2. **Dequeue (pop)** - Removes an element from the front of the queue.

### Solution Approach

1. **Enqueue Operation**:
   - Push the new element onto `stack1`.

2. **Dequeue Operation**:
   - If `stack2` is empty, transfer all elements from `stack1` to `stack2`. This reverses the order, so the oldest element is at the top of `stack2`.
   - Pop the top element from `stack2`, which is the front of the queue.

## Code Implementation

The program is written in C, with a `QueueUsingStacks` structure that contains two stacks (`stack1` and `stack2`).

### Files
- `queue_using_stacks.c`: Contains the main code for the queue implementation.

## Usage

1. Clone this repository or download the `queue_using_stacks.c` file.
2. Compile the code:
   ```bash
   gcc queue_using_stacks.c -o queue_using_stacks

