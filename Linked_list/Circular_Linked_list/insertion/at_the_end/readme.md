# Circular Linked List - Insertion at the End

This program contains an implementation of a **Circular Linked List** with the ability to **insert a node at the end** of the list.

## Node Structure

Each node in the Circular linked list consists of two components:
1. **Data**: An integer value stored in the node.
2. **Next Pointer**: A reference to the next node in the linked list.

## Insertion at the End

The `insertAtEnd` function allows you to add a new node to the end of the linked list. The steps involved in this process are as follows:

1. **Memory Allocation**: Allocate memory for the new node.
2. **Data Assignment**: Assign the provided data to the new node.
3. **Check for Empty List**:
   -If list is empty, new node becomes the head and points to itself.
4. **Traverse till the last node**: 
   - If the list is not empty, traverse to the last node.
5. **Add the New Node**:
   - Update the last node’s next pointer to point to the new node.
6. **Update Next Pointer**: Set the new node's next pointer to `head`.
   
## Display the List

The `display` function is used to traverse the linked list and print the data of each node. It continues until the end of the list is reached (i.e., when the next pointer is `head` again). The output format shows the data values of the nodes followed by an arrow, ending with `back to head` to indicate the end of the list.

## Full Example

The complete implementation demonstrates the following functionalities:
1. **Insertion**: Nodes can be added to the end of the list.
2. **Display**: The current state of the linked list can be displayed.

### Example Output

When running the program, the output will display the linked list after inserting nodes at the end.
 
For example:
10 -> 20 -> 30 -> 40 -> (back to head)


