# Binary Exponentiation Algorithm

## Description

Binary exponentiation is an efficient algorithm for computing large powers of a number. It works by breaking down the exponentiation process into smaller, more manageable subproblems using the idea of dividing the exponent in half. This algorithm is particularly useful when dealing with large numbers as it reduces the time complexity to O(log b) for calculating a^b (a raised to the power of b).

## Problem Definition

Given:

A base a (an integer or floating-point number).
A non-negative exponent b (an integer).
Objective:

Compute the value of a raised to the power of b, i.e., a^b.

## Algorithm Overview

Initialize a result variable as 1.

While the exponent b is greater than 0:

    If b is odd, multiply the result by the current base a.
    
    Square the base a to account for the exponent being halved.
    
    Divide the exponent b by 2.
    
    Return the result after the loop terminates.

## Key Operations

Multiplication when the exponent is odd: If the current exponent is odd, multiply the result by the base.

Squaring the base: At each iteration, the base is squared, and the exponent is halved.

## Time Complexity

The time complexity of binary exponentiation is O(log b), which is significantly faster than the naive approach of multiplying the base b times, which would take O(b) time. This logarithmic time complexity makes binary exponentiation especially useful for large exponents.

### Example

To calculate 3^13:

Step 1: Result = 1, Base = 3, Exponent = 13 (odd, so multiply result by base)
Step 2: Result = 3, Base = 9, Exponent = 6 (square the base, halve the exponent)
Step 3: Base = 81, Exponent = 3 (odd, so multiply result by base)
Step 4: Result = 243, Base = 6561, Exponent = 1 (odd, so multiply result by base)
Final Result = 1594323
