### SUM TREE
---
### Problem Description:

Given a binary tree, the task is to check if it is a Sum Tree. A Sum Tree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. An empty tree is Sum Tree and the sum of an empty tree can be considered as 0. A leaf node is also considered a Sum Tree.

---
### Appraoch
The approach to checking if a binary tree is a Sum Tree involves recursively traversing the tree, where each node checks if it is `NULL` or a leaf. The algorithm computes the sums of the left and right subtrees, then verifies if the current node's value equals the combined sum of its children. If all nodes satisfy this condition, the tree is classified as a Sum Tree; otherwise, it is not.

### Algorithm Steps:

1. Pass the root node of the binary tree to the Sum Tree check function.                         
2. If the node is `NULL`, return `true` with a sum of 0; if it's a leaf, return `true` with its value.                    
3. Recursively call the function for the left child and right child to get their sums and check for Sum Tree property.                   
4. Add the values of the left and right subtree sums to the current node’s value.                    
5. Return `true` if the current node's value equals the sum of its left and right subtree sums; otherwise, return `false`.                       
6. If the root’s check passes, return `true` ; if any node fails, return `false`.               


---
### Sample Input:
    //       26   
    //      /  \                                   
    //     10   3                     
    //    / \    \                   
    //   4  6     3             

### Sample Output:
  The binary tree is a Sum Tree.

---
### Time Complexity:
- The time complexity of checking if a binary tree is a Sum Tree is `O(n)`, where `n` is the number of nodes in the tree. This is because the algorithm visits each node exactly once to compute sums and check the Sum Tree property, resulting in linear traversal.

### Space Complexity:
- The space complexity of the algorithm for checking if a binary tree is a Sum Tree is `O(h)`, where `h` is the height of the tree, due to the recursive call stack. In the worst case, this can be `O(n)` for a skewed tree, while for a balanced tree, it is `O(log n)`.
