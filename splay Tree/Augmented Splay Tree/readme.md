# Augmented Splay Tree (Order Statistic Tree)

## Description
An Augmented Splay Tree is an advanced form of a splay tree that includes additional information to efficiently support *order statistics* operations, such as finding the k-th smallest or largest element. By maintaining subtree sizes for each node, this augmented structure allows for efficient rank queries and order-based operations, making it suitable for scenarios where data access frequency varies and order-based retrievals are needed.

### Problem Definition
The goal is to implement an augmented splay tree that efficiently supports the following operations:

1. **Insertion of elements**, followed by a splay operation to move the inserted node to the root, with subtree size adjustments.
2. **Deletion of elements**, which involves splaying the node to be deleted before removal and adjusting subtree sizes accordingly.
3. **Order-based queries**, including finding the k-th smallest or largest element and rank queries.
4. **Tree traversals** to visit nodes in specific orders (in-order, pre-order, post-order), maintaining subtree size information.

### Algorithm Review

1. **Insertion**
   - Insert the node as in a standard splay tree.
   - Adjust subtree sizes during the insertion.
   - Perform a splay operation to bring the inserted node to the root, adjusting subtree sizes as needed.

2. **Deletion**
   - Splay the tree to bring the target node to the root.
   - Remove the root node, reconnect left and right subtrees, and adjust subtree sizes.
   - Splay the new root to maintain the splay tree properties and adjust subtree sizes accordingly.

3. **Order-based Queries**
   - **K-th Smallest/Largest**: Use subtree sizes to navigate to the k-th element efficiently.
   - **Rank Query**: Determine the rank of an element based on subtree sizes while navigating the tree.

4. **Tree Traversals**
   - **In-order traversal (LNR)**: Visits nodes in sorted order.
   - **Pre-order traversal (NLR)**: Visits root first, followed by left and right subtrees.
   - **Post-order traversal (LRN)**: Visits children first, followed by the root.

5. **Splaying**
   - **Zig Rotation**: Used when the accessed node is the child of the root.
   - **Zig-Zig Rotation**: Used when both node and parent are either left or right children.
   - **Zig-Zag Rotation**: Used when the node is a right child of a left parent or a left child of a right parent.

### Time Complexity
The time complexity of operations in an Augmented Splay Tree is as follows:

- **Insertion**: Amortized O(log n)
  - Each insertion adjusts subtree sizes and performs splaying, resulting in O(log n) on average.

- **Deletion**: Amortized O(log n)
  - Deletion includes finding the node, updating subtree sizes, and rebalancing via splaying.

- **Order-based Queries**: Amortized O(log n)
  - K-th smallest/largest and rank queries operate in O(log n) using subtree size information.

- **Traversal**: O(n)
