# Longest String Chain (Dynamic Programming)

## Overview

The **Longest String Chain** problem is a dynamic programming-based problem where we are given a list of strings, and we need to find the longest possible chain of strings such that each string in the chain can be formed by adding one character to the previous string in the chain.

### Problem Statement

You are given an array of words. A word chain is a sequence of words such that every word except the first one can be formed by inserting a single character into the previous word. Your task is to find the length of the longest possible word chain.

### Example

Input:

words[] = {"a", "b", "ba", "bca", "bda", "bdca"}

Output:

The length of the longest string chain is: 4
Explanation:

The longest string chain is: "a" -> "ba" -> "bda" -> "bdca".

Approach
Key Idea
This problem can be solved using a dynamic programming approach. We first sort the array of words based on their lengths. Then, for each word, we attempt to build the longest chain possible by checking if the word can be formed by adding one character to any of the previous shorter words. We use a dynamic programming array dp[] to store the length of the longest chain ending at each word.

Steps:
Sorting: We sort the words based on their lengths.
Dynamic Programming: We initialize a dp[] array where dp[i] will store the longest chain ending with words[i].
Comparison: For each word, we check if it can be formed by adding a single character to any of the previously processed words. If a valid chain can be formed, we update the dp[] value.
Result: The maximum value in the dp[] array is the length of the longest word chain.
Time Complexity:
Sorting: O(N * log N)
DP Calculation: O(N^2 * L), where N is the number of words and L is the average length of a word.
Overall, the time complexity is O(N^2 * L + N * log N).

Space Complexity:
The space complexity is O(N), where N is the number of words
