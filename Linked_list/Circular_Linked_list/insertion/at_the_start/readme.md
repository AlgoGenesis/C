# Circular Linked List - Insertion at the Beginning

This program contains an implementation of a **SCircular Linked List** with the ability to **insert a node at the beginning** of the list.

## Node Structure

Each node in the singly linked list consists of two components:
1. **Data**: An integer value stored in the node.
2. **Next Pointer**: A reference to the next node in the linked list.

## Insertion at the Beginning

The `insertAtStart` function allows you to add a new node to the beginning of the linked list. The steps involved in this process are as follows:

1. **Memory Allocation**: Allocate memory for the new node.
2. **Data Assignment**: Assign the provided data to the new node.
3. **Update Next Pointer**: Make the new node point to the current head of the list (the first node).
4. **Update Head**: Move the head of the list to point to the new node, effectively making it the first node.

## Display the List

The `display` function is used to traverse the linked list and print the data of each node. It continues until the end of the list is reached (i.e., when the next pointer is `NULL`). The output format shows the data values of the nodes followed by an arrow, ending with `NULL` to indicate the end of the list.

## Full Example

The complete implementation demonstrates the following functionalities:
1. **Insertion**: Nodes can be added to the beginning of the list.
2. **Display**: The current state of the linked list can be displayed.

### Example Output

When running the program, the output will display the linked list after inserting nodes at the beginning. 

For example: 10 -> 20 -> 30 -> 40 -> NULL

