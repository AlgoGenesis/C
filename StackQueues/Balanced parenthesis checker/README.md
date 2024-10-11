### **Parentheses Balancing Using Stack**
### Problem Description:
The goal of this program is to check if an expression containing parentheses is balanced. The expression may contain three types of parentheses:

- Round brackets ()
- Curly brackets {}
- Square brackets []     
An expression is said to be balanced if every opening parenthesis has a corresponding closing parenthesis in the correct order.

### Approach:
This program uses a stack data structure to solve the problem of checking whether the parentheses in an expression are balanced. The stack is ideal for this task as it allows tracking unmatched opening parentheses, which are then compared with the closing parentheses.

### Algorithm Steps:
Scan the expression:
1. If an opening parenthesis ((, {, or [) is encountered, push it onto the stack.
2. If a closing parenthesis (), }, or ]) is encountered, check if it matches the top of the stack:
3. If the stack is empty or the parentheses don't match, the expression is unbalanced.
4. At the end:
If the stack is empty, the expression is balanced; otherwise, it's unbalanced.
### Code Explanation:
**Stack structure:** Contains an array to store the stack elements and a top pointer to track the top of the stack.
### Core functions:
**push(), pop(), peek(), isEmpty(), isFull(),** and **freeStack()** are helper functions to handle stack operations.
**isBalanced() function:** Implements the core logic to check if the expression is balanced using the stack.
### Sample Input:
Enter an expression: a+(b+c)-d+[e*f+{g-h*(x-y)}]
### Sample Output:
The parentheses are balanced.
### Explanation of Sample:
In the first input, all the opening and closing parentheses match correctly in the right order.
In the second input, the closing parenthesis does not match the corresponding opening parenthesis, making the expression unbalanced.
### Time Complexity:
For each character in the expression:
Insertion and deletion operations (push and pop) on the stack take constant time O(1).
The algorithm scans through the expression once, making the time complexity O(n), where n is the length of the expression.
### Space Complexity:
The stack can hold at most n characters in the worst case (when all characters are opening parentheses), so the space complexity is O(n).
