Climbing Stairs Problem
This problem is based on a classic dynamic programming challenge where you have to calculate the number of distinct ways to reach the top of a staircase with n steps, given that you can climb either 1 or 2 steps at a time.

Problem Explanation
The problem is a simple application of combinatorial logic. At each step, there are two choices:

Take a single step.
Take two steps.
We can break down the solution as follows:

If we are on the n-th step, there are two possibilities for reaching it:
We arrived from the (n-1)-th step by taking a single step.
We arrived from the (n-2)-th step by taking two steps.
This logic forms a recurrence relation: dp[𝑛]=dp[𝑛−1]+dp[𝑛−2]
dp[n]=dp[n−1]+dp[n−2]

Here, dp[i] represents the number of ways to reach the i-th step.

Solution Approach
Dynamic Programming Array: We initialize an array dp where dp[i] will store the number of ways to reach the i-th step.
Base Cases:
dp[0] = 1: There is 1 way to stay at the ground (by doing nothing).
dp[1] = 1: There is only one way to reach the first step (a single step).
Iterative Calculation:
Starting from i = 2 up to i = n, we compute dp[i] based on the relation dp[i] = dp[i-1] + dp[i-2].
This ensures that each step is built upon the previous ones, leveraging previously computed values to avoid redundant calculations.
Time Complexity
The solution runs in O(n) time, as each step from 2 to n is computed once in a linear scan.

Space Complexity
The space complexity is O(n) due to the storage required for the dp array, which holds the number of ways to reach each step up to n.