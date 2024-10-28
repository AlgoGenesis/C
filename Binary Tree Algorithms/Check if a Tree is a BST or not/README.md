The function recursively verifies that each node’s value lies within a specific range, ensuring all nodes in the left subtree are less and all nodes in the right subtree are greater than the current node.

Explanation of the Code

isBSTUtil Function:
->This recursive utility function checks whether each node’s value is within a specific range (min to max).
->It checks if the current node's value violates the range conditions.
->It then recursively checks left and right subtrees with updated ranges to maintain BST constraints.

isBST Function:
->This function initializes the range for the root node using INT_MIN and INT_MAX, covering all integer values.

Main Function:
->We create a sample tree and test if it’s a BST by calling isBST.

This approach runs in O(n)

O(n) time complexity, where n is the number of nodes, and it uses O(h) space for recursion, where 
h is the height of the tree.