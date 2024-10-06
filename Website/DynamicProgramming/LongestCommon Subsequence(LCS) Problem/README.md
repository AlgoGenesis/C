# Longest Common Subsequence (LCS) Problem

## Description:

The Longest Common Subsequence (LCS) problem is a classic dynamic programming challenge that involves finding the longest contiguous or non-contiguous subsequence present in two input sequences (strings) while maintaining the original order of elements.

### #Problem Definition:

Given:

Two strings: X[] and Y[] of lengths m and n respectively.

Objective:

Find the length of the longest subsequence that is present in both strings.

### Algorithm Overview:
The dynamic programming approach to solving the LCS problem involves creating a 2D table where each entry in the table represents the length of the LCS up to that point in both strings.

#### Steps
**Dynamic Programming Table**: Create a 2D array dp[m+1][n+1] where dp[i][j] will store the length of the LCS of X[0...i-1] and Y[0...j-1].

**#Initialization**: Initialize the first row and first column to 0. This represents the base case where one of the strings is empty, resulting in an LCS length of 0.
Filling the DP Table:

For each character pair X[i-1] and Y[j-1], if the characters match, we update the table as:
dp[i][j] = dp[i-1][j-1] + 1 (include the character in the LCS)
If the characters don't match, take the maximum of either excluding X[i-1] or Y[j-1]:
dp[i][j] = max(dp[i-1][j], dp[i][j-1])

**Result:** The final answer will be stored in dp[m][n], which contains the length of the LCS for the two input strings.

### Time Complexity:

The time complexity of this dynamic programming solution is O(m * n), where m and n are the lengths of the input strings X and Y respectively.The space complexity is O(m * n) for the DP table

