## What are Red-Black Trees? ##
Red-Black Trees are a type of self-balancing binary search tree that maintain specific properties to ensure balanced height, resulting in O(log n) time complexity for insertions, deletions, and lookups. Each node is colored either red or black, and the tree adheres to certain rules that enforce balance.

### How does insertion work in a Red-Black tree? ###
Insertion in a Red-Black tree begins like a standard BST insertion. After inserting a new node (colored red), the tree checks for violations of the Red-Black properties. If violations occur, specific recoloring and rotations are performed to restore balance and maintain the properties.

### How does deletion work in a Red-Black tree? ###
Deletion in a Red-Black tree follows the standard BST deletion process. After removing a node, if the tree violates Red-Black properties, a series of recoloring and rotations are executed to ensure the tree remains balanced and the properties are upheld.

### How do lookups work in a Red-Black tree? ###
Lookups in a Red-Black tree are conducted in the same way as in a standard BST. Starting from the root, the search compares the target value with the current node's value, moving left or right based on the comparison, continuing until the target is found or a null reference is reached.
