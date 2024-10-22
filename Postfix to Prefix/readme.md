# Postfix to Prefix Conversion

## Description:
This project provides a tool for converting arithmetic expressions from Postfix notation (Reverse Polish Notation) to Prefix notation (Polish Notation). Postfix notation places operators after their operands, while Prefix notation places operators before their operands. This conversion allows for more intuitive evaluation of expressions and easier parsing in systems that do not rely on operator precedence.

## Problem Definition:
Given an arithmetic expression in Postfix form (e.g., A B + C *), the objective is to convert it to Prefix form (e.g., * + A B C) using an algorithm that handles the structure correctly.

## Key Elements:
- Operands: Variables or numbers.
- Operators: (+, -, *, /, ^).

The output of converting a postfix expression to a prefix expression should:
1. Correctly place operators before their operands.
2. Avoid ambiguity by ensuring operators are placed with the right precedence.

## Algorithm
1. **Initialize a Stack:** Create an empty stack to store the operands and intermediate expressions.
2. **Read the Postfix Expression:** Start reading the postfix expression from left to right.
3. **Process Each Symbol:**
    - **If the Symbol is an Operand:**
        - Push it onto the stack.
    - **If the Symbol is an Operator:**
        - Pop the top two operands from the stack. Let’s call them operand1 and operand2.
        - Form a new prefix expression in the format: (operator operand2 operand1) (since postfix is reverse, operands are taken in reverse order).
        - Push this new string back onto the stack.
4. **Repeat:** Continue this process until all symbols in the postfix expression are processed.
5. **Final Result:** The stack will contain one element at the end, which is the required prefix expression.

## Example
For the Postfix expression: A B + C *
- **Step 1:** A is an operand, push it → Stack: [A]
- **Step 2:** B is an operand, push it → Stack: [A, B]
- **Step 3:** + is an operator, pop B and A, form + A B, push it → Stack: [+ A B]
- **Step 4:** C is an operand, push it → Stack: [+ A B, C]
- **Step 5:** * is an operator, pop C and + A B, form * + A B C, push it → Stack: [* + A B C]
**Final Prefix output:** * + A B C

## Time Complexity
The algorithm performs a single scan of the postfix expression, making it **O(n)** in time complexity, where n is the number of characters in the input expression. Each operand and operator is pushed and popped from the stack at most once, ensuring linear complexity.