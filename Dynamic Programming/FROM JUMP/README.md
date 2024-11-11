Minimum Energy to Reach the Last Stair
Problem Description
This program calculates the minimum energy required to reach the last stair in a series of stairs, given the heights of each stair. The energy required to move from one stair to another is calculated based on the height difference between the stairs. At each stair, you can either take a step to the next stair or skip one stair to move two steps ahead, each option consuming different amounts of energy.

Approach
To solve this problem, a dynamic programming (DP) approach is used. The key idea is to minimize the energy required at each stair based on the energy consumption of the previous steps.

Dynamic Programming Array:

We use an array dp[], where dp[i] represents the minimum energy required to reach stair i.
Initialize dp[0] = 0, since no energy is required to start at the first stair.
Energy Calculation:

For each stair i (starting from the second stair), calculate the minimum energy to reach that stair from either:
One step back: dp[i-1] + abs(height[i] - height[i-1])
Two steps back: dp[i-2] + abs(height[i] - height[i-2]) (only if i > 1).
Choose the minimum of these two values to find the optimal (least energy-consuming) path to stair i.
Result:

The last element in the dp array (dp[n-1]) gives the minimum energy required to reach the last stair.
Complexity
Time Complexity: O(n) since we calculate the minimum energy required for each stair once.
Space Complexity: O(n) for the dp array used to store the minimum energy at each stair.
Example
Given height = [10, 20, 30, 10], the function calculates that the minimum energy required to reach the last stair is 20.