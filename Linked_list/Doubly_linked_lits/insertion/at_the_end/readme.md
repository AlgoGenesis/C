# Doubly Linked List - Insertion at the End

This program contains an implementation of a **Doubly Linked List** with the ability to **insert a node at the end** of the list.

## Node Structure

Each node in a doubly linked list consists of three components:
1. **Data**: An integer value stored in the node.
2. **Next Pointer**: A reference to the next node in the list.
3. **Previous Pointer**: A reference to the previous node in the list.

## Insertion at the End

The `insertAtEnd` function allows you to add a new node to the end of the doubly linked list. The steps involved in this process are as follows:

1. **Memory Allocation**: Allocate memory for the new node.
2. **Data Assignment**: Assign the provided data to the new node.
3. **Update Next Pointer**: Set the new node's next pointer to `NULL`, as it will be the last node in the list.
4. **Check for Empty List**: 
   - If the linked list is empty (i.e., the head is `NULL`), set the new node as the head and its previous pointer to `NULL`.
5. **Traverse to the End**: 
   - If the list is not empty, traverse through the list to find the last node.
6. **Link the New Node**: 
   - Update the last node's next pointer to point to the new node.
   - Update the new node’s previous pointer to point to the last node.

## Display the List

The `display` function is used to traverse the doubly linked list and print the data of each node in the forward direction. The function starts from the head of the list and continues until the end (i.e., when the next pointer is `NULL`). The output format shows the data values of the nodes followed by an arrow, ending with `NULL` to indicate the end of the list.

## Full Example

The complete implementation demonstrates the following functionalities:
1. **Insertion**: Nodes can be added to the end of the list.
2. **Display**: The current state of the doubly linked list can be displayed.

### Example Output

When running the program, the output will display the doubly linked list after inserting nodes at the end.
 
For example:
10 -> 20 -> 30 -> 40 -> NULL