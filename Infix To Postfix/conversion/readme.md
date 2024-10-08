# Infix To Postfix Conversion

## Description

This project converts an arithmetic expression from Infix notation (where operators are placed between operands) to Postfix notation (where operators are placed after operands). The conversion simplifies the evaluation of expressions, especially in computer systems, where postfix expressions eliminate the need for parentheses and respect operator precedence automatically.

### Problem Defination

Given an arithmetic expression in infix form (e.g., A + B * C), the task is to convert it to postfix form (e.g., A B C * +) using an algorithm that handles operator precedence and associativity. The expression may include:

Operands (variables or numbers)

Operators (+, -, *, /, ^)

Parentheses to override operator precedence.


The output should be a postfix expression that can be easily evaluated by stack-based computation.

### Algorithm Review

1. Initialize an empty stack for operators and an empty list for the postfix output.


2. Scan each symbol in the infix expression from left to right:

If the symbol is an operand, append it directly to the postfix output.

If the symbol is an operator:

While the operator at the top of the stack has greater or equal precedence, pop it to the output.

Push the current operator onto the stack.


If the symbol is a left parenthesis (, push it onto the stack.

If the symbol is a right parenthesis ), pop the stack to the output until a left parenthesis is encountered.



3. After the expression is fully scanned, pop any remaining operators from the stack to the output.

Example

For the infix expression: A + B * C

The postfix output is: A B C * +

### Time Complexity

The algorithm performs a single scan of the infix expression, making it O(n) in time complexity, where n is the number of characters in the input expression. Each operator is pushed and popped from the stack at most once, ensuring linear complexity.