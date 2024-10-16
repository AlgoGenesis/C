# Weighted Interval Scheduling Problem

## Description:
The Weighted Interval Scheduling problem is a dynamic programming challenge that involves selecting a set of non-overlapping intervals, each associated with a weight (or profit), to maximize the total weight. The goal is to find the optimal subset of intervals such that no two intervals overlap.

## Problem Definition:
Given:

- A set of intervals \( I = \{(s_1, f_1, w_1), (s_2, f_2, w_2), \ldots, (s_n, f_n, w_n)\} \), where each interval \( (s_i, f_i) \) has a start time \( s_i \), finish time \( f_i \), and a weight \( w_i \).

Objective:

- Select a subset of non-overlapping intervals that maximizes the total weight.

## Algorithm Overview:
The dynamic programming approach to solving the Weighted Interval Scheduling problem involves sorting the intervals by their finish times and then using a DP table to keep track of the maximum weight obtainable at each interval.

### Steps

1. **Sort Intervals**: 
   - Sort the intervals based on their finish times \( f_i \).

2. **Dynamic Programming Table**: 
   - Create a 1D array `dp[n]` where `dp[i]` will store the maximum weight obtainable by considering intervals from \( 1 \) to \( i \).

3. **Preprocessing for Compatibility**:
   - Create a function to find the last non-conflicting interval for each interval \( i \). This function iterates through the sorted intervals and finds the maximum index \( j < i \) such that \( f_j \leq s_i \).

4. **Initialization**: 
   - Set `dp[0]` to \( 0 \) (base case, no intervals selected).

5. **Filling the DP Table**:
   - For each interval \( i \) from \( 1 \) to \( n \):
     - Let \( incl = w_i + dp[last\_non\_conflicting\_interval(i)] \) (include the current interval).
     - Let \( excl = dp[i-1] \) (exclude the current interval).
     - Update the table as: `dp[i] = max(incl, excl)`.

6. **Result**: 
   - The final answer will be stored in `dp[n]`, which contains the maximum weight of non-overlapping intervals.

## Time Complexity:
The time complexity of this dynamic programming solution is \( O(n \log n) \) due to the sorting step, followed by \( O(n) \) for filling the DP table, resulting in a total complexity of \( O(n \log n) \). The space complexity is \( O(n) \) for the DP array.
