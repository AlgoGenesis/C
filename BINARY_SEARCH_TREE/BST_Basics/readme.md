#Binary Search Tree (BST)


***************************************************************

## Description
A Binary Search Tree (BST) is a data structure that maintains elements in a sorted order, allowing for efficient searching, insertion, and deletion operations. 

Each node in a BST has a value greater than all the values in its left subtree and smaller than all the values in its right subtree. 

BSTs provide a foundation for solving problems that require dynamic data ordering and efficient search operations.


***************************************************************

## Problem Definition
The goal is to implement a Binary Search Tree (BST) to support:

Insertion of elements while maintaining the BST property.

Deletion of elements, ensuring that the tree structure adheres to the BST rules.

Searching for elements efficiently.

Tree traversals for visiting nodes in specific orders (in-order, pre-order, post-order).


***************************************************************

## BST Property:

Each node in the tree follows this property:

The left subtree of a node contains only nodes with values less than the node's value.

The right subtree contains only nodes with values greater than the node's value.

Both left and right subtrees must also be binary search trees.


***************************************************************

### Algorithm Review::

1. Insertion
Insertion in a BST follows these steps:

Start at the root and compare the element with the current node.
If the element is smaller, move to the left subtree; if larger, move to the right subtree.
Repeat this process until you find an empty spot and insert the new node.

2. Deletion
Deletion in a BST is more complex as there are three scenarios to consider:

Node to delete has no children: Simply remove the node.
Node to delete has one child: Replace the node with its child.
Node to delete has two children: Replace the node with its in-order successor (smallest node in the right subtree) or in-order predecessor (largest node in the left subtree).

3. Searching
Searching in a BST is done by comparing the target value with the current node:

If the target value equals the node’s value, return the node.
If the target value is smaller, recursively search the left subtree.
If larger, recursively search the right subtree.

4. Tree Traversals
In-order traversal (LNR): Traverse the left subtree, visit the root, and then traverse the right subtree. This returns elements in sorted order.
Pre-order traversal (NLR): Visit the root first, then traverse the left subtree, followed by the right subtree.
Post-order traversal (LRN): Traverse the left subtree, then the right subtree, and finally visit the root.

***************************************************************

## Time Complexity::

The time complexity of operations in a BST depends on the height of the tree:

###
1 Balanced BST: The height is O(log n), and all operations (insertion, deletion, search) are O(log n).

### 
2 Unbalanced BST: In the worst case (when the tree becomes a linked list), the height can become O(n), and the operations will take O(n) time.

### 
3 Insertion:
Average case: O(log n)
Worst case (unbalanced): O(n)

### 
4 Deletion:
Average case: O(log n)
Worst case (unbalanced): O(n)

### 5 Search:
Average case: O(log n)
Worst case (unbalanced): O(n)

### 6 Traversal:
All traversals (in-order, pre-order, post-order): O(n)


***************************************************************

## Applications of Binary Search Tree::

Efficient searching, insertion, and deletion of data.

Used in implementing associative arrays and dictionaries.

Forms the basis for advanced tree structures such as AVL trees and Red-Black trees.

Often used in applications where ordered data and fast lookup, addition, or deletion is required.
 

***************************************************************

## Advantages of Binary Search Tree::

Simple structure and easy to implement.

Searching and sorting operations are efficient when the tree is balanced.

Provides dynamic data storage where data can be inserted or deleted as needed.



***************************************************************

## Disadvantages of Binary Search Tree::

Becomes inefficient if the tree is unbalanced, leading to O(n) time complexity for operations.
Requires tree balancing techniques (e.g., AVL trees or Red-Black trees) to maintain optimal performance in all cases.


***************************************************************
***************************************************************
