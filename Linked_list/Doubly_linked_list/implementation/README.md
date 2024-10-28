# Doubly Linked List

## Definition

A **doubly linked list** is a data structure consisting of a sequence of nodes, where each node contains three parts:

1. **Data**: The value or information stored in the node.
2. **Next Pointer**: A reference (or pointer) to the next node in the sequence.
3. **Previous Pointer**: A reference (or pointer) to the previous node in the sequence.

### Characteristics:

- The first node is called the **head**, and it serves as the entry point of the list.
- The last node points to **null (or `NULL`)** in its next pointer, indicating the end of the list.
- Unlike a singly linked list, each node in a doubly linked list points to both its **next** and **previous** nodes, allowing traversal in both directions (forward and backward).

## Structure of a Node:

Each node in a doubly linked list contains:
- **Data**: Stores the actual data value.
- **Next**: A pointer to the next node in the list.
- **Prev**: A pointer to the previous node in the list.

## Operations on Doubly Linked List

Common operations performed on a doubly linked list include:

- **Insertion**: Adding a new node to the list at the beginning, end, or a specific position.
- **Deletion**: Removing a node from the list by value or by position.
- **Traversal**: Visiting each node in the list from the head to the end (forward traversal) or from the end to the head (backward traversal).
- **Searching**: Finding a specific node in the list by its value.
- **Reversal**: Reversing the order of nodes in the list.

## Advantages of Doubly Linked List

- **Bidirectional Traversal**: You can traverse the list both forward and backward, which is not possible in a singly linked list.
- **Efficient Deletions**: It is easier to delete a node from the list since each node has a pointer to the previous node.
- **Dynamic Size**: Like a singly linked list, a doubly linked list can grow or shrink dynamically as elements are added or removed.

## Disadvantages of Doubly Linked List

- **More Memory Usage**: Each node requires extra memory for storing both the next and previous pointers.
- **Complexity**: Doubly linked lists require more operations to manage the two pointers compared to singly linked lists, making them more complex to implement.
