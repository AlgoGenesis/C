# Insertion Operation
Insertion at the end of the list: The new node is added after the last node, and the new node’s next pointer is set to the head of the list.

# Algorithm Description
The Insertion Algorithm follows these steps:

# Create a new node:
Allocate memory dynamically for a new node.
Assign the given data to the new node.
Set the new node’s next pointer to the head (as it's a circular list).

# If the list is empty:
The new node becomes the head node.
The new node’s next pointer points to itself, maintaining the circular structure.

# If the list is not empty:
Traverse the list to find the last node (the node whose next pointer points to the head).
Update the last node’s next pointer to point to the new node.
Set the new node’s next pointer to the head, preserving the circular nature of the list.
