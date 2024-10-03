
# Computing Binomial Coefficient
## Desrciption:
The binomial coefficient C(n,k).
C(n,k) gives the number of ways to choose k elements from a set of n elements.

## Problem Statement: Compute Binomial Coefficient using Dynamic Programming.

Given two integers n and k, write a program to compute the binomial coefficient C(n,k)C(n,k), which represents the number of ways to choose k elements from a set of n elements. This can be defined as:
C(n,k)=n!/(k!(n−k)!)

Alternatively, it can be computed using the recursive relation:
C(n,k)=C(n−1,k−1)+C(n−1,k)  for 1≤k≤n−1

With the following base cases:
C(n,0)=1 and C(n,n)=1

Input:

    Two integers n and k (with 0 <= k <= n) representing the size of the set n and the number of elements to choose k.

Output:

    The value of the binomial coefficient C(n,k)C(n,k), which is the number of ways to choose k elements from n elements.

Time Complexity:

    The time complexity is O(n * k) because we compute each subproblem exactly once.

Memoization Table:
A 2D array t[100][100] is used to store the results of subproblems. Initially, all values are set to -1, indicating that they haven’t been computed yet.