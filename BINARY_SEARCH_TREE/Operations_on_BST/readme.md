# Binary Search Tree (BST)

## Description

A Binary Search Tree (BST) is a data structure where each node has at most two children and every node follows the property: the value of the left child is less than the parent node, and the value of the right child is greater than the parent node. This structure enables efficient searching, insertion, and deletion of elements, making it suitable for a variety of dynamic data applications.

******************

## Problem Definition

The goal is to implement a Binary Search Tree that supports:

- **Insertion of elements**, ensuring the BST property is maintained.

- **Deletion of elements**, maintaining the tree's structure after the removal of nodes.

- **Efficient searching** for elements.

- **Tree traversals** (in-order, pre-order, post-order).

******************

## Algorithm Review

### 1. Insertion

- Start at the root.
- Recursively move to the left if the value to insert is smaller, and to the right if it is larger.
- Insert the new node at the correct position while maintaining the BST property.

Example:
For inserting the value 8 into this tree:

    10
   /  \
  5    20
We compare 8 with 10 (less, so move left), then 8 with 5 (greater, so move right), and insert 8 as the right child of 5.

Time Complexity:
Average case: O(log n)
Worst case (unbalanced): O(n)

******************

### 2. Deletion

- Find the node to delete.
- If the node has no children, simply remove it.
- If the node has one child, replace it with its child.
- If the node has two children, replace the node with its in-order successor (smallest value in the right subtree), and delete the successor node.

Example:
For deleting the value 10 from this tree:

    10
   /  \
  5    20

If 10 is deleted, the in-order successor (smallest node in the right subtree) is 20, so 20 will replace 10 as the new root.

Time Complexity:
Average case: O(log n)
Worst case (unbalanced): O(n)


******************

### 3. Searching

- Start at the root.
- Move left if the value is smaller than the current node, and right if it’s larger.
- Continue until the node is found or the search reaches a leaf node (null).


Example:
For searching 5 in this tree:

     10
   /  \
  5    20

We compare 5 with 10 (less, move left), then we find 5.

Time Complexity:
Average case: O(log n)
Worst case (unbalanced): O(n)



******************

## Tree Traversals

### 1. In-order Traversal (LNR)

- Left subtree -> Node -> Right subtree.
- Visits nodes in ascending order.

### 2. Pre-order Traversal (NLR)

- Node -> Left subtree -> Right subtree.
- Useful for creating a copy of the tree.

### 3. Post-order Traversal (LRN)

- Left subtree -> Right subtree -> Node.
- Useful for deleting or freeing nodes in a tree.

******************

## Time Complexity

- **Insertion:** O(h), where h is the height of the tree. In the worst case (unbalanced), h = O(n).
- **Deletion:** O(h).
- **Search:** O(h).
- **Traversal:** O(n).

In the worst case (unbalanced), the time complexity can be O(n). However, with balanced trees like AVL or Red-Black Trees, this is improved to O(log n).
