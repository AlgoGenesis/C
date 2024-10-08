# House Robber

## Description
This project implements an algorithm to solve the House Robber problem, which aims to determine the maximum amount of money that can be robbed from a series of houses without triggering any alarms.

### Problem Definition

In the House Robber problem, you are given an array of non-negative integers representing the amount of money at each house. You cannot rob two adjacent houses, as that will alert the police. The goal is to find the maximum amount of money you can rob tonight without alerting the police.

### Algorithm Overview

The algorithm employs a dynamic programming approach to find the maximum amount of money that can be robbed.

#### Steps

1. **Initialization**: Create a dynamic programming array `dp` where `dp[i]` represents the maximum amount of money that can be robbed from the first `i` houses.
2. **Base Cases**: 
   - If there are no houses, the maximum amount is `0`.
   - If there is only one house, the maximum amount is the value of that house.
3. **Recurrence Relation**: For each house, you have two choices:
   - Rob the current house and add its value to the maximum amount robbed from the houses before the previous one (i.e., `dp[i - 2]`).
   - Skip the current house and take the maximum amount robbed from the previous house (i.e., `dp[i - 1]`).
   The relation can be expressed as:
   \[
   dp[i] = \max(dp[i - 1], nums[i] + dp[i - 2])
   \]
4. **Final Result**: The maximum amount of money robbed will be in `dp[n]`, where `n` is the number of houses.

### Time Complexity

The time complexity of this algorithm is **O(n)**, where `n` is the number of houses. This is because we iterate through the array of houses once. The space complexity is also **O(n)** for the `dp` array, though it can be optimized to **O(1)** by using two variables to keep track of the maximum amounts.

