# Binary Tree Level Order Traversal in C

This project contains a C program that constructs a binary tree from user input and performs a level order traversal (breadth-first traversal) using a queue. Each level's nodes are printed on a new line.

## Algorithm

1. **Build Tree**: Starting with the root node, ask the user to input values for each node.
    - For each node, take user input to determine its left and right children.
    - If the input is `-1`, that child is considered `NULL` (no node).
2. **Level Order Traversal**:
    - Initialize a queue to hold nodes at each level.
    - For each node in the queue:
      - Print the node’s value.
      - Add its left and right children to the queue (if they exist).
    - Each level is printed on a new line.

---

## Approach Using Queues

The program uses a queue to facilitate the level order traversal. The algorithm follows a breadth-first approach, where nodes are visited level-by-level:

1. Start by enqueuing the root node.
2. For each node:
   - Dequeue it and print its value.
   - Enqueue its left child (if present).
   - Enqueue its right child (if present).
3. Repeat until the queue is empty. Each level is printed line by line, indicating level-based traversal.

---

## Complexity Analysis

### Time Complexity

- **Tree Construction**: \(O(n)\), where \(n\) is the number of nodes. Each node is visited once.
- **Level Order Traversal**: \(O(n)\), as each node is dequeued, printed, and its children (if any) are enqueued once.

### Space Complexity

- **Tree Construction**: \(O(n)\) for storing nodes in the binary tree.
- **Queue for Traversal**: \(O(w)\), where \(w\) is the maximum width of the binary tree, which in the worst case could be \(O(n)\) if the tree is perfectly balanced.

---

## Sample Input and Output

### Example

Here’s a sample input and output for the program:

**Input:**
Enter root node value (or -1 for NULL): 1
Enter left child of 1 (or -1 for NULL): 2
Enter right child of 1 (or -1 for NULL): 3
Enter left child of 2 (or -1 for NULL): 4
Enter right child of 2 (or -1 for NULL): 5
Enter left child of 3 (or -1 for NULL): 6
Enter right child of 3 (or -1 for NULL): 7
Enter left child of 4 (or -1 for NULL): -1
Enter right child of 4 (or -1 for NULL): -1
Enter left child of 5 (or -1 for NULL): -1
Enter right child of 5 (or -1 for NULL): -1
Enter left child of 6 (or -1 for NULL): -1
Enter right child of 6 (or -1 for NULL): -1
Enter left child of 7 (or -1 for NULL): -1
Enter right child of 7 (or -1 for NULL): -1

**Output:**
Level Order Traversal:
1 
2 3 
4 5 6 7 