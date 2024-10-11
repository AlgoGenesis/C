## What are AVL Trees? ##
AVL Trees are a type of self-balancing binary search tree where the difference in heights between the left and right subtrees (the balance factor) is no more than one for every node. This ensures O(log n) time complexity for insertions, deletions, and lookups by maintaining a balanced tree structure.

### How does insertion work in an AVL tree? ###
Insertion in an AVL tree is similar to that in a standard BST, followed by checking the balance factor of each node from the inserted node back to the root. If a node becomes unbalanced (balance factor becomes +2 or -2), rotations (single or double) are performed to restore balance.

### How does deletion work in an AVL tree? ###
Deletion in an AVL tree follows the standard BST deletion process. After removing the node, the balance factor of each ancestor node is updated. If any ancestor node becomes unbalanced, appropriate rotations are performed to restore balance.

### How do lookups work in an AVL tree? ###
Lookups in an AVL tree are performed similarly to standard BST lookups. Starting from the root, the search compares the target value with the current node's value, moving left or right based on whether the target is smaller or larger. This process continues until the target is found or a null reference is reached.


