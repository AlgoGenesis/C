# Medium Level Binary tree problems and solutions
## 1.Maximum Binary Tree

You are given an integer array nums with no duplicates. A maximum binary tree can be built recursively from nums using the following algorithm:

Create a root node whose value is the maximum value in nums.
Recursively build the left subtree on the subarray prefix to the left of the maximum value.
Recursively build the right subtree on the subarray suffix to the right of the maximum value.
Return the maximum binary tree built from nums.

### solution:
```

class Solution(object):
    def constructMaximumBinaryTree(self, nums):
        m=max(nums)
        i=nums.index(m)
        root=TreeNode(m)
        def tree(temp,left,right):
            if left:
                ml=max(left)
                varl=TreeNode(ml)
                i=left.index(ml)
                temp.left=varl
                if i+1==len(left): tree(temp.left,left[:i],[])
                else: tree(temp.left,left[:i],left[i+1:])
            if right:
                mr=max(right)
                varr=TreeNode(mr)
                i=right.index(mr)
                temp.right=varr
                if i+1==len(right): tree(temp.right,right[:i],[])
                else: tree(temp.right,right[:i],right[i+1:])
        if i+1==len(nums):
            tree(root,nums[:i],[])
        else: tree(root,nums[:i],nums[i+1:])
        return root
```

##  2.Print Binary Tree

Given the root of a binary tree, construct a 0-indexed m x n string matrix res that represents a formatted layout of the tree. The formatted layout matrix should be constructed using the following rules:

The height of the tree is height and the number of rows m should be equal to height + 1.
The number of columns n should be equal to 2height+1 - 1.
Place the root node in the middle of the top row (more formally, at location res[0][(n-1)/2]).
For each node that has been placed in the matrix at position res[r][c], place its left child at res[r+1][c-2height-r-1] and its right child at res[r+1][c+2height-r-1].
Continue this process until all the nodes in the tree have been placed.
Any empty cells should contain the empty string "".
Return the constructed matrix res.


### Solution:
```
class Solution:
    def maxHeightTree(self, node: Optional[TreeNode]) -> int:
        if node is None:
            return 0
        
        leftHeight = self.maxHeightTree(node.left)
        rightHeight = self.maxHeightTree(node.right)

        if leftHeight > rightHeight:
            return leftHeight + 1
        else:
            return rightHeight + 1
    
    def createTreeList(self, root: Optional[TreeNode], maxHeight: int) -> List[List[str]]:
        treeStringList = [[""] * (2 ** maxHeight - 1) for _ in range(maxHeight)]
        queue = deque([(root, 0, (2 ** maxHeight - 1) // 2)])

        while queue:
            node, currentHeight, index = queue.popleft()

            treeStringList[currentHeight][index] = str(node.val)

            offset = 2 ** (maxHeight - currentHeight - 2)

            if node.left is not None:
                queue.append((node.left, currentHeight + 1, index - offset))

            if node.right is not None:
                queue.append((node.right, currentHeight + 1, index + offset))
        
        return treeStringList
    
    def printTree(self, root: Optional[TreeNode]) -> List[List[str]]:
        if root is None:
            return []
        
        maxHeight = self.maxHeightTree(root)
        return self.createTreeList(root, maxHeight)
```

## 3.Binary Tree Pruning

Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

A subtree of a node node is node plus every node that is a descendant of node.

### Solution:
```
return root && (!!(root->left = pruneTree(root->left)) | !!(root->right = pruneTree(root->right)) | root->val) ? root : nullptr;
```
