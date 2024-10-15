# Stack Implementation Using Linked List

## Description

A **stack** is a linear data structure that follows the Last In First Out (LIFO) principle. The most recently added element is removed first. This implementation of a stack uses a **singly linked list**. Unlike an array-based stack, a linked list-based stack does not have a fixed size, and its memory usage grows dynamically.

In this implementation:

- **Push** adds an element to the top of the stack.
- **Pop** removes and returns the element from the top of the stack.
- **Peek (Top)** returns the element on the top of the stack without removing it.
- **isEmpty** checks if the stack is empty.

## Problem Definition

The goal is to implement a stack using a linked list to perform the following operations efficiently:

1. **Push**: Insert an element onto the top of the stack.
2. **Pop**: Remove and return the top element of the stack.
3. **Peek**: View the top element without removing it.
4. **isEmpty**: Check whether the stack is empty.

### Key Operations:

- **Push Operation**: Add a new node at the beginning of the linked list.
- **Pop Operation**: Remove the node at the beginning of the linked list.
- **Peek Operation**: Return the value of the node at the beginning without removing it.
- **isEmpty Operation**: Check if the stack is empty by verifying if the head node is NULL.

## Algorithm Review

### 1. Push Operation:
- Create a new node.
- Point the new node to the current top (head) of the stack.
- Update the top pointer to the new node.

### 2. Pop Operation:
- Check if the stack is empty.
- If not, store the value of the top node.
- Update the top pointer to the next node.
- Delete the previous top node.
- Return the stored value.

### 3. Peek Operation:
- Check if the stack is empty.
- If not, return the value of the top node.

### 4. isEmpty Operation:
- If the top pointer is NULL, the stack is empty.

## Time Complexity

For all operations (push, pop, peek, isEmpty):
- **Time Complexity**: O(1)
  - Push, pop, peek, and isEmpty operations all run in constant time as they only involve pointer manipulation.

