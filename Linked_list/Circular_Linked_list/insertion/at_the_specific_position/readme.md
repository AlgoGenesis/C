# Circluar Linked List - Insertion at a Specific Position

This program contains an implementation of a **Circular Linked List** with the ability to **insert a node at a specific position** within the list.

## Node Structure

Each node in the singly linked list consists of two components:
1. **Data**: An integer value stored in the node.
2. **Next Pointer**: A reference to the next node in the linked list.

## Insertion at a Specific Position

The `insertAtPosition` function allows you to add a new node at a specified position in the linked list. The steps involved in this process are as follows:

1. **Memory Allocation**: Allocate memory for the new node.
2. **Data Assignment**: Assign the provided data to the new node.
3. **Check for Empty list**: If the list is empty, make the new node the head of the list.
4. **Insertion at beginning**: Navigate through the list to find the node that precedes the desired insertion position.
5. **Check Validity**: If the specified position is beyond the current length of the list, print an error message.
6. **Insert the Node**: Adjust the pointers to insert the new node at the desired position.

## Display the List

The `display` function is used to traverse the linked list and print the data of each node. It continues until the end of the list is reached (i.e., when the next pointer is `NULL`). The output format shows the data values of the nodes followed by an arrow, ending with `NULL` to indicate the end of the list.

## Full Example

The complete implementation demonstrates the following functionalities:
1. **Insertion**: Nodes can be added at specific positions in the list.
2. **Display**: The current state of the linked list can be displayed.

### Example Output

When running the program, the output will display the circular linked list after inserting nodes at various positions. 

For example: 50 -> 10 -> 40 -> 20 -> 30 -> (Back to head)
