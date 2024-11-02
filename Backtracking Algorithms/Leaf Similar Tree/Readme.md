## Leaf-Similar Tree

# Problem Description
In the given problem, we are asked to compare two binary trees to check if they are 'leaf-similar'. Binary trees are a type of data structure in which each node has at most two children, referred to as the left child and the right child. A leaf node is a node with no children. The 'leaf value sequence' is the list of values of these leaf nodes read from left to right. Two binary trees are considered 'leaf-similar' if the sequences that of their leaf values are identical.

# Solution Approach
The solution is implemented in Python, and it focuses on a Depth-First Search (DFS) approach to traverse through the binary trees. The implementation defines a nested function dfs within the leafSimilar method, with the purpose of performing the actual DFS traversal, searching the entire tree for its leaves, and building the leaf sequence.

Here's the step-by-step breakdown of the algorithm:

The dfs function is defined, which takes a single argument, root, representing the current node in the tree.
Upon each invocation of dfs, the function first checks if the current root node is None. If it is, it returns an empty list as there are no leaves to gather from a None subtree.
If the current node is not None, the dfs function first recursively calls itself with root.left and root.right to search through the entire left and right subtrees.
The leaves are gathered by this part of the code: ans = dfs(root.left) + dfs(root.right). This code concatenates the left and right subtree leaves into one sequence.
Finally, the function checks if the node is a leaf node, that means both root.left and root.right are None. If it is a leaf, it returns a list containing the leaf's value: [root.val]. If the node is not a leaf, it returns the concatenated list of leaf values from both the left and right subtrees.
The main function leafSimilar calls the dfs function for both root1 and root2 trees, collecting the sequences of leaf values as lists.
The solution concludes by comparing these two lists with dfs(root1) == dfs(root2). If they are identical, it means that the leaf value sequences are the same, and therefore the two trees are considered leaf-similar and True is returned. If the sequences differ in any way, the function returns False.

# Examples: 

Input: Roots of below Binary Trees
         1            
        / \
       2   3      
      /   / \          
     4   6   7

          0
        /   \
       5     8      
        \   / \        
        4   6  7
Output: same
Leaf order traversal of both trees is 4 6 7     

Input: Roots of below Binary Trees
         0            
        / \
       1   2         
      / \       
     8   9     

# Time Complexity and Space Complexity
The time complexity of the algorithm is determined by the depth-first search (DFS) function, which visits every node in the binary tree exactly once. Therefore, the time complexity is O(N+M), where N is the number of nodes in the first tree and M is the number of nodes in the second tree.

The space complexity is mainly governed by the call stack of the recursive DFS calls and the space used to store the leaf values. In the worst case, the depth of the recursion could be O(H1+H2), where H1 is the maximum height of the first tree and H2 is the maximum height of the second tree, if the trees are highly skewed.