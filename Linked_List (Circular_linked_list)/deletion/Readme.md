# Circular Linked List Deletion in C
## Overview
This program implements the deletion of a node from a circular linked list in the C programming language. It also includes a function to display the contents of the list.

## How it Works
A circular linked list is a linked list where the last node points back to the head, forming a circle. This program provides functions to:

Delete a node with a specified key from the circular linked list.
Display the circular linked list.

## Key Operations
Delete Node: Deletes the node containing the specified data key from the circular linked list.
Display List: Prints all the elements of the circular linked list starting from the head and loops back when it reaches the last node.

## Functions

### 1. Delete Node
This function deletes a node with the specified data key from the circular linked list.

#### Parameters:
head: Double pointer to the head node of the circular linked list.
key: The data value of the node to be deleted.
#### Functionality:
If the list is empty, it displays a message: "List is empty."

If the node to be deleted is the head and it's the only node, the list becomes empty after deletion.

If the head node needs to be deleted but there are more nodes, the head is updated to the next node, and the last node's pointer is updated accordingly.

For other nodes, it searches for the node with the specified key and deletes it by adjusting the pointers of the neighboring nodes.

#### Example:
deleteNode(&head, 3);

Deletes the node containing the value 3 from the circular linked list.

### 2.display(struct Node* head)
This function displays the contents of the circular linked list.

#### Parameters:
head: Pointer to the head node of the circular linked list.
#### Functionality:
If the list is empty, it displays a message: "List is empty."

It prints each node's data in a circular fashion, showing that the last node points back to the head.
#### Example:

display(head);
Displays the current nodes in the list.

## Sample Output
Assuming the circular linked list contains the values 1 -> 2 -> 3 -> 4 -> (Back to head):

### Before Deletion:

1 -> 2 -> 3 -> 4 -> (Back to head)

### After deleting node with key = 3:

1 -> 2 -> 4 -> (Back to head)

### After deleting node with key = 1 (head node):

2 -> 4 -> (Back to head)
