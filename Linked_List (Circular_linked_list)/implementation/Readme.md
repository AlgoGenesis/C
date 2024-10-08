# Circular Linked List Implementation in C
## Overview
This project implements a Circular Linked List in C. In a circular linked list, the last node of the list points back to the first node, creating a loop. Circular linked lists are useful when you want to loop through a list continuously, such as in round-robin scheduling.

## Key Features
Circular Structure: The last node of the list points back to the first node.
Insertion: Allows inserting nodes at the end or beginning of the list.
Traversal: Traverses and displays nodes starting from the head and looping back to the head after reaching the end.
Deletion: Removes specific nodes while maintaining the circular structure.

## How It Works
A Circular Linked List is a variation of a linked list where the last node points back to the first node, forming a loop. The list can be traversed starting from any node, and the traversal will continue until you loop back to the starting point.

### This implementation includes:

Inserting nodes at the end or beginning of the list.
Traversing the list and displaying its contents.
Deleting a node from the list.

## Functions
1. Insertion
void insertEnd(struct Node** head, int data);

### Description: Inserts a node with the given value (data) at the end of the list, ensuring the circular property is maintained.
### Parameters:
head: Pointer to the head node of the list.
data: The value to be inserted into the new node.

2. Deletion
void deleteNode(struct Node** head, int key);

### Description: Deletes a node with a specific value (key) from the list, ensuring the circular structure is preserved.
### Parameters:
head: Pointer to the head node of the list.
key: The value of the node to be deleted.
3. Traversal
void display(struct Node* head);

### Description: Traverses the circular linked list, displaying all the nodes in the list starting from the head and looping back to it.
### Parameters:
head: Pointer to the head node of the list.

## OUTPUT:-
Circular Linked List: 10 -> 20 -> 30 -> (Back to head)
After deletion (at position 2): 10 -> 30 -> (Back to head)
