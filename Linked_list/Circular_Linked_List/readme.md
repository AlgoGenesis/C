# Circular Linked Lists

## Circular Singly Linked List

### Definition
A **Circular Singly Linked List** is a type of linked list where the last node points back to the first node, creating a circular structure. Each node contains two parts:

- **Data**: The value or information stored in the node.
- **Next Pointer**: A reference (or pointer) to the next node in the sequence.

### Structure of a Node
Each node in a circular singly linked list contains:
- **Data**: Stores the actual data value.
- **Next**: A pointer to the next node in the list.

### Operations on Circular Singly Linked List
Common operations include:
1. **Insertion**: Adding a new node (at the beginning, end, or specific position).
2. **Deletion**: Removing a node (by value or by position).
3. **Traversal**: Visiting each node starting from the head and continuing until returning to the head.
4. **Searching**: Finding a specific node by its value.
5. **Reversal**: Reversing the order of nodes (less common).

### Advantages
- **No Null References**: Continuous traversal without null references.
- **Dynamic Size**: Can grow or shrink dynamically.
- **Efficient Insertions/Deletions**: More efficient than arrays for certain operations.

### Disadvantages
- **Complexity**: Managing circularity can complicate logic.
- **No Backward Traversal**: Cannot traverse in reverse.

---

## Circular Doubly Linked List

### Definition
A **Circular Doubly Linked List** is a type of linked list where each node contains pointers to both the next and previous nodes, and the last node points back to the first node. This allows traversal in both directions.

### Structure of a Node
Each node in a circular doubly linked list contains:
- **Data**: Stores the actual data value.
- **Next**: A pointer to the next node in the list.
- **Prev**: A pointer to the previous node in the list.

### Operations on Circular Doubly Linked List
Common operations include:
1. **Insertion**: Adding a new node (at the beginning, end, or specific position).
2. **Deletion**: Removing a node (by value or by position).
3. **Traversal**: Visiting each node in both forward and backward directions.
4. **Searching**: Finding a specific node by its value.
5. **Reversal**: Reversing the order of nodes.

### Advantages
- **Bidirectional Traversal**: Can traverse in both forward and backward directions.
- **Dynamic Size**: Can grow or shrink dynamically.
- **Efficient Insertions/Deletions**: Efficient for operations at both ends and in the middle.

### Disadvantages
- **More Memory Usage**: Requires more memory for storing an additional pointer.
- **Complexity**: More complex implementation compared to singly linked lists.
