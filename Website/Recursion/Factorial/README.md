# Factorial Using Recursion

## Description

The factorial of a non-negative integer `n` is the product of all positive integers less than or equal to `n`. It is a fundamental concept in mathematics, frequently used in combinatorics, probability, and various algorithms.

The factorial function can be defined as follows:
- **F(0) = 1**
- **F(n) = n * F(n-1)** for `n > 0`

The objective is to compute the factorial of a non-negative integer `n` using a recursive approach. Recursion is a method in which a function calls itself to solve a smaller version of the original problem until a base case is reached.

## Problem Definition

Given a non-negative integer `n`, compute the factorial `F(n)` using recursion.

### Examples:
- **F(0) = 1**
- **F(4) = 4 * 3 * 2 * 1 = 24**
- **F(5) = 5 * 4 * 3 * 2 * 1 = 120**

### Algorithm Overview

1. **Base Case**:  
   - When `n = 0`, return 1. This is the base case since the factorial of 0 is defined as 1.
   
2. **Recursive Case**:  
   - For any `n > 0`, return `n * factorial(n-1)`. This means that to compute the factorial of `n`, multiply `n` by the factorial of `n-1`.

### Detailed Steps:

1. **Function Definition**: Define a recursive function `factorial(n)` that computes the factorial of `n`.
2. **Base Condition**: If `n == 0`, return 1.
3. **Recursive Call**: For `n > 0`, the function calls itself with `factorial(n-1)` and multiplies the result by `n`.
4. **Return Result**: Return the result of `n * factorial(n-1)` until the base case is reached.

### Time Complexity

The time complexity of this recursive approach is **O(n)**, where `n` is the input value. This is because the function is called recursively `n` times, reducing the problem size by 1 at each step, until the base case is reached.

### Space Complexity

The space complexity is also **O(n)** due to the recursion stack. Each recursive call is stored in memory until the base case is hit, resulting in a stack depth of `n`.
