## Aggressive Cows
The "Aggressive Cows" problem is a classic problem that involves placing cows in stalls such that the minimum distance between any two cows is maximized. The goal is to find this maximum minimum distance.

# Problem Statement
You have N stalls and C cows. You need to place the cows in the stalls such that the minimum distance between any two cows is as large as possible.

# Approach
Sort the Stalls: First, sort the array of stall positions.
Binary Search: Use binary search to find the maximum minimum distance.
Greedy Check: For a given distance, check if it is possible to place all cows in the stalls such that the minimum distance between any two cows is at least that distance.

# Example
For the stalls [1, 2, 4, 8, 9] and 3 cows, the maximum minimum distance that can be achieved is:

## Time Complexity:
 O(n log m), where n is the number of stalls and m is the range of possible distances.

# Space Complexity:
 O(1), as we are using a constant amount of space apart from the input.
