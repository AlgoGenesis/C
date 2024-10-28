## What are BSTs? ##
Binary Search Trees, also known as BSTs are a special variant of rooted binary trees that specialize in (on an average) O(log n) insertions, deletions and lookups and hold data in a sorted order.

### How does insertion work in a BST? ###
Insertion in a BST involves comparing the value to be inserted with the root node. If the value is less, the process continues recursively in the left subtree; if greater, it moves to the right subtree. This continues until a suitable null position is found, where the new value is inserted.

### How does deletion work in a BST? ###
Deletion in a BST requires finding the node to be removed. There are three cases to consider: 
1. **Leaf node**: Simply remove the node.
2. **One child**: Remove the node and link its parent directly to its child.
3. **Two children**: Replace the node's value with its in-order predecessor or successor (the largest value in the left subtree or the smallest in the right subtree) and then delete that predecessor or successor.

### How do lookups work in a BST? ###
Lookups in a BST involve comparing the target value to the current node's value. If they match, the search is successful. If the target is less, the search continues in the left subtree; if greater, it moves to the right subtree. This process repeats until the target is found or a null reference is reached, indicating the target is not in the tree.
