# Prefix To Postfix Conversion

## Description

This project provides a tool for converting arithmetic expressions from Prefix notation to Postfix notation. Prefix notation places operators before their operands, while Postfix notation places operators after their operands. This conversion simplifies the evaluation process by eliminating the need for parentheses and adhering to the order of operations through the position of operators and operands. Converting from Prefix to Postfix can enhance the clarity and efficiency of expression evaluation in computational systems.


## Problem Definition

Given an arithmetic expression in Prefix form (e.g., * + A B C), the objective is to convert it to Postfix form (e.g., A B + C *) using an algorithm that accurately handles operator precedence and associativity.

Operands (variables or numbers)

Operators (`+`, `-`, `*`, `/`, `^`)

The output of converting a prefix expression to an infix expression should follow these guidelines-
   1. Correct Placement of Operators: Operators should be placed after their respective operands.
   2. No Parentheses: In Postfix notation, operator precedence is inherently maintained by the position of the operators, so parentheses are not required.


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

**Final Result**: The stack will contain one element at the end, which is the required postfix expression.


## Example

For the Prefix expression: *+ABC

The Infix output is: AB+C*


## Time Complexity

The algorithm scans the Prefix expression once from right to left, processing each symbol exactly once. For each operator, it pops two operands and pushes the result back onto the stack, which involves constant-time operations for each symbol. Since there are n symbols in the expression, the time complexity is O(n), where n is the number of characters in the input expression.