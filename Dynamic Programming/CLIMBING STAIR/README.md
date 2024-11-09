Climbing Stairs Problem
This program provides a solution to the "Climbing Stairs" problem, a classic example of dynamic programming. The problem can be stated as follows:

Problem Statement:
A person is at the bottom of a staircase with n steps and wants to reach the top. They can take either 1 or 2 steps at a time. The task is to determine the number of distinct ways the person can reach the top of the staircase.

Approach:s
Dynamic Programming

This problem has overlapping subproblems, making it a suitable candidate for dynamic programming.
Define dp[i] as the number of ways to reach the i-th step.
The number of ways to reach step i is the sum of ways to reach the previous step i-1 and the step before that, i-2. This is because the person can arrive at step i by taking a single step from i-1 or a double step from i-2.
Thus, the recurrence relation is:

𝑑𝑝[𝑖]=𝑑𝑝[𝑖−1]+𝑑𝑝[𝑖−2]dp[i]=dp[i−1]+dp[i−2]
Base Cases:

If there are no steps (n = 0), there is 1 way (doing nothing).
If there is one step (n = 1), there is also 1 way to reach it.
Building the Solution:

Create an array dp of size n+1 to store the number of ways to reach each step up to n.
Initialize dp[0] = 1 and dp[1] = 1 as per the base cases.
Use a loop to fill the array from dp[2] up to dp[n] using the recurrence relation.
Finally, dp[n] will contain the number of distinct ways to reach the top of the staircase with n steps.
Example:
For n = 5, the program calculates the ways as follows:

dp[0] = 1
dp[1] = 1
dp[2] = dp[1] + dp[0] = 2
dp[3] = dp[2] + dp[1] = 3
dp[4] = dp[3] + dp[2] = 5
dp[5] = dp[4] + dp[3] = 8
So, there are 8 distinct ways to reach the 5th step.

Complexity Analysis:
Time Complexity: O(n) because we only need to compute each value in dp from 0 to n.
Space Complexity: O(n) for storing the dp array.
This dynamic programming approach efficiently computes the number of ways to climb the staircase, demonstrating how overlapping subproblems and optimal substructure can be leveraged to solve problems effectively.