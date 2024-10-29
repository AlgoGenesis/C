## Trapping Rainwater

## Problem Description
Used to calculate how much water can trapped. Given an array of non-negative integers representation elevation of ground. Your task is to find the water that can be trapped after rain.

 ## Solution Proposed
Solution 1: Brute force

Approach: For each index, we have to find the amount of water that can be stored and we have to sum it up.If we observe carefully the amount the water stored at a particular index is the minimum of maximum elevation to the left and right of the index minus the elevation at that index.

Solution 2:Better solution

Intuition: We are taking O(N) for computing leftMax and rightMax at each index. The complexity can be boiled down to O(1) if we precompute the leftMax and rightMax at each index.

Approach: Take 2 array prefix and suffix array and precompute the leftMax and rightMax for each index beforehand. Then use the formula min(prev[I], next[i])-arr[i] to compute water trapped at each index.


Solution3:Optimal (Two Pointers)

Approach: Take 2 pointers l(left pointer) and r(right pointer) pointing to 0th and (n-1)th index respectively. Take two variables leftMax and rightMax and initialize them to 0. If height[l] is less than or equal to height[r] then if leftMax is less than height[l] update leftMax to height[l] else add leftMax-height[l] to your final answer and move the l pointer to the right i.e l++. If height[r] is less than height[l], then now we are dealing with the right block. If height[r] is greater than rightMax, then update rightMax to height[r] else add rightMax-height[r] to the final answer. Now move r to the left. Repeat these steps till l and r crosses each other.

## Example
Input: height= [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

## Time and Space Complexity
Approach 1
Time Complexity: O(N*N) as for each index we are calculating leftMax and rightMax so it is a nested loop.

Space Complexity: O(1).

Approach 2
Time Complexity: O(3*N) as we are traversing through the array only once. And O(2*N) for computing prefix and suffix array.

Space Complexity: O(N)+O(N) for prefix and suffix arrays.

Approach 3
Time Complexity: O(N) because we are using 2 pointer approach.
Space Complexity: O(1) because we are not using anything extra.

