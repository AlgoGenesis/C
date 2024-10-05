# Splay Tree

## Description
A Splay Tree is a self-adjusting binary search tree that moves frequently accessed elements closer to the root through a process called splaying. This operation helps improve access times for recently accessed nodes, making the tree efficient for workloads with repetitive access patterns. Unlike balanced trees, Splay Trees do not maintain strict balance, but they ensure that any recently accessed element can be accessed in O(log n) time on average.

### Problem Definition

The goal is to implement a splay tree that efficiently supports the following operations:

1. Insertion of elements, followed by a splay operation to move the inserted node to the root.


2. Deletion of elements, which includes splaying the node to be deleted before removing it.


3. Searching for elements, which will splay the found node to the root.


4. Tree traversals to visit nodes in specific orders (in-order, pre-order, post-order).

### Algorithm Review

1. Insertion

Insert the node as in a standard binary search tree.

After insertion, perform a splay operation to bring the newly inserted node to the root.


2. Deletion

Search for the node to be deleted using the search operation, which brings it to the root.

Remove the root node, then attach the left and right subtrees appropriately.

Perform a splay operation on the new root to maintain the properties of the tree.


3. Searching

To search for a node, traverse the tree as you would in a regular binary search tree.

When the node is found (or the search ends), perform a splay operation to move the found node to the root.


4. Tree Traversals

In-order traversal (LNR): Visits nodes in sorted order.

Pre-order traversal (NLR): Visits root first, followed by left and right subtrees.

Post-order traversal (LRN): Visits children first, followed by the root.


5. Splaying

Zig Rotation: Used when the accessed node is the child of the root.

Zig-Zig Rotation: Used when the accessed node and its parent are both left or both right children.

Zig-Zag Rotation: Used when the accessed node is a right child of a left parent or a left child of a right parent.

### Time Complexity

The time complexity of operations in a Splay Tree is as follows:

Insertion: Amortized O(log n)

Each insertion operation takes O(log n) on average due to the splaying process.


Deletion: Amortized O(log n)

Similar to insertion, deletion involves finding the node (O(log n)) and rebalancing via splaying.


Search: Amortized O(log n)

Searching for a node is efficient, with the amortized cost of O(log n) due to the splay operation.


Traversal: O(n)


