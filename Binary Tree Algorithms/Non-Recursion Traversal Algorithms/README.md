# Non-Recursive Binary Tree Traversal

This section describes the implementation of functions in C that performs non-recursive traversal of a binary tree. Here offers pre-order, in-order, and post-order traversals.

## Problem Statement
Given a binary tree, implement pre-order, in-order, and post-order traversals of the tree in a non-recursive manner.

## Solution
To perform non-recursive traversal of a binary tree, we utilize a stack data structure. The `StackNode` struct is essential as it allows us to keep track of the nodes during traversal. Each `StackNode` contains a pointer to a `Node` of the binary tree and a pointer to the next `StackNode`, mimicking the Last-In-First-Out (LIFO) behavior of a stack.

### 1. pre-order Traversal
In pre-order traversal, we visit the root node first, then recursively perform pre-order traversal on the left subtree, and finally on the right subtree.

**Implementation Details:**
- Initialize an empty stack and push the root node onto the stack.
- Pop a node from the stack, visit it, and push its right child followed by its left child onto the stack.
- Repeat the process until the stack is empty.

### 2. in-order Traversal
In in-order traversal, we recursively perform in-order traversal on the left subtree, visit the root node, and then recursively perform in-order traversal on the right subtree.

**Implementation Details:**
- Initialize an empty stack and set the current node to the root.
- Push all left children of the current node onto the stack until a leaf node is reached.
- Pop a node from the stack, visit it, set the current node to its right child, and repeat the process.
- If the current node is NULL and the stack is empty, the traversal is complete.

### 3. post-order Traversal
In post-order traversal, we recursively perform post-order traversal on the left subtree, then on the right subtree, and finally visit the root node.

**Implementation Details:**
- Initialize two stacks, `stack1` and `stack2`.
- Push the root node onto `stack1`.
- Pop a node from `stack1`, push it onto `stack2`, and then push its left child followed by its right child onto `stack1`.
- Repeat the process until `stack1` is empty.
- Pop nodes from `stack2` and visit them, which will be in post-order since the last nodes to be popped from `stack1` are the leftmost nodes.