# Conversion of Linked List to Balanced Binary Tree

## Overview
To convert a sorted linked list into a balanced binary search tree (BST), we need to carefully choose the middle element of the linked list to maintain the balance of the tree. A balanced BST ensures that the left and right subtrees of every node have a minimal height difference, which optimizes search, insert, and delete operations.

## Steps:
1. Calculate the size of the linked list: This helps in determining the middle element for the root.
2. Recursively build the BST by finding the middle element of the list and using it as the root.
3. Move the linked list pointer while constructing the tree to ensure we are processing the nodes in sequence.

## Explanation:
1. ListNode and TreeNode Structures:

- ListNode represents a node in the linked list with an integer value and a pointer to the next node.
- TreeNode represents a node in the binary search tree (BST), which contains a value, and pointers to its left and right children.
2. Helper Functions:

- createListNode: Creates a new linked list node.
- createTreeNode: Creates a new tree node.
- getListSize: Finds the size of the linked list.
- sortedListToBSTHelper: Recursively builds the balanced BST. It takes the current head of the list (passed as a reference) and the size of the current list segment.
- sortedListToBST: Initializes the process of converting the linked list into a BST by calling the helper function with the list's size.
3. In-order Traversal:

- The inorderTraversal function prints the tree nodes in sorted order (since it’s a binary search tree), which can help verify the correctness of the conversion.
- Helper Function to Create Linked List:

- The createLinkedList function converts an array into a sorted linked list. This is helpful for testing the solution.
4. Main Function:

- We create a sorted linked list [-10, -3, 0, 5, 9].
- We convert this linked list into a balanced BST using the sortedListToBST function.
- The result is printed using in-order traversal, which should print the sorted elements of the BST in the same order.
  
### Time Complexity:
- Finding the size of the linked list: **O(n)**, where n is the number of nodes in the list.
- Recursive BST construction: O(n), since each node of the linked list is processed exactly once.
Thus, the overall time complexity is O(n), where n is the number of nodes in the linked list.

### Space Complexity:
- Recursive stack space: **O(log n)**,
- where n is the number of nodes in the linked list (since we are constructing a balanced tree).
