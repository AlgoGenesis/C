# Postfix to Infix Conversion

## Description:
This project provides a tool for converting arithmetic expressions from Postfix notation (Reverse Polish Notation) to Infix notation. Postfix notation places operators after their operands, while Infix notation places operators between operands with parentheses to ensure the correct precedence. This conversion is useful for readability and in situations where expressions need to be evaluated based on operator precedence.

## Problem Definition:
Given an arithmetic expression in Postfix form (e.g., `A B + C *`), the objective is to convert it to Infix form (e.g., `(A + B) * C`) using an algorithm that handles operator precedence and parenthesis placement correctly.

## Key Elements:
- **Operands:** Variables or numbers.
- **Operators:** (`+`, `-`, `*`, `/`, `^`).

The output of converting a postfix expression to an infix expression should:
1. Correctly place operators between operands.
2. Include parentheses to maintain the correct precedence of operations, avoiding ambiguity.

## Algorithm
1. **Initialize a Stack:** Create an empty stack to store operands and intermediate expressions.
2. **Read the Postfix Expression:** Start reading the postfix expression from left to right.
3. **Process Each Symbol:**
    - **If the Symbol is an Operand:**
        - Push it onto the stack as a string.
    - **If the Symbol is an Operator:**
        - Pop the top two elements from the stack. Let’s call them `operand1` and `operand2`.
        - Form a new infix expression in the format `(operand2 operator operand1)` (since postfix order is reversed).
        - Push this new expression (with parentheses) back onto the stack.
4. **Repeat:** Continue processing each symbol in the postfix expression until the entire expression is parsed.
5. **Final Result:** The stack will contain one element at the end, which is the required infix expression.

## Example
For the Postfix expression: `A B + C *`
- **Step 1:** `A` is an operand, push it → Stack: `[A]`
- **Step 2:** `B` is an operand, push it → Stack: `[A, B]`
- **Step 3:** `+` is an operator, pop `B` and `A`, form `(A + B)`, push it → Stack: `[(A + B)]`
- **Step 4:** `C` is an operand, push it → Stack: `[(A + B), C]`
- **Step 5:** `*` is an operator, pop `C` and `(A + B)`, form `((A + B) * C)`, push it → Stack: `[((A + B) * C)]`
  
**Final Infix output:** `((A + B) * C)`

## Time Complexity
The algorithm performs a single scan of the postfix expression, making it **O(n)** in time complexity, where `n` is the number of characters in the input expression. Each operand and operator is pushed and popped from the stack at most once, ensuring linear complexity.
