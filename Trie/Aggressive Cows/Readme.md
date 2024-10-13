## Aggressive Cows

## Problem Statement
You are given an array of length ‘N,’ where each element denotes the position of a stall. These ‘N’ stalls are located along a straight line at positions x1, x2, x3…, xn. The integer ‘K’ represents the number of cows that are aggressive. You need to assign the cows to the stalls such that they don’t hurt each other. This can be done by maximizing the minimum distance between them. What is the largest minimum distance?

## Analyzing the Problem Statement
Let’s analyze the problem and write down some important points that will help you reach the solutions.

What can be the minimum distance between two cows? 
Since two cows can’t be placed in the same stall, the minimum possible distance can be 1.

## The Solution
To solve this problem, we can use binary search to efficiently find the maximum minimum distance. The key idea is to perform a binary search on the possible distances, and at each step, check if it’s possible to place the required number of cows with that distance.

Let’s break down the solution into steps:

Step 1: Sort the Positions
Sort the given positions in ascending order. Sorting allows us to perform efficient binary search and simplifies the process of checking distances between cows.
Step 2: Binary Search
Use binary search to find the maximum minimum distance. Initialize the left and right pointers based on the possible range of distances.

Step 3: Check Feasibility
For each mid-distance value, simulate the placement of cows and check if it’s possible to place the required number of cows with that distance. Adjust the pointers accordingly.

Step 4: Return the Result
Once the binary search is complete, return the maximum minimum distance.

## Time Complexity Analysis
The time complexity of the solution is O(nlogn) due to the sorting of positions, and the binary search itself has a time complexity of O(logn). Therefore, the overall time complexity is O(nlogn).