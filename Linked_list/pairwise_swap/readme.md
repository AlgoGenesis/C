# Given a singly linked list, the task is to swap linked list elements pairwise.

Examples:

1. Input : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL 
   Output : 2 -> 1 -> 4 -> 3 -> 6 -> 5 -> NULL


2. Input : 1 -> 2 -> 3 -> 4 -> 5 -> NULL 
   Output : 2 -> 1 -> 4 -> 3 -> 5 -> NULL

# Implementation 1 :Using Recursion

- O(n) Time and O(n) Space

The idea is to swap the data of the first two adjacent nodes, then recursively move to the next pair of nodes. In each recursive call, the data of the current node is swapped with its next node, and the function continues to do so until there are fewer than two nodes left in the list


# Implementation 2 : Using Iterative Method

 – O(n) Time and O(1) Space

The idea is to traverse the linked list from head and swap the data between adjacent nodes in pairs. Starting from the head node, we swap the data of the current node with the next node, then move two steps forward to swap the next pair.