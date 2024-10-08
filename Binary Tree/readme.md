# Binary Tree Algorithm

## Description
A Binary Tree Data Structure is a hierarchical data structure in which each node has at most two children, referred to as the left child and the right child. It is commonly used in computer science for efficient storage and retrieval of data, with various operations such as insertion, deletion, and traversal.

### Problem Defination

Given a collection of elements, the goal is to:

1. Insert each element into a binary tree while maintaining the binary search tree properties.


2. Search for any specific element efficiently in the tree.


3. Delete an element while restructuring the tree to preserve its binary search properties.


4. Perform traversal of the tree to visit nodes in a specific order (in-order, pre-order, or post-order).


5. Compute the height of the tree.

### Algorithm Review 

1. Insertion

To insert a node in a binary search tree (BST):

Start at the root.

Compare the value to be inserted with the current node's value.

If the value is smaller, go to the left subtree.

If the value is larger, go to the right subtree.


When an appropriate null position is found, insert the new node there.
2. Deletion

To delete a node in a binary search tree:

If the node to be deleted has no children, simply remove it.

If the node has one child, replace it with its child.

If the node has two children, find the in-order successor (smallest node in the right subtree), replace the node's value with the successor's value, and then delete the successor.

3. Search

To search for a value in a binary search tree:

Start at the root.

Compare the value with the current node.

If the value matches, return the node.

If the value is smaller, move to the left subtree.

If the value is larger, move to the right subtree.


If the value is not found, return None.
4. Binary trees can be traversed in several orders:

In-order Traversal (LNR): Traverse the left subtree, visit the node, traverse the right subtree.

Pre-order Traversal (NLR): Visit the node, traverse the left subtree, traverse the right subtree.

Post-order Traversal (LRN): Traverse the left subtree, traverse the right subtree, visit the node.

### Time Complexity

The time complexity for the basic operations in a binary tree depends on the tree's height, denoted as h. For a balanced binary tree, h = O(log n) where n is the number of nodes. However, in the worst case (when the tree degenerates into a linked list), h = O(n).

Insertion:

Average case: O(log n)

Worst case: O(n)


Deletion:

Average case: O(log n)

Worst case: O(n)


Search:

Average case: O(log n)

Worst case: O(n)


Traversal (In-order, Pre-order, Post-order):

Time complexity: O(n), as each node needs to be visited.


Height Calculation:

Time complexity: O(n), as the algorithm needs to visit each node to determine the height.