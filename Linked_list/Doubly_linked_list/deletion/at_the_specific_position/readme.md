# Doubly Linked List - Deletion at a Specific Position

This program contains an implementation of a **Doubly Linked List** with the ability to **delete a node at a specific position** in the list.

## Node Structure

Each node in the doubly linked list consists of three components:
1. **Data**: The integer value stored in the node.
2. **Next Pointer**: A reference to the next node in the linked list.
3. **Previous Pointer**: A reference to the previous node in the linked list.

## Insertion at the End

To add a new node at the end of the doubly linked list:
- Allocate memory for the new node.
- Assign the provided data to the new node.
- If the list is empty, the new node becomes the head.
- Otherwise, traverse to the end of the list and update the last node’s next pointer to point to the new node and set the new node’s previous pointer to the last node.

## Deletion at a Specific Position

To delete a node at a specific position in the linked list:
- If the list is empty, print a message indicating that there's nothing to delete.
- If the position to delete is `1`, update the head to point to the next node, free the old head, and set the new head's previous pointer to `NULL`.
- Traverse the list to find the node just before the position to be deleted.
- If the position is greater than the number of nodes, print a message indicating that the position is invalid.
- If the position is valid, unlink the node from the list, update the next and previous pointers accordingly, and free its memory.

## Display the List

The `display` function is used to traverse the doubly linked list and print each node's data until the end of the list is reached. The output format shows the data values of the nodes followed by `<->` to indicate the links between nodes, ending with `NULL` to indicate the end of the list.

## Full Example

The complete implementation demonstrates the following functionalities:
1. **Insertion**: Nodes can be added to the end of the list.
2. **Deletion**: A node can be removed from a specific position in the list.
3. **Display**: The current state of the linked list can be displayed before and after deletion operations.

## Output

When running the program, the output shows the linked list before and after the deletion of a node at a specific position. For example:

- **Before Deletion**: The list might look like `10 <-> 20 <-> 30 <-> 40 <-> NULL`.
- **After Deletion at Position 2**: The updated list would appear as `10 <-> 30 <-> 40 <-> NULL`.

## How to Run

To run the implementation:
1. Copy the code into a file named `doubly_linked_list.c`.
2. Compile the program using a C compiler, such as GCC.
3. Execute the compiled program.

## Key Points

- **Memory Management**: Ensure to free the memory of deleted nodes to avoid memory leaks.
- **Deletion at a Specific Position**: This implementation supports the removal of a node from any valid position in the doubly linked list.
- **Traversal**: The display function helps in visualizing the structure of the linked list at any point in time.
