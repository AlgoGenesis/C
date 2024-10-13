# Infix To Prefix Evaluation 

## Description 

This project evaluates an arithmetic expression that has been converted to Prefix notation. Prefix notation (also called Polish Notation) places operators before their operands, eliminating the need for parentheses and simplifying the evaluation process using a stack-based approach. By processing the expression from right to left, the evaluation respects operator precedence and is efficient for computation.

## Problem Definition

Given a valid prefix expression (e.g., +A*BC), the task is to evaluate it to compute the result. The expression may consist of:

Operands (numbers or variables that have corresponding values)

Operators (`+`, `-`, `*`, `/`, `^`) that follow standard precedence rules.


The evaluation process must be efficient and handle any valid prefix expression.

# Algorithm for Evaluating a Prefix Expression

1. **Initialize the Stack**:
   - Create a stack to hold integer values.
   - Set the stack's top to -1 to indicate it is empty.

2. **Input Prefix Expression**:
   - Prompt the user to enter a prefix expression (string).
   - Read the input into a character array.

3. **Determine the Length of the Expression**:
   - Calculate the length of the prefix expression string.

4. **Scan the Prefix Expression from Right to Left**:
   - For each character in the prefix expression (starting from the last character to the first):
     - **Check if the Character is an Operand**:
       - If the character is a digit (operand), convert it to an integer by subtracting the ASCII value of '0' and push it onto the stack.
     - **Check if the Character is an Operator**:
       - If the character is an operator (e.g., `+`, `-`, `*`, `/`):
         - Pop the top two operands from the stack:
           - Store the first popped value as `operand1`.
           - Store the second popped value as `operand2`.
         - Perform the operation corresponding to the operator:
           - If the operator is `+`, push the result of `operand1 + operand2` onto the stack.
           - If the operator is `-`, push the result of `operand1 - operand2` onto the stack.
           - If the operator is `*`, push the result of `operand1 * operand2` onto the stack.
           - If the operator is `/`, push the result of `operand1 / operand2` onto the stack.

5. **Final Result**:
   - After processing all characters in the prefix expression, the final result will be at the top of the stack.
   - Pop the result from the stack and return it.

6. **Output the Result**:
   - Print the result of the evaluation.



Example

For the prefix expression: +*34/62

The evaluation proceeds as:

- 2 pushed into stack `2`
- 6 pushed into stack `2, 6`
- then comes / 
  - pop 2 and 3 from the stack and perform `6 / 2 = 3`
  - 3 pushed into the stack  `3`
- 4 pushed into the stack `3, 4`
- 3 pushed into the stack `3, 4, 3`
- now comes the *
  - pop 3 and 4 from the stack and perform `3 * 4 = 12`
  - push 12 into the stack `3, 12`
- now comes +
  - pop 3 and 12 from the stack and perform `12 + 3 = 15`
-push 15 onto the stack.

After complete processing is done
- pop 15 from the stack 

The final result is 15.


### Time Complexity

The time complexity of evaluating a prefix expression is O(n), where n is the number of symbols in the prefix expression. Each symbol is processed once (either pushed to the stack or popped for computation), ensuring linear complexity.
