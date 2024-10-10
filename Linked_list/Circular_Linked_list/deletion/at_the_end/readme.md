# Circular Linked List - Deletion from the End

This program contains an implementation of a **Circular Linked List** with the ability to **delete a node from the end** of the list.

## Node Structure

Each node in the singly linked list consists of two components:
1. **Data**: The integer value stored in the node.
2. **Next Pointer**: A reference to the next node in the linked list.

## Insertion at the End

To add a new node at the end of the linked list:
- Allocate memory for the new node.
- Assign the provided data to the new node.
- If the list is empty, the new node becomes the head.
- Otherwise, traverse to the last node of the list and update the last node’s next pointer to point to the new node. Then, set the new node pointer to point at head.

## Deletion from the End

To delete a node at the start of the linked list:
- If the list is empty, print a message indicating that list is empty and there is nothing to delete.
- If the list has only single element, free the node and set the head to `NULL`.
- Store a reference to the current head node in temp and prev as NULL.
- Traverse the list to the second last node and update the second last node's pointer to the head.
- Free the memory of the last node.

## Display the List

The `display` function traverses the linked list and prints the data of each node. It continues until the end of the list is reached (i.e., when the next pointer points to the `head` again after printing the complete list). The output format shows the data values of the nodes followed by an arrow, ending with `Back to head` to indicate the end of the list i.e., again pointing to the start of list (head).


## Full Example

The complete implementation demonstrates the following functionalities:
1. **Insertion**: Nodes can be added to the end of the list.
2. **Deletion**: A node can be removed from the start of the list.
3. **Display**: The current state of the linked list can be displayed before and after deletion operations.

## Output

When running the program, the output shows the linked list before and after the deletion of the first node. For example:

- **Original List**:
10 -> 20 -> 30 -> 40 -> (Back to head)

- **Deleting from the end...**:

  List after deletion from the end:
10 -> 20 -> 30 -> (Back to head)


## How to Run

To run the implementation:
1. Copy the code into a file named `circular_linked_list.c`.
2. Compile the program using a C compiler, such as GCC.
3. Execute the compiled program.

## Key Points

- **Memory Management**: Ensure to free the memory of deleted nodes to avoid memory leaks.
- **Deletion at the Start**: This implementation supports the removal of a node from the end of the linked list.
- **Traversal**: The display function helps in visualizing the structure of the linked list at any point in time.
