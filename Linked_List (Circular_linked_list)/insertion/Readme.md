# Overview
This demonstrates the Insertion operation in a Circular Singly Linked List (CSLL) using C.
In a circular linked list, each node points to the next node, and the last node points back to the first node, creating a circular structure. This implementation allows for the insertion of nodes at various positions in the list.

# Key Features
Circular Structure: Each node points to the next node, and the last node points back to the head.
Multiple Insertion Methods: Insert nodes at the beginning, end, or after a specified node.
Efficient Use of Memory: No additional structures or arrays are required to manage nodes.

# How It Works
A Circular Linked List is similar to a regular linked list, except the last node points back to the first node. In this implementation, you can insert nodes in three different ways:

At the beginning of the list
At the end of the list
After a specific node (based on its value)

# Functions
## 1. Insert at the Beginning

### Description: Inserts a node with the specified value at the beginning of the circular linked list.
### Parameters:-
head: A pointer to the head node of the list.
data: The value to be inserted.

## 2. Insert at the End

### Description: Inserts a node with the specified value at the end of the circular linked list.
### Parameters:
head: A pointer to the head node of the list.
data: The value to be inserted.

## 3. Insert After a Given Node

### Description: Inserts a node with the specified value after a given node.
### Parameters:
prevNode: The node after which the new node will be inserted.
data: The value to be inserted.

## Examples
Inserting Nodes
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);
    insertAfter(head->next, 25);  Insert 25 after 20

## Output
Circular Linked List: 10 -> 20 -> 25 -> 30 -> (Back to head)
