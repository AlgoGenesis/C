Factorial Using Recursion
Description
The factorial of a non-negative integer n is the product of all positive integers less than or equal to n. The factorial is defined as follows:

F(0) = 1
F(n) = n * F(n-1) for n > 0
The factorial function is commonly used in mathematics and computer science, particularly in combinatorics, probability, and algorithms.

Problem Definition
Given a non-negative integer n, the objective is to compute the factorial of n using a recursive function.

Algorithm Overview
Base Case: Define the base case for F(0) as 1.
Recursive Case: For values greater than 0, compute the factorial by calling the function recursively for F(n-1) and multiplying it by n.
Time Complexity
The time complexity of the recursive approach to compute the factorial is O(n), as there are n recursive calls made until the base case is reached. This is more efficient than the exponential time complexity seen in the naive recursive Fibonacci calculation.