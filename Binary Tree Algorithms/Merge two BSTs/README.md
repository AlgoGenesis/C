                           Merge Two Binary Search Trees

Description

This project provides a solution to merge two Binary Search Trees (BSTs) into a single balanced BST. Merging two BSTs is a common operation in data structures, allowing the combination of two ordered datasets while maintaining efficient search properties.

The algorithm involves:
1. Performing in-order traversal on each BST to obtain sorted arrays of values.
2. Merging the two sorted arrays into one sorted array.
3. Building a balanced BST from the merged sorted array.
This solution ensures that the final merged tree remains balanced, allowing efficient operations such as search, insertion, and      deletion.

Problem Statement

Given two Binary Search Trees, we aim to merge them into a single BST that:
- Contains all elements from both trees.
- Maintains the properties of a Binary Search Tree.
- Is balanced to optimize search efficiency.
This solution is useful for applications where merging ordered data structures is required while preserving search efficiency.

Approach and Solution

Steps to Merge Two BSTs
1. In-Order Traversal:
  - Perform an in-order traversal on both BSTs to extract elements in sorted order.
  - This gives two sorted arrays of values from the two trees.

2. Merge Sorted Arrays:
  - Merge the two sorted arrays into one single sorted array.
  - This ensures that all elements from both trees are combined in   sorted order.

3. Build a Balanced BST:
  - Convert the merged sorted array into a balanced BST.
  - We achieve this by choosing the middle element of the array as the  root and recursively building left and right subtrees, ensuring the tree is height-balanced.


Algorithm Complexity

- Time Complexity:
  - O(m + n) for in-order traversal (where m and n are the sizes of the two BSTs).
  - O(m + n) for merging two sorted arrays.
  - O(m + n) for building the balanced BST from a sorted array.
  - Overall Complexity: O(m + n).

- Space Complexity: O(m + n), as we store values in arrays and construct a new BST.


Example
This example demonstrates the merging process of two BSTs, showing the trees before merging and the structure of the final merged BST.

Input:
1. BST 1:     
   3  
 /  \
1    5
  - In-order traversal of BST 1: 1 3 5

2. BST 2:
   4  
 /  \
2    6
  - In-order traversal of BST 2: 2 4 6


Process:
1. In-order Traversal:
  - First, we perform in-order traversal on both BSTs to obtain sorted arrays.
  - BST 1 in-order traversal gives: [1, 3, 5]
  - BST 2 in-order traversal gives: [2, 4, 6]

2. Merge Sorted Arrays:
  - Next, we merge the two sorted arrays from the BSTs.
  - Merged array: [1, 2, 3, 4, 5, 6]

3. Build Balanced BST:
- We use the merged array to create a balanced BST:
  - Middle element 3 becomes the root.
  - Elements [1, 2] are on the left subtree, with 2 as the right child of 1.
  - Elements [4, 5, 6] are on the right subtree, with 5 as the right child of 4.
-The final balanced BST is:
           3
         /   \
        1      5
         \     / \
          2   4   6

Output:
After merging, the final in-order traversal of the balanced merged BST is:

1 2 3 4 5 6
