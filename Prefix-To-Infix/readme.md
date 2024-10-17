# Prefix To Infix Conversion

## Description

This project provides a tool for converting arithmetic expressions from Prefix notation (Polish notation) to Infix notation. Prefix notation places operators before their operands, while Infix notation places operators between operands. This conversion helps clarify expression evaluation and maintains proper operator precedence without needing parentheses.


## Problem Definition

Given an arithmetic expression in Prefix form (e.g., * + A B C), the objective is to convert it to Infix form (e.g., ((A + B) * C)) using an algorithm that accurately handles operator precedence and associativity.

Operands (variables or numbers)

Operators (`+`, `-`, `*`, `/`, `^`)

Parentheses to override operator precedence.

The output of converting a prefix expression to an infix expression should follow these guidelines-
   1. Correct Placement of Operators: Operators should be placed between their respective operands.
   2. Use of Parentheses: Parentheses should be used where necessary to maintain the order of operations based on operator precedence and associativity.


## Algorithm

**Initialize a Stack**: Create an empty stack to hold the operands.

**Read the Prefix Expression**: Start reading the prefix expression from right to left.

**Process Each Symbol**:
    - If the Symbol is an Operand:
            - Push it onto the stack.
    - If the Symbol is an Operator:
            - Pop the top two operands from the stack. Let’s call them operand1 and operand2.
            - Create a new string in the format: (operand1 operator operand2).
            - Push this new string back onto the stack.
**Repeat**: Continue this process until you have processed all symbols in the prefix expression.

**Final Result**: The stack will contain one element at the end, which is the required infix expression.


## Example

For the Prefix expression: *+ABC

The Infix output is: ((A+B)*C)


## Time Complexity

The algorithm performs a single scan of the prefix expression, making it `O(n)` in time complexity, where n is the number of characters in the input expression. Each operator is pushed and popped from the stack at most once, ensuring linear complexity.