### Full Binary Tree Algorithm

**Working Of The Proposed Algorithm:-**

1.  **User Input for Node Count**: The program prompts the user to enter the number of nodes in the full binary tree.
    
2.  **Validation for Full Binary Tree**: The program checks if the number of nodes is valid for a full binary tree (i.e., it must be of the form (2^k - 1) for some (k)). If not, it displays an error message and exits.
    
3.  **Dynamic Memory Allocation for Node Values**: The program dynamically allocates memory for the array that will store the node values.
    
4.  **User Input for Node Values**: The program prompts the user to enter the values for the nodes in level order.

### Time Complexity 

1.  **Constructing the Full Binary Tree:**
    

3.  The function **insertLevelOrder** is called recursively to insert nodes into the tree.
    
4.  For a full binary tree with ( n ) nodes, each node is inserted exactly once.
    
5.  The time complexity for inserting all ( n ) nodes is ( O(n) ).
    
6.  **Inorder Traversal**:
    
    *   The **inorderTraversal** function also visits each node exactly once.
        
    *   The time complexity for the inorder traversal is ( O(n) ).
        

> 7.  Overall Time Complexity
>     
>     The overall time complexity for constructing the full binary tree and performing an inorder traversal is: \[ O(n) + O(n) = O(n) \]