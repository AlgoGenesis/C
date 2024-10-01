# Sum of First n Natural Numbers Using Recursion

## Description
The sum of the first n natural numbers is the total obtained by adding all integers from 1 to n. This can be efficiently computed using recursion.

### Problem Definition
Given a non-negative integer n, the objective is to calculate the sum of the first n natural numbers using a recursive function.

### Algorithm Overview
**Base Case**: The sum for n = 0 is 0.  
**Recursive Case**: For n > 0, the sum is computed as n + sum(n-1).

### Time Complexity
The time complexity for calculating the sum of the first n natural numbers using recursion is O(n), as there are n recursive calls made until the base case is reached.