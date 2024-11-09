This section describes the implementation of a function in C that verifies how to find the nearest common ancestor of a Binary Search Tree (BST).There are both recursive and non-recursive ways to implement it.

## What are BSTs? ##
A Binary Search Tree (BST) is a binary tree where for every node:

->The value of all nodes in the left subtree is less than the node’s value.
->The value of all nodes in the right subtree is greater than the node’s value.

## Problem Statement ##
Given a binary search tree, find the nearest common ancestors of the two specified nodes in that tree.
For the two nodes p and q of the root tree T, the nearest common ancestor is represented as one node x, satisfying x is the ancestor of p and q and the depth of x is as large as possible.A node can also be its own ancestor.

## Solution ##
### 1. recursive
non_recursive_find_LCA:

When root is NULL,we can return directly;If not,on the basis of the BST,we should know the
relationship of position between p,q nodes and root.

If (root->data - p->data) * (root->data - q->data) > 0,it indicates that both differences are either positive or negative,which means p and q are definitely on the same side of the root node.We compare the value of root to the value of any node and decide whether to go left or right.

Then we can start recursion until finding the first node with a value between p and q,that's what we want.

### 2. non_recursive
It's almost the same as the previous one.It just makes the movement of the root node more obvious.I actually think this question just needs to be non_recursive.