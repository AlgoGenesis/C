# AVL Tree

## Description

An AVL Tree is a self-balancing binary search tree (BST) where the height difference (balance factor) between the left and right subtrees of any node is at most 1. This ensures that the tree remains balanced, providing better performance for insertion, deletion, and search operations compared to an unbalanced binary tree.

### Problem Definition

The goal is to implement a self-balancing binary search tree (AVL tree) to efficiently support:

1. Insertion of elements while keeping the tree balanced.
2. Deletion of elements, ensuring the balance of the tree is restored if necessary.
3. Searching for elements efficiently.
4. Tree traversals to visit nodes in specific orders (in-order, pre-order, post-order).

### AVL Property:

After every insertion or deletion, the balance factor (difference between the heights of the left and right subtrees) of each node must be maintained between -1 and 1.

### Algorithm Review

1. **Insertion:**
   - Insert the node like in a regular binary search tree (BST).
   - After insertion, check the balance factor of every ancestor node.
   - If the tree becomes unbalanced, perform one of the following rotations:
     - Left Rotation
     - Right Rotation
     - Left-Right Rotation
     - Right-Left Rotation

2. **Deletion:**
   - Delete the node like in a regular BST.
   - After deletion, check the balance factor of affected nodes.
   - If unbalanced, perform the necessary rotation(s) to restore balance.

3. **Searching:**
   - Same as searching in a binary search tree: move left if the value is smaller, and move right if the value is larger.

4. **Tree Traversals:**
   - In-order traversal (LNR): Returns elements in sorted order.
   - Pre-order traversal (NLR): Visits root first, followed by left and right subtrees.
   - Post-order traversal (LRN): Visits children first, followed by root.

5. **Rotations:**
   - Single Rotations (Left or Right) are used when the tree is unbalanced on one side.
   - Double Rotations (Left-Right or Right-Left) are used when the tree is unbalanced in both directions.

### Time Complexity

In an AVL tree, the height is always maintained as O(log n), ensuring efficient operations:

- **Insertion:** O(log n)
  - Insertion may involve O(log n) rotations to rebalance the tree.
- **Deletion:** O(log n)
  - Deletion may require O(log n) rotations to restore balance.
- **Search:** O(log n)
  - The tree remains balanced, so the search operation takes logarithmic time.
- **Traversal:** O(n)
