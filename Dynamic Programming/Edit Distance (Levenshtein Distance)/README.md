
# Edit Distance (Levenshtein Distance)

## Description

This project implements the Edit Distance algorithm, which calculates the minimum number of operations required to transform one string into another. The allowed operations are insertion, deletion, and substitution of a single character.

### Problem Definition

Given two strings `word1` and `word2`, the task is to determine the minimum number of operations required to convert `word1` into `word2`. This problem is commonly used in natural language processing, spell checking, and DNA sequencing.

### Algorithm Overview

The algorithm uses dynamic programming to solve the problem efficiently. It constructs a 2D table `dp` where `dp[i][j]` represents the minimum edit distance between the first `i` characters of `word1` and the first `j` characters of `word2`.

#### Steps
1. **Initialize a 2D array** `dp` of size `(m + 1) x (n + 1)`, where `m` is the length of `word1` and `n` is the length of `word2`.
2. **Base Cases**:
   - `dp[i][0]` is initialized to `i`, as it requires `i` deletions to convert `word1` to an empty string.
   - `dp[0][j]` is initialized to `j`, as it requires `j` insertions to convert an empty string to `word2`.
3. **Fill the DP Table**:
   - Iterate through each character of both strings.
   - For each character, calculate the minimum cost based on the three possible operations:
     - **Insertion**: `dp[i][j-1] + 1`
     - **Deletion**: `dp[i-1][j] + 1`
     - **Substitution**: `dp[i-1][j-1] + cost`, where `cost` is 0 if characters are the same, and 1 if they are different.
4. **Result**: The value at `dp[m][n]` will give the minimum edit distance between `word1` and `word2`.

### Time Complexity

The time complexity of the Edit Distance algorithm is **O(m * n)**, where `m` is the length of `word1` and `n` is the length of `word2`. This is due to the nested iterations through both strings to fill the DP table.
