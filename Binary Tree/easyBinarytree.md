# EASY BINARY TREE PROBLEMS



## 1.Balanced Binary Tree

Given a binary tree, determine if it is 
height-balanced
### solution
```
class Solution:
    def isBalanced(self, root: Optional[TreeNode], height=2) -> int:
        return  height-1 if root == None else                               \
                0 if (LH:=self.isBalanced(root.left, height + 1)) <= 0 or   \
                      (RH:=self.isBalanced(root.right, height + 1)) <= 0 or \
                      abs(LH - RH) > 1  else                                \
                max(LH, RH)
```

 ## 2.Invert Binary Tree

Given the root of a binary tree, invert the tree, and return its root.

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None
        right = self.invertTree(root.right)
        left = self.invertTree(root.left)
        root.left = right
        root.right = left
        return root
```

## 3.Binary Tree Tilt
Given the root of a binary tree, return the sum of every tree node's tilt.

#The tilt of a tree node is the absolute difference between the sum of all left #subtree node values and all right subtree node values. If a node does not have #a left child, then the sum of the left subtree node values is treated as 0. The #rule is similar if the node does not have a right child.

### solution:
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTilt(self, root: Optional[TreeNode]) -> int:
        def get_sum(root):
            return root.val + get_sum(root.left) + get_sum(root.right) if root else 0
        
        def helper(root):
            global ans
            if root is None:
                return 0
            else:
                ans+= abs(get_sum(root.left) - get_sum(root.right))
                helper(root.left)
                helper(root.right)
                return ans
                
        global ans
        ans=0
        helper(root)
        return ans
```

 
 