# Singly Linked List - Deletion at the Start

This program contains an implementation of a **Singly Linked List** with the ability to **delete a node at the start** of the list.

## Node Structure

Each node in the singly linked list consists of two components:
1. **Data**: The integer value stored in the node.
2. **Next Pointer**: A reference to the next node in the linked list.

## Insertion at the End

To add a new node at the end of the linked list:
- Allocate memory for the new node.
- Assign the provided data to the new node.
- If the list is empty, the new node becomes the head.
- Otherwise, traverse to the end of the list and update the last node’s next pointer to point to the new node.

## Deletion at the Start

To delete a node at the start of the linked list:
- If the list is empty, print a message indicating that there's nothing to delete.
- Store a reference to the current head node.
- Update the head pointer to point to the next node.
- Free the memory of the old head node.

## Display the List

The `display` function is used to traverse the linked list and print each node's data until the end of the list is reached. The output format shows the data values of the nodes followed by an arrow, ending with `NULL` to indicate the end of the list.

## Full Example

The complete implementation demonstrates the following functionalities:
1. **Insertion**: Nodes can be added to the end of the list.
2. **Deletion**: A node can be removed from the start of the list.
3. **Display**: The current state of the linked list can be displayed before and after deletion operations.

## Output

When running the program, the output shows the linked list before and after the deletion of the first node. For example:

- **Before Deletion**: The list might look like `10 -> 20 -> 30 -> 40 -> NULL`.
- **After Deletion at Start**: The updated list would appear as `20 -> 30 -> 40 -> NULL`.

## How to Run

To run the implementation:
1. Copy the code into a file named `singly_linked_list.c`.
2. Compile the program using a C compiler, such as GCC.
3. Execute the compiled program.

## Key Points

- **Memory Management**: Ensure to free the memory of deleted nodes to avoid memory leaks.
- **Deletion at the Start**: This implementation supports the removal of a node from the start of the linked list.
- **Traversal**: The display function helps in visualizing the structure of the linked list at any point in time.
