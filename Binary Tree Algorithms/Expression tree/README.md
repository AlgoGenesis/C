### EXPRESSION TREE
---
### Problem Description:

This C program constructs an Expression Tree from a user-provided postfix expression and evaluates the expression using inorder traversal. The expression tree is a binary tree where the internal nodes are operators (+, -, *, /), and the leaf nodes are operands (single-digit integers). The program outputs the corresponding infix expression with proper parentheses and computes the evaluated value of the expression.

---
### Description

**1. Postfix Expression:**
Input format where operators come after their operands.
**Example:** For the infix expression (5 + 3) * (8 - 2), the postfix expression would be 53+82-*.

**2. Expression Tree:**
A binary tree where:
Leaf nodes contain operands (e.g., 5, 3, 8, 2).
Internal nodes contain operators (e.g., +, *, -).
The root of the tree represents the last operator in the postfix expression.

**3. Inorder Traversal:**
A tree traversal technique where you visit the left subtree, the root node (operator), and then the right subtree.
During this traversal, the program reconstructs and prints the infix expression with parentheses for operator precedence.

**4. Expression Evaluation:**
The program evaluates the expression as it traverses the tree in an inorder manner.
Operators are applied to the left and right operands, and the final result is printed.

---
### Input:
Enter postfix expression: 53+82-*

### Output: 
Infix expression: ((5+3)*(8-2))                        
Evaluated value: 48

---
### Time Complexity:

The overall time complexity of the program is  **O(n)** , where n is the number of characters in the postfix expression. This includes the time taken for both constructing the expression tree and evaluating the expression via an inorder traversal. Tree construction involves processing each character (either operand or operator) in the postfix expression exactly once, performing constant-time stack operations and node creation. Similarly, the inorder traversal visits each node in the tree once to print the infix expression and evaluate it, making both the construction and traversal linear in time complexity.


