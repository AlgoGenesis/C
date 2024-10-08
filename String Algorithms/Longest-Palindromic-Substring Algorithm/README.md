# Longest Palindromic Substring

## Description

The **Longest Palindromic Substring** algorithm identifies the longest contiguous palindromic substring within a given string. A palindrome is a sequence of characters that reads the same forward and backward. This algorithm uses dynamic programming to efficiently find the longest palindrome in **O(n²)** time, where `n` is the length of the input string.

### Problem Definition

Given:
- A string `S` of length `n`.

Objective:
- Find the longest contiguous substring of `S` that is a palindrome.

### Algorithm Overview

1. **DP Table Initialization**: 
   - Create a 2D table where `dp[i][j]` is true if the substring `S[i...j]` is a palindrome.
   
2. **Base Case**: 
   - All single-character substrings are palindromes. Initialize `dp[i][i]` to true for all `i`.

3. **Check Two-Character Substrings**: 
   - For two consecutive characters, mark as palindrome if they are the same (i.e., `S[i] == S[i+1]`).

4. **Expand to Longer Substrings**: 
   - For substrings longer than two characters, `S[i...j]` is a palindrome if `S[i] == S[j]` and `dp[i+1][j-1]` is true.

5. **Tracking the Longest Palindrome**: 
   - Keep track of the starting index and maximum length of the longest palindrome found.

### Time Complexity

- **Time Complexity**: O(n²), where `n` is the length of the string.
- **Space Complexity**: O(n²) due to the use of the 2D DP table.
