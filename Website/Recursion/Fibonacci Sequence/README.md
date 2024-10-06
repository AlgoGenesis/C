# Fibonacci Series Using Recursion

## Description

The Fibonacci series is a sequence of numbers where each number is the sum of the two preceding ones, usually starting with 0 and 1. The series is defined as follows:

- F(0) = 0
- F(1) = 1
- F(n) = F(n-1) + F(n-2) for n > 1

The Fibonacci series appears in various areas of mathematics and computer science, particularly in algorithms, data structures, and mathematical problems.

### Problem Definition

Given a non-negative integer `n`, the objective is to compute the `n`-th Fibonacci number using a recursive function.

### Algorithm Overview

1. **Base Cases**: Define the base cases for `F(0)` and `F(1)`.
2. **Recursive Case**: For values greater than `1`, compute the Fibonacci number by calling the function recursively for `F(n-1)` and `F(n-2)`.

### Time Complexity

The time complexity of the recursive approach to compute Fibonacci numbers is `O(2^n)`, which makes it inefficient for large values of `n`. This is due to the exponential growth of function calls. 

For more efficient computation, iterative approaches or memoization techniques can be used.
