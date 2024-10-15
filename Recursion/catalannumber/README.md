# Catalan Number (Recursive)

## Description

This pull request implements the generation of **Catalan numbers** using a recursive algorithm. Catalan numbers are widely used in combinatorial mathematics and appear in various problems, including counting valid expressions, binary trees, and grid paths.

**Key details:**

* **Recursive Approach** : The algorithm uses the recursive relation Cn=∑i=0n−1****Ci****×Cn**−1−i**.
* **Base Case** : C0= 1.
* **Optimized for smaller values** : This implementation serves as an educational tool to demonstrate recursion.

### Problem Definition

The task is to compute the **n-th Catalan number** using a recursive algorithm. Catalan numbers are a sequence of natural numbers that have significant applications in combinatorics, such as counting valid expressions of parentheses, distinct binary trees, and paths in a grid. The recursive approach builds the result based on smaller subproblems, following the relation:

Cn=i=0∑n−**1C**i×Cn**−1−**i

**Input:**

* A single integer nn**n** (where 0≤n≤300 ) representing the index of the Catalan number in the sequence.

**Output:**

* The nn**n**-th Catalan number, which is a non-negative integer.

### Algorithm Overview


The recursive algorithm for generating the **n-th Catalan number** leverages a well-defined recurrence relation. It breaks the problem into smaller subproblems and combines their solutions to compute the desired result.

**Base Case:**

For n=0 , the Catalan number is defined as: C0=1

**Recursive Case:**

For n>0, the Catalan number is computed using the recursive relation:

Cn=i=0∑n−**1C**i×Cn**−1−i**

The recursive call divides the problem into smaller parts, calculating each smaller Catalan number and combining them through multiplication and summation

**Flow of the Algorithm:**

1. If n=0, return 1 as the base case.
2. For any n>0, recursively calculate the Catalan numbers for all values from 0 to n−1, then sum the products of pairs of these Catalan numbers to compute Cn.
3. Continue the recursion until the base case is reached for all subproblems.

This recursive approach naturally mirrors the structure of many combinatorial problems, which are built from smaller instances of the same problem.

### Time Complexity

The time complexity of the recursive Catalan number algorithm is  **O(2^n)** . This is because, in the recursive approach, each call generates two more recursive calls, leading to an exponential growth in the number of calls as **n** increases.

For large nn**n**, this results in significant overhead due to repeated calculations of the same subproblems. Therefore, the recursive method is not efficient for larger values of **n** unless optimized with techniques like memoization.
