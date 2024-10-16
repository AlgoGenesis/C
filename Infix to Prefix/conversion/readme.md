Here's an updated version of your README that incorporates the improvements made to the infix to prefix conversion algorithm, along with code blocks showcasing the enhanced sections of the code:

---

# Infix To Prefix Conversion

## Description

This project converts an arithmetic expression from Infix notation (where operators are placed between operands) to Prefix notation (where operators are placed before their operands). The conversion simplifies the evaluation of expressions, especially in computer systems, where prefix expressions automatically eliminate the need for parentheses and respect operator precedence.

Unlike infix notation, where the order of operations can be ambiguous without parentheses, prefix notation ensures that operations are executed in the correct order based solely on their position in the expression. This conversion helps simplify the expression evaluation process in various computational scenarios.

## Problem Definition

Given an arithmetic expression in infix form (e.g., A + B * C), the task is to convert it to prefix form (e.g., + A * B C) using an algorithm that handles operator precedence and associativity. The expression may include:

- Operands (variables or numbers)
- Operators (`+`, `-`, `*`, `/`, `^`)
- Parentheses to override operator precedence.

The output should be a prefix expression that a stack-based computation can easily evaluate. In prefix notation, operators appear before their operands, simplifying expression evaluation by removing the need for parentheses and directly respecting operator precedence. This makes prefix notation especially useful for compilers and expression evaluators.

## Algorithm

1. Reverse the input string.
2. Swap every left parenthesis `(` with a right parenthesis `)` and vice versa.
3. Initialize:
   - An empty stack for operators.
   - An empty list for the prefix output.
4. Scan the reversed infix expression from left to right:
   - If the symbol is an operand, append it directly to the prefix output.
   - If the symbol is an operator:
     - While the operator at the top of the stack has greater or equal precedence than the current operator, pop it to the prefix output.
     - Push the current operator onto the stack.
   - If the symbol is a left parenthesis `(`, push it onto the stack.
   - If the symbol is a right parenthesis `)`, pop the stack to the prefix output until a left parenthesis is encountered, then discard the left parenthesis.
5. After scanning the expression, pop any remaining operators from the stack and append them to the prefix output.
6. Reverse the prefix output to get the final prefix expression.

## Example

For the infix expression: `A*B+C`

The prefix output is: `+*ABC`

## Improvements

The algorithm has been enhanced with the following features:

1. **Error Handling**: Added checks for stack overflow, underflow, and invalid characters in the input.
2. **Input Validation**: A function to ensure that parentheses are properly matched before processing the expression.
3. **Clearer Precedence Handling**: Improved readability of operator precedence logic using a switch-case structure.

### Code Improvements

Here are some specific code improvements made to the original implementation:

#### Enhanced Error Handling

```c
void push(struct Stack* stack, char c) {
    if (isFull(stack)) {
        fprintf(stderr, "Stack overflow: Unable to push '%c'\n", c); // Enhanced error message
        exit(EXIT_FAILURE); // Exit program on overflow
    }
}
```

#### Input Validation Function

```c
int isValidInfix(const char* exp) {
    int openBrackets = 0;
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') openBrackets++;
        if (exp[i] == ')') openBrackets--;
        if (openBrackets < 0) return 0; // More closing brackets than opening
    }
    return (openBrackets == 0); // Valid if all brackets are closed
}
```

#### Improved Operator Precedence Handling

```c
int precedence(char c) {
    switch (c) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}
```

## Time Complexity

The algorithm performs a single scan of the infix expression, making it `O(n)` in time complexity, where n is the number of characters in the input expression. Each operator is pushed and popped from the stack at most once, ensuring linear complexity.