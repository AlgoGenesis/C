Check if a Tree is a Binary Search Tree (BST)

This section describes the implementation of a function in C that verifies whether a given binary tree satisfies the properties of a Binary Search Tree (BST).

Problem Statement

A Binary Search Tree (BST) is a binary tree where for every node:

->The value of all nodes in the left subtree is less than the node’s value.
->The value of all nodes in the right subtree is greater than the node’s value.

Given a binary tree, our goal is to determine if it meets these properties.

Solution Approach

The implementation uses recursion to verify that each node in the tree is within a specified range of allowable values:

1. Recursively Traverse the Tree: For each node, ensure that its value lies within the defined minimum and maximum range.
2. Update Range for Subtrees:
 (i) For the left subtree, the maximum allowable value is updated to the current node's value.
 (ii) For the right subtree, the minimum allowable value is updated to the current node's value.
3. Return Boolean:
 If all nodes respect the BST properties, the function returns true; otherwise, it returns false.


Code Explanation
The implementation consists of two main functions:

1. Helper Function: isBSTUtil

(i) This function takes a node, a minimum value, and a maximum value as input.
(ii) For each node, it checks:
 -> If the node is NULL, it returns true (an empty subtree is valid).
 -> If the node’s value is within the valid range (between min and max).
(iii) It recursively calls itself for the left and right children,     updating the valid range:
 -> For the left child, it narrows the max range to the current node's value.
 -> For the right child, it expands the min range to the current node's value.

3. Main Function: isBST

 (i) This function initializes the range using INT_MIN and INT_MAX to cover all possible integer values.
 (ii) It calls isBSTUtil on the root node.

Consider the following binary tree:

      10
     /  \
    5   20
   / \
  3   8
In this example:

-> The function will verify that all nodes in the left subtree (5, 3, 8) are less than 10.
-> All nodes in the right subtree (20) are greater than 10.
-> Hence, this tree is a valid BST, and the function will return true.

Testing
The provided code includes a simple test case in the main function to demonstrate functionality. To further test, use additional edge cases like:
->An empty tree.
->A tree with only one node.
->Trees where nodes violate BST properties.

This function is highly efficient and is designed for validating whether a binary tree structure adheres to BST rules in O(n) time complexity.


Complexity Analysis
1. Time Complexity: O(n), where n is the number of nodes, as we need to visit each node once.
2. Space Complexity: O(h), where h is the height of the tree, due to the recursive stack during traversal.