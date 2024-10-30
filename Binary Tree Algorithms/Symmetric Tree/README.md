### Problem Statement:
Given a Binary Tree, determine whether the given tree is symmetric or not. A Binary Tree would be Symmetric, when its mirror image is exactly the same as the original tree. If we were to draw a vertical line through the centre of the tree, the nodes on the left and right side would be mirror images of each other.

### Approach:
 If the tree is empty, it is symmetric by definition. Otherwise, recursively check if the left subtree is a mirror image of the right subtree by comparing each node's left and right children in opposite order.

### Algorithm Steps:
1. **Base Case**:  
   - If the root node is `NULL`, the tree is symmetric by definition.

2. **Recursive Check**:
   - Define a helper function `isMirror(left, right)` that:
     - Returns `true` if both `left` and `right` nodes are `NULL` (indicating both subtrees are empty).
     - Returns `false` if only one of `left` or `right` is `NULL` (indicating subtrees are not balanced).
     - Checks if `left` and `right` node values are equal.
     - Recursively compares:
       - `left->left` with `right->right`
       - `left->right` with `right->left`

3. **Main Function**:  
   - Call `isMirror(root->left, root->right)` in the main function to check if the left and right subtrees of the root are mirror images.

4. **Return Result**:  
   - If all recursive checks are successful, the tree is symmetric; otherwise, it is not.

### Sample Input:
        1
       / \
      2   2
     / \ / \
    3  4 4  3


### Sample Output:
    The tree is symmetrical

### Explanation of Sample:
  In this tree:
  1. The root node (`1`) has two children, both labeled `2`, which match symmetrically.
  2. The left subtree of the left `2` node contains `3` (left) and `4` (right), while the right subtree of the right `2` node contains `4` (left) and `3` (right).
  3. Each pair of corresponding nodes matches in value and structure, confirming that the tree is a mirror image of itself.
  Thus, the function confirms symmetry and outputs that the tree is symmetrical.

### Time Complexity:
- The time complexity is `(O(n)`, where `n` is the number of nodes, as each node is visited once to verify symmetry.
