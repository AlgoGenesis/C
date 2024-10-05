# Sum of Digits Using Recursion

## Description

The sum of digits of a non-negative integer n is the total of all individual digits in the integer. This problem involves calculating the sum of digits using a recursive approach.

The sum of digits function can be defined as follows:

**S(0) = 0**

**S(n) = n % 10 + S(n / 10) for n > 0**

## Problem Definition

Given a non-negative integer n, compute the sum of digits S(n) using recursion.

### Examples:
- S(0) = 0
- S(123) = 1 + 2 + 3 = 6
- S(456) = 4 + 5 + 6 = 15

## Algorithm Overview

1. **Base Case**:  
   - When **n = 0**, return **0**. This is the base case since the sum of digits of 0 is defined as 0.
   
2. **Recursive Case**:  
   - For any **n > 0**, return **n % 10 + sumOfDigits(n / 10)**. This means that to compute the sum of digits of n, add the last digit of n (obtained by n % 10) to the sum of digits of the remaining digits (obtained by recursively calling sumOfDigits with n / 10 as input).

## Time Complexity

The time complexity of this recursive approach is **O(log n)**, where **n** is the input value. This is because the function is called recursively until the base case is reached, and the number of recursive calls is proportional to the number of digits in the input integer.

## Space Complexity

The space complexity is also **O(log n)** due to the recursion stack. Each recursive call is stored in memory until the base case is hit, resulting in a stack depth of **log n**.
