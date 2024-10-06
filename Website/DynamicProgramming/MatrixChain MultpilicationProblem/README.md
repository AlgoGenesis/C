# Matrix Chain Multiplication Problem

## Description:

The Matrix Chain Multiplication problem is a classic optimization problem that involves finding the most efficient way to multiply a given sequence of matrices. The goal is to minimize the number of scalar multiplications required to multiply the matrices.

### Problem Definition:

**Given:**
A sequence of matrices, where the i-th matrix has dimensions p[i-1] x p[i].

**Objective:**
Find the minimum number of scalar multiplications needed to multiply the sequence of matrices.

### Algorithm Overview:
The dynamic programming approach to solve this problem involves creating a table that stores the minimum number of scalar multiplications needed for each subproblem.

### Steps:

**Dynamic Programming Table:**
Let m[i][j] represent the minimum number of scalar multiplications needed to multiply matrices from i to j.
**Initialize:** 
m[i][i] = 0, since multiplying one matrix requires zero multiplications.
**Filling the DP Table:**
For chain lengths L = 2 to n, compute m[i][j] by splitting the product at every possible position k and minimizing the number of multiplications.
For each i and j, calculate:
m[i][j] = min(m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j]) for all i <= k < j.
**Result:**
The final answer will be stored in m[1][n-1], which contains the minimum number of scalar multiplications required to multiply the entire chain of matrices.

### Time Complexity:
The time complexity of this dynamic programming solution is O(n^3), where n is the number of matrices.The space complexity is O(n^2) for the DP table.