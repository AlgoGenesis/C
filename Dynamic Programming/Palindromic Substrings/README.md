# Palindromic Substrings - Dynamic Programming

## Problem Statement
The **Palindromic Substrings Problem** involves counting the number of distinct substrings of a given string that are palindromes. A palindrome is a string that reads the same forward and backward.

### Example
Given the string `"aaa"`, the palindromic substrings are:
- `"a"` (3 occurrences)
- `"aa"` (2 occurrences)
- `"aaa"` (1 occurrence)

The total count is `6`.

## Algorithm Overview
1. **Define the Problem State**: Use a 2D dynamic programming array `dp[][]` where `dp[i][j]` indicates whether the substring from index `i` to `j` is a palindrome.
2. **Base Cases**:
   - Every single character is a palindrome.
   - For two consecutive characters, check if they are equal.
3. **Dynamic Programming Approach**:
   - For substrings of length greater than 2, check if the first and last characters are the same and if the substring in between is a palindrome.

### Dynamic Programming Formula
The relationship to update `dp[i][j]` is:
dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1]
- This means that the substring `s[i:j]` is a palindrome if the characters at positions `i` and `j` are equal, and the substring `s[i+1:j-1]` is also a palindrome.

### Pseudocode
```c
function countPalindromicSubstrings(s):
     n = length of s 
    count = 0
    create a 2D array dp of size (n x n)
    for i from 0 to n-1:
    dp[i][i] = true
    count++

    for i from 0 to n-2:
        if s[i] == s[i + 1]:
            dp[i][i + 1] = true
            count++

    for length from 3 to n:
        for i from 0 to n - length:
            j = i + length - 1
            if s[i] == s[j] and dp[i + 1][j - 1]:
                dp[i][j] = true
                count++

return count
```

## Time Complexity
- **Time Complexity**: `O(n^2)`
  - Where `n` is the length of the string. This is due to the nested loops for filling the `dp` array.
- **Space Complexity**: `O(n^2)`
  - The `dp[][]` array requires space proportional to the square of the length of the string.
