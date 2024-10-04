# Singly Linked List - Deletion at the End

This program contains an implementation of a **Singly Linked List** with the ability to **delete the last element** in the list.

## Node Structure

Each node in the singly linked list consists of two parts:
1. **Data**: The value stored in the node.
2. **Next Pointer**: A reference to the next node in the list.

## Insertion at the End

To insert a new node at the end of the linked list:
- Allocate memory for the new node.
- Assign the data to the new node.
- If the list is empty, make the new node the head of the list.
- Otherwise, traverse to the last node and update the last node’s next pointer to point to the new node.

## Deletion at the End

To delete the last node from the linked list:
- If the list is empty, print a message indicating that there's nothing to delete.
- If the list contains only one node, free that node and set the head to `NULL`.
- Otherwise, traverse to the second-to-last node and update its next pointer to `NULL`, then free the last node.

## Display the List

The `display` function is used to traverse the linked list and print each node's data until the end of the list is reached. The output is presented in a readable format, showing the data values of the nodes followed by an arrow to indicate the link to the next node, ending with `NULL` to signify the end of the list.

## Full Example

The complete implementation demonstrates the following functionalities:
1. **Insertion**: Nodes can be added to the end of the list.
2. **Deletion**: The last node can be removed from the list.
3. **Display**: The current state of the linked list can be displayed before and after deletion operations.

## Output

When running the program, the output shows the linked list before and after the deletion of the last node. For example:

- **Before Deletion**: The list might look like `10 -> 20 -> 30 -> 40 -> NULL`.
- **After Deletion**: The updated list would appear as `10 -> 20 -> 30 -> NULL`.

## How to Run

To run the implementation:
1. Copy the code into a file named `singly_linked_list.c`.
2. Compile the program using a C compiler, such as GCC.
3. Execute the compiled program.

## Key Points

- **Memory Management**: Ensure to free the memory of deleted nodes to avoid memory leaks.
- **Deletion at the End**: This implementation supports the removal of the last node in the linked list.
- **Traversal**: The display function helps in visualizing the structure of the linked list at any point in time.
