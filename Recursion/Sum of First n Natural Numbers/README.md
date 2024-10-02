# Sum of First n Natural Numbers Using Recursion

## Description

The sum of the first `n` natural numbers is the total of all integers from 1 to `n`. This can be computed using recursion by breaking down the problem into smaller subproblems. The idea is to recursively sum the numbers from `n` down to 1.

### Problem Definition

Given a non-negative integer `n`, compute the sum of the first `n` natural numbers using recursion.

### Examples:
- **Input**: `n = 5`  
  **Output**: `15` (since 1 + 2 + 3 + 4 + 5 = 15)

- **Input**: `n = 0`  
  **Output**: `0`

### Algorithm Overview

1. **Base Case**:  
   - If `n = 0`, return `0`. This serves as the base case since the sum of the first 0 numbers is 0.

2. **Recursive Case**:  
   - For any `n > 0`, return `n + sum(n-1)`. This means that to compute the sum of the first `n` numbers, add `n` to the sum of the first `n-1` numbers.

### Detailed Steps:

1. **Function Definition**: Define a recursive function `sum(n)` that computes the sum of the first `n` natural numbers.
2. **Base Condition**: If `n == 0`, return `0`.
3. **Recursive Call**: For `n > 0`, call `sum(n-1)` and add `n` to the result.
4. **Return Result**: Continue until the base case is reached.


### Time Complexity

The time complexity of this recursive approach is **O(n)**, where `n` is the input value. This is because the function makes `n` recursive calls until it reaches the base case.
