# Burst Balloons

This project implements an algorithm to solve the Burst Balloons problem, which involves maximizing the number of coins collected by bursting balloons in a specific order using dynamic programming.

## Description

### Problem Definition
The Burst Balloons problem requires you to determine the maximum number of coins you can collect by bursting balloons strategically. Each balloon has a certain number of coins, and bursting a balloon yields coins based on the values of adjacent balloons. The goal is to find the optimal order to burst the balloons to maximize the total coins collected.

### Algorithm Overview
The algorithm uses a dynamic programming approach to calculate the maximum coins that can be collected. It involves creating a 2D array where each entry represents the maximum coins collectible for a given range of balloons. 

#### Steps
1. **Initialization**:
   - Create a new array that includes virtual balloons with a value of 1 at both ends.
   - Initialize a 2D DP array to store results for subproblems.
  
2. **Dynamic Programming Filling**:
   - Iterate through all possible lengths of balloon ranges.
   - For each range, calculate the maximum coins collectible by bursting the last balloon in that range.
   - Use the results of previously computed subproblems to fill in the DP table.

3. **Result Extraction**:
   - The final result is found in the DP table entry that corresponds to bursting all balloons.

### Time Complexity
The time complexity of the Burst Balloons algorithm is O(n^3), where `n` is the number of balloons. This is due to the nested loops required to compute the maximum coins for each subproblem of the balloons, making the approach polynomial with respect to the number of balloons.





