### **Red-Black Tree: Definition**
A **Red-Black Tree** is a type of self-balancing binary search tree (BST) where each node stores an additional "color" property (either red or black). This color property, along with a set of specific rules, helps the tree maintain balance during insertion and deletion operations, ensuring that the height of the tree remains approximately logarithmic concerning the number of nodes. This guarantees that operations like insertion, deletion, and search can be performed efficiently.

### **Implementation Details**
A Red-Black Tree is similar to a Binary Search Tree but includes extra color properties and re-balancing mechanisms after each insertion or deletion. The key implementation details include:

1. **Node Structure**:
   - Each node contains a color (either red or black), a value, and pointers to its left and right children, its parent, and a color indicator.

2. **Balancing After Insertion and Deletion**:
   - When nodes are inserted or deleted, certain properties may be violated. Balancing is performed using **recoloring** and **rotations**:
     - **Left Rotate** and **Right Rotate**: Rotate nodes to adjust their position and maintain the red-black properties.
     - **Recoloring**: Change the color of nodes to restore the red-black properties.
   - **Balancing Rules**: Ensures that tree height remains logarithmic relative to the number of nodes, which helps maintain O(log n) operation time.

### **Key Functions**
1. **Insertion**:
   - Insert the new node as a regular BST node, then color it red.
   - After insertion, check if the red-black properties are violated, and if so, apply rotations or recoloring to restore them.

2. **Deletion**:
   - Perform standard BST deletion.
   - If the deleted node was black, additional balancing steps are taken to restore red-black properties. This involves a series of recoloring and rotations.

3. **Search**:
   - Operates similarly to a standard BST search. Starting at the root, compare the target value with the current node and move left or right accordingly until the node is found or a leaf node is reached.

4. **Rotations (Left Rotate and Right Rotate)**:
   - These operations help adjust the structure of the tree when balancing. A left or right rotation repositions nodes in a subtree to reduce tree height and restore balance.

### **Properties of Red-Black Trees**
To maintain balance, Red-Black Trees follow these five main properties:

1. **Each node is either red or black.**
2. **The root node is always black.**
3. **All leaf nodes (NIL nodes) are black.**
4. **Red Node Constraint**: Red nodes cannot have red children (no two consecutive red nodes on any path).
5. **Black Height**: Every path from a given node to its descendant leaves must have the same number of black nodes.

These properties ensure that no path in the tree is more than twice as long as any other path, maintaining balanced tree height.

### **Time and Space Complexity Analysis**
- **Insertion**: O(log n) due to the tree’s balanced height.
- **Deletion**: O(log n) as it may require rotations to maintain balance.
- **Search**: O(log n), as the height is logarithmic.
- **Space Complexity**: O(n) for storing `n` nodes.