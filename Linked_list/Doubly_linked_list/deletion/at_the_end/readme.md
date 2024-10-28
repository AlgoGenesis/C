# Doubly Linked List - Deletion at the End

This program contains an implementation of a **Doubly Linked List** with the ability to **delete the last element** in the list.

## Node Structure

Each node in the doubly linked list consists of three parts:
1. **Data**: The value stored in the node.
2. **Next Pointer**: A reference to the next node in the list.
3. **Prev Pointer**: A reference to the previous node in the list.

## Insertion at the End

To insert a new node at the end of the doubly linked list:
- Allocate memory for the new node.
- Assign the data to the new node.
- If the list is empty, make the new node the head of the list.
- Otherwise, traverse to the last node and update its `next` pointer to point to the new node. The new node’s `prev` pointer is set to the previous last node.

## Deletion at the End

To delete the last node from the doubly linked list:
- If the list is empty, print a message indicating that there's nothing to delete.
- If the list contains only one node, free that node and set the head to `NULL`.
- Otherwise, traverse to the last node, update the second-to-last node’s `next` pointer to `NULL`, and free the last node.

## Display the List

The `display` function is used to traverse the doubly linked list and print each node's data until the end of the list is reached. The output format shows the data values of the nodes followed by a double arrow `<->`, which indicates the link between the current node and the next. The list ends with `NULL`, signifying the end of the list.

## Full Example

The complete implementation demonstrates the following functionalities:
1. **Insertion**: Nodes can be added to the end of the list.
2. **Deletion**: The last node can be removed from the list.
3. **Display**: The current state of the doubly linked list can be displayed before and after deletion operations.

## Output

When running the program, the output shows the doubly linked list before and after the deletion of the last node. For example:

- **Before Deletion**: The list might look like `10 <-> 20 <-> 30 <-> 40 <-> NULL`.
- **After Deletion**: The updated list would appear as `10 <-> 20 <-> 30 <-> NULL`.

## How to Run

To run the implementation:
1. Copy the code into a file named `doubly_linked_list.c`.
2. Compile the program using a C compiler, such as GCC.
3. Execute the compiled program.

## Key Points

- **Memory Management**: Ensure to free the memory of deleted nodes to avoid memory leaks.
- **Deletion at the End**: This implementation supports the removal of the last node in the doubly linked list.
- **Traversal**: The display function helps in visualizing the structure of the doubly linked list at any point in time, showing both the next and previous relationships.
