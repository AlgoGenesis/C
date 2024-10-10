


#Subset Sum Problem
##Description
The Subset Sum Problem is a classic problem in computer science and combinatorics. Given a set of non-negative integers, the objective is to determine if there exists a subset of the given set whose sum is equal to a specified target value. This problem is commonly used in fields like cryptography, resource allocation, and decision-making.

###Problem Statement
Given:

- `n`: Number of elements in the set
- `set[]`: An array of non-negative integers representing the set
- `sum`: The target sum to check for
The task is to determine whether there exists a subset of the given set such that the sum of the subset equals the target value.

###Example
###Input:
Set: {3, 34, 4, 12, 5, 2}
Sum: 9
###Output:
"Subset with the given sum exists"
The subset {4, 5} sums to 9.

##Dynamic Programming Solution
To solve the Subset Sum Problem, dynamic programming can be used to break the problem down into smaller subproblems. The idea is to build a table that stores whether each possible sum can be formed using elements from the set.

##Approach:
1.DP Table:
Create a 2D DP table dp[i][j] where:

a.i is the index of the set (from 0 to n),
b.j is the sum (from 0 to the target sum),
c.dp[i][j] is true if it is possible to achieve sum j using the first i elements.

2.Initialization:

a.For sum = 0, it's always possible to achieve the sum using an empty subset: dp[i][0] = true.
b.For no elements (i = 0) and a non-zero sum, it’s impossible to form any sum: dp[0][j] = false.

3.Filling the DP Table:

a.For each element in the set, check if including or excluding it results in forming the required sum:
b.If the current element is excluded: dp[i][j] = dp[i-1][j]
c.If the current element is included (and is not greater than the current sum): dp[i][j] = dp[i-1][j-set[i-1]]


##Final Answer:

The value dp[n][sum] tells whether it is possible to form the target sum using the set.