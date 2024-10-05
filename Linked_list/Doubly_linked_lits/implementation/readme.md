# Doubly Linked List

## Definition:

A **doubly linked list** is a type of data structure where each node contains links to both the next and the previous node in the sequence. This two-way connection allows traversal in both forward and backward directions.

In a doubly linked list:

- The first node is called the **head**, and it serves as the entry point of the list.
- The last node is called the **tail**, and it points to **null (or None)** in its next pointer, indicating the end of the list.
- Nodes are connected in both directions, meaning you can traverse the list forward (from head to tail) or backward (from tail to head).

## Structure of a Node:

Each node in a doubly linked list contains:
- **Data**: Stores the actual data value.
- **Next**: A pointer to the next node in the list.
- **Previous**: A pointer to the previous node in the list.

## Operations on Doubly Linked List:

Some common operations performed on a doubly linked list include:

- **Insertion**: Adding a new node to the list (at the beginning, end, or specific position).
- **Deletion**: Removing a node from the list (by value or by position).
- **Traversal**: Visiting each node in the list in both forward and backward directions.
- **Searching**: Finding a specific node in the list by its value.
- **Reversal**: Reversing the order of the nodes in the list.

## Advantages of Doubly Linked List:

- **Bidirectional Traversal**: Allows both forward and backward traversal of the list, making it more versatile than a singly linked list.
- **Efficient Insertion/Deletion**: Inserting or deleting elements from both ends (head or tail) is efficient as it doesn't require traversing the entire list.
- **Easier Node Removal**: Given the ability to traverse backward, removing a node in a doubly linked list is easier and more efficient compared to a singly linked list, especially when deleting a specific node.

## Disadvantages of Doubly Linked List:

- **Memory Usage**: Each node requires extra memory to store both the next and previous pointers, leading to higher memory overhead compared to a singly linked list.
- **Complexity**: The additional pointer (previous) increases the complexity of operations like insertion and deletion, as both the next and previous pointers must be updated.
