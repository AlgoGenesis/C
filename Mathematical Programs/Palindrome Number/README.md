# Palindrome Number

## Description

Palindrome numbers are those numbers which after reversing the digits equals the original number.

### Problem Definition

A simple method for this problem is to first reverse all the digits of a given number using arithmetic operations and then compare the reverse of the number with a given number. If both are the same, then return true, else return false.

### Examples:
- **Input**: `n = 43345`  
  **Output**: `Yes` 

- **Input**: `n = 324`  
  **Output**: `No`

### Algorithm Overview

1. **Base Case**:  
   - If `n = 0`, return `0`. This serves as the base case since the sum of the first 0 numbers is 0.

2. **Recursive Case**:  
   - For any `n > 0`, return `n + sum(n-1)`. This means that to compute the sum of the first `n` numbers, add `n` to the sum of the first `n-1` numbers.

### Detailed Steps:

1. **Function Definition**: Define a function `reverseNum(n)` that computes the reverse of `n`.
2. **Function Definition**: Define a function `isPalindrome(n)` that checks if it is Palindrome or not.

### Time Complexity

Time Complexity: O(logN) where N is the number.
Auxiliary Space: O(1)
