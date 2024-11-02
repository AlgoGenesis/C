# Postfix Expression Evaluation

## Description:
This project implements a tool for evaluating arithmetic expressions written in Postfix notation (Reverse Polish Notation). Postfix notation is a mathematical notation in which every operator follows all of its operands, eliminating the need for parentheses to dictate the order of operations.

## Problem Definition:
Given an arithmetic expression in Postfix form (e.g., `23 45 * 9 -`), the objective is to evaluate the expression and return the result using an algorithm that efficiently manages the operands and operators using a stack data structure.

## Key Elements:
- **Operands:** Numeric values.
- **Operators:** `+`, `-`, `*`, `/`.

The output of evaluating a Postfix expression should:
1. Correctly apply operators to their respective operands.
2. Handle arithmetic operations including addition, subtraction, multiplication, and division.
3. Manage errors, such as division by zero, appropriately.

## Algorithm
1. **Initialize a Stack:** Create an empty stack to store integer values.
2. **Read the Postfix Expression:** Start reading the postfix expression from left to right.
3. **Process Each Symbol:**
   - **If the Symbol is an Operand:**
     - Convert it to an integer and push it onto the stack.
   - **If the Symbol is an Operator:**
     - Pop the top two operands from the stack.
     - Perform the arithmetic operation corresponding to the operator.
     - Push the result back onto the stack.
4. **Repeat:** Continue this process until all symbols in the postfix expression are processed.
5. **Final Result:** The stack will contain one element at the end, which is the result of the expression.

## Example
For the Postfix expression: `23 45 * 9 -`
- **Step 1:** Push 2 → Stack: [2]
- **Step 2:** Push 3 → Stack: [2, 3]
- **Step 3:** `*` is an operator, pop 3 and 2, compute 2 * 3 = 6, push the result → Stack: [6]
- **Step 4:** Push 4 → Stack: [6, 4]
- **Step 5:** Push 5 → Stack: [6, 4, 5]
- **Step 6:** `-` is an operator, pop 5 and 4, compute 4 - 5 = -1, push the result → Stack: [6, -1]
- **Step 7:** Push 9 → Stack: [6, -1, 9]
- **Step 8:** `-` is an operator, pop 9 and -1, compute -1 - 9 = -10, push the result → Stack: [6, -10]
- **Step 9:** `*` is an operator, pop -10 and 6, compute 6 * -10 = -60, push the result → Stack: [-60]
  
**Final result:** `-60`

## Time Complexity
The algorithm performs a single scan of the postfix expression, making it **O(n)** in time complexity, where n is the number of characters in the input expression. Each operand and operator is pushed and popped from the stack at most once, ensuring linear complexity.

## Usage
1. Compile the program using a C compiler.
2. Run the executable and input a valid postfix expression when prompted.
3. The program will output the result of the evaluation.

## Example Input
```
Enter a postfix expression: 23 45 * 9 -
```

## Example Output
```
Result of evaluation: -60
```
