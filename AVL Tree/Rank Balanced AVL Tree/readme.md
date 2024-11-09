# Rank-Balanced AVL Tree

## Description

A Rank-Balanced AVL Tree is an advanced self-balancing binary search tree (BST) that not only maintains balance for efficient operation but also tracks the rank (or size of the subtree) of each node. This extra information enables additional rank-based operations while still ensuring logarithmic time complexity for insertion, deletion, and search operations, ideal for scenarios requiring frequent modifications and order statistics.

### Problem Definition

The goal is to implement a self-balancing binary search tree (Rank-Balanced AVL Tree) that efficiently supports:

Insertion: Insert elements while maintaining AVL balance and updating rank information.
Deletion: Remove elements and restore balance while maintaining accurate rank data.
Searching: Locate elements efficiently using the tree's balanced structure.
Rank Operations: Calculate the rank of a node, which represents the position of the element in a sorted order.
Tree Traversals: Traverse nodes in specific orders (in-order, pre-order, post-order).

# Rank-Balanced AVL Properties

In a Rank-Balanced AVL Tree, the balance factor of any node must be between -1 and 1, similar to an AVL Tree. Additionally, each node tracks the size of its subtree, which enables efficient calculation of node ranks or the number of elements smaller than a given node. This structure ensures the tree remains balanced with O(log n) height for n nodes, providing efficient performance.

# Algorithm Review

1. Insertion

Insert the node like in a regular BST.
After insertion, update the rank information for each ancestor node.
Check the balance factor and apply rotations if needed to restore balance:
Left Rotation: To balance a right-heavy subtree.
Right Rotation: To balance a left-heavy subtree.
Left-Right Rotation: For specific left-right cases.
Right-Left Rotation: For specific right-left cases.

2. Deletion

Remove the node like in a BST.
Update rank information for affected nodes.
Check and restore balance through rotations as required.

3. Searching

Similar to a standard BST, moving left or right based on value comparisons.
Time complexity remains O(log n) due to balanced structure.
Rank Operations

Using the rank information, find the rank of any node, or retrieve the k-th smallest element efficiently.


4. Tree Traversals

In-order: Returns elements in sorted order.
Pre-order: Visits the root node before its subtrees.
Post-order: Visits subtrees before the root node.

# Time Complexity

For Rank-Balanced AVL Trees, all operations are efficient due to the tree's height being O(log n):

Insertion: O(log n) (may involve O(log n) rotations to rebalance the tree).
Deletion: O(log n) (may require O(log n) rotations).
Search: O(log n).
Rank Calculation: O(log n) due to subtree size tracking.
Traversal: O(n) for all nodes.


