This section describes the implementation of a function in C that verifies how to find the nearest common ancestor of a Binary Tree (BT).I can only offer the recursive way to implement it.If someone has non-recursive ideas,welcome to add.

## Problem Statement ##
Given a binary tree, find the nearest common ancestors of the two specified nodes in that tree.
For the two nodes p and q of the root tree T, the nearest common ancestor is represented as one node x, satisfying x is the ancestor of p and q and the depth of x is as large as possible.A node can also be its own ancestor.

## Solution ##
 if root be p,q The most recent common ancestor is only possible in one of the following cases:
1. p and q are in root's subtree and on different sides;
2. p=root moreover q at root left or right subtree;
3. q=root moreover p at root left or right subtree;
   
#### *find_LCA*:

Consider performing a pre-order traversal of the binary tree by recursively when encountering nodes p or q. When nodes p,q are on the opposite sides of node root, the node root is the nearest common ancestor, it is returned upwards.

When the leaf node is crossed, it returns directly null; While the data of root is equal to p or q , go back directly root;

Then we can begin recursive works: 

Turn on the recursive left child node, and the return value is denoted as left.

Turn on the recursive right child node, and the return value is denoted as right. 

When left and right are also empty, this means the left and right subtrees of root don't contain p or q, return NULL. This situation can be combined with the situation where either side of the left and right subtree is empty.

 When left or right is empty, this means nothing on the empty side. P,q are both on the opposite side, go to the opposite side.

When left and right are also not empty, which meaning p,q are on both sides of root,the root is what we want.






