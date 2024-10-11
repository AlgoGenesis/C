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
4. **Handle insertion at the beginning case**: Traverse through the list and sets the next of new node to head and last node's next to new node. Finally update the new node as head.
5. **Check Validity**: Traverse the list(using current node) to the position where the node is to be placed.
6. **Insert the Node**: Set the next of new node to current's next then current's next to new node.

## Display the List

The `display` function traverses the linked list and prints the data of each node. It continues until the end of the list is reached (i.e., when the next pointer points to the `head` again after printing the complete list). The output format shows the data values of the nodes followed by an arrow, ending with `Back to head` to indicate the end of the list i.e., again pointing to the start of list (head).

## Full Example

The complete implementation demonstrates the following functionalities:
1. **Insertion**: Nodes can be added at specific positions in the list.
2. **Display**: The current state of the linked list can be displayed.

### Example Output

When running the program, the output will display the circular linked list after inserting nodes at various positions. 

For example: 
Circular Linked List after insertions at specified positions:
10 -> 40 -> 20 -> 30 -> (Back to head)
