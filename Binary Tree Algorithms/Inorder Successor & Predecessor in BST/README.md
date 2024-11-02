                  Inorder Successor and Predecessor in a Binary Search Tree (BST)

Overview
The Inorder Successor and Predecessor functions are implemented to assist with traversal operations in a Binary Search Tree (BST). These functions find specific nodes in a BST:
 - The Inorder Predecessor of a given node, which is the largest node that comes before it in in-order traversal.
 - The Inorder Successor of a given node, which is the smallest node that comes after it in in-order traversal.

This functionality is valuable in various applications, including database indexing, memory management, and scenarios where node navigation in a BST is required.

Function Descriptions
 1. findPredecessor:
This function searches for the Inorder Predecessor of a given node in the BST. It traverses the BST to find the largest node smaller than the given node, typically residing in the left subtree. If no predecessor exists (i.e., if the given node is the smallest in the tree), the function returns NULL.

 2. findSuccessor:
This function searches for the Inorder Successor of a given node. It locates the smallest node greater than the given node, typically residing in the right subtree. If no successor exists (i.e., if the given node is the largest in the tree), the function returns NULL.

Code Structure
The implementation consists of the following:
 - Node Structure: Defines each node in the BST with pointers to its left and right children.
 - Insert Function: Inserts new nodes into the BST in sorted order, ensuring BST properties.
 - Predecessor and Successor Functions: Efficiently locate the predecessor and successor nodes by utilizing the properties of the BST.
 - Main Function: Demonstrates the functionality by constructing a BST and testing the findPredecessor and findSuccessor functions on sample nodes.

 Example:
 Consider a BST constructed with the following elements:
         20
       /    \
     8       22
    /  \
   4    12
       /   \
     10    14

We’ll find the Inorder Successor and Predecessor for the node with value 12.

Step-by-Step Example:

1. Create the BST:
 - Insert nodes in this order: 20, 8, 22, 4, 12, 10, 14.
 - The resulting BST is as shown above.

2. Find Predecessor and Successor for Node with Value 12:
 - Inorder Predecessor: The largest value node smaller than 12 is 10.
 - Inorder Successor: The smallest value node larger than 12 is 14.

Example Output:
Using the provided code, running the findPredecessor and findSuccessor functions for the node with value 12 would yield the following output:
Inorder Predecessor of 12 is 10
Inorder Successor of 12 is 14