# More Tree Traversal Algorithms

This repository contains various implementations of tree traversal algorithms in C. Each algorithm demonstrates a different method of traversing a binary tree, showcasing the versatility of tree data structures. Below is a detailed description of each file included in this folder, along with their time complexities and explanations of the code.

## Files

1. **boundaryTraversal.c**
   - **Description**: This file implements the boundary traversal algorithm, which prints the boundary nodes of a binary tree in a specific order: root, left boundary (excluding leaves), leaves, and right boundary (excluding leaves).
   - **Code Explanation**:
     - The `Node` structure defines the binary tree node.
     - The `newNode` function creates a new node with given data.
     - The `isLeaf` function checks if a node is a leaf node.
     - The `printLeftBoundary`, `printLeaves`, and `printRightBoundary` functions handle the respective parts of the boundary traversal.
     - The `boundaryTraversal` function orchestrates the overall traversal.
   - **Time Complexity**: O(n), where n is the number of nodes in the tree. Each node is visited once.

2. **spiralOrderTraversal.c**
   - **Description**: This file implements the spiral (or zig-zag) order traversal algorithm. The algorithm uses two stacks to alternate the direction of printing for each level of the tree.
   - **Code Explanation**:
     - The `Node` structure and `newNode` function are similar to the previous file.
     - The `Stack` structure and associated functions (`createStack`, `isEmpty`, `push`, `pop`) manage the two stacks used for traversal.
     - The `spiralOrderTraversal` function processes nodes in a zig-zag manner by alternating between the two stacks.
   - **Time Complexity**: O(n), where n is the number of nodes in the tree. Each node is processed once.

3. **reverseLevelOrderTraversal.c**
   - **Description**: This file implements the reverse level order traversal algorithm. It first stores the nodes in level order using a queue and then prints them in reverse order using a stack.
   - **Code Explanation**:
     - The `Node` structure and `newNode` function are defined as before.
     - The `reverseLevelOrder` function uses a queue to perform a level order traversal and a stack to reverse the order of nodes before printing.
   - **Time Complexity**: O(n), where n is the number of nodes in the tree. Each node is visited once.

4. **MorrisAlgorithm.c**
   - **Description**: This file implements the Morris traversal algorithm for both in-order and pre-order traversals. It allows for tree traversal without using additional space for a stack or recursion.
   - **Code Explanation**:
     - The `Node` structure and `newNode` function are defined similarly.
     - The `morrisInorderTraversal` and `morrisPreorderTraversal` functions use a clever technique of creating temporary links between nodes to facilitate traversal without additional space.
   - **Time Complexity**: O(n) for both in-order and pre-order traversals, where n is the number of nodes in the tree. The space complexity is O(1) since no additional data structures are used.

5. **verticalOrderTraversal.c**
   - **Description**: This file implements the vertical order traversal algorithm, which prints the nodes of the tree in vertical columns based on their horizontal distance from the root.
   - **Code Explanation**:
     - The `Node` structure and `newNode` function are defined as before.
     - The `findMinMax` function determines the minimum and maximum horizontal distances of the tree.
     - The `printVerticalLine` function prints nodes at a specific horizontal distance.
     - The `verticalOrder` function orchestrates the overall vertical traversal.
   - **Time Complexity**: O(n), where n is the number of nodes in the tree. Each node is visited once.

6. **bottomViewTraversal.c**
   - **Description**: This file implements the bottom view traversal algorithm, which prints the nodes of the tree as seen from the bottom.
   - **Code Explanation**:
     - The `Node` structure and `newNode` function are defined similarly.
     - The `Info` structure stores a node along with its horizontal distance and height.
     - The `bottomViewUtil` function recursively updates the bottom-most node at each horizontal distance.
     - The `bottomView` function initializes the data structures and calls the utility function.
   - **Time Complexity**: O(n), where n is the number of nodes in the tree. Each node is visited once.

7. **topViewTraversal.c**
   - **Description**: This file implements the top view traversal algorithm, which prints the nodes of the tree as seen from the top.
   - **Code Explanation**:
     - The `Node` structure and `newNode` function are defined as before.
     - The `Info` structure is used to store the top-most node at each horizontal distance.
     - The `topViewUtil` function recursively updates the top-most node at each horizontal distance.
     - The `topView` function initializes the data structures and calls the utility function.
   - **Time Complexity**: O(n), where n is the number of nodes in the tree. Each node is visited once.

## Usage

To compile and run any of the algorithms, use the following commands in your terminal:

```bash
gcc filename.c -o outputfile
./outputfile
````

Replace `filename.c` with the name of the file you want to compile and `outputfile` with your desired output executable name.

## Example

For example, to run the boundary traversal algorithm:

```bash
gcc boundaryTraversal.c -o boundaryTraversal
./boundaryTraversal
```

## Conclusion

These algorithms provide a comprehensive understanding of different tree traversal techniques. Each algorithm has its unique approach and use cases, making them valuable for various applications in computer science. Feel free to explore and modify the code to suit your needs or to enhance your understanding of tree data structures.
