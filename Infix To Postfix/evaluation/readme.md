# Infix To Postfix Evaluation 

## Description 

This project evaluates an arithmetic expression that has been converted to Postfix notation. Postfix notation (also called Reverse Polish Notation, RPN) places operators after their operands, eliminating the need for parentheses and simplifying the evaluation process using a stack-based approach.

### Problem Defination

Given a valid postfix expression (e.g., A B C * +), the task is to evaluate it to compute the result. The expression may consist of:

Operands (numbers or variables that have corresponding values)

Operators (+, -, *, /, ^) that follow standard precedence rules.


The evaluation process must be efficient and handle any valid postfix expression.

### Algorithm Review

1. Initialize an empty stack.


2. Scan the postfix expression from left to right:

If the symbol is an operand, push it onto the stack.

If the symbol is an operator:

Pop the top two operands from the stack.

Perform the operation using the operator on these two operands.

Push the result back onto the stack.

3. At the end of the expression, the result of the evaluation will be the single value remaining on the stack.


Example

For the postfix expression: 2 3 4 * +

The evaluation proceeds as:

3 * 4 = 12

2 + 12 = 14


The final result is 14.


### Time Complexity

The time complexity of evaluating a postfix expression is O(n), where n is the number of symbols in the postfix expression. Each symbol is processed once (either pushed to the stack or popped for computation), ensuring linear complexity.
