# Interleaving Strings

## Problem Description
Given three strings `A`, `B`, and `C`, determine if `C` is an interleaving of `A` and `B`. `C` is considered an interleaving of `A` and `B` if it contains all characters of `A` and `B`, with their order preserved, though characters from each string can be interwoven.

### Example
#### Example 1
- **Input:**
A = "aab" B = "axy" C = "aaxaby"
- **Output:**
True

- **Explanation:** 
`C` can be formed by interleaving `A` and `B`, as `C = "aaxaby"` follows the sequence of characters from both `A` and `B`.

#### Example 2
- **Input:**
A = "abc" B = "def" C = "abdecf"
- **Output:**
False
- **Explanation:** 
`C` is not an interleaving of `A` and `B`, as the sequence of characters does not match both `A` and `B`.

## Approach
We use **Dynamic Programming (DP)** to solve this problem efficiently. We define a DP table where each cell `dp[i][j]` represents whether the first `i` characters of `A` and the first `j` characters of `B` can form the first `i + j` characters of `C`.

### Key Insights
1. If `A[i-1]` matches `C[i+j-1]`, then `dp[i][j]` depends on `dp[i-1][j]`.
2. If `B[j-1]` matches `C[i+j-1]`, then `dp[i][j]` depends on `dp[i][j-1]`.
3. If either condition above holds, then `dp[i][j]` is `true`.

### DP Recurrence Relation
- If `A[i-1] == C[i+j-1]`, then `dp[i][j] = dp[i-1][j]`.
- If `B[j-1] == C[i+j-1]`, then `dp[i][j] = dp[i][j-1]`.
- If either condition is true, `dp[i][j] = true`.

### Steps
1. Initialize a 2D DP table with dimensions `(n+1) x (m+1)`, where `n` is the length of `A` and `m` is the length of `B`.
2. Fill the table based on the recurrence relations derived.
3. The result will be in `dp[n][m]`, representing if all characters of `A` and `B` can interleave to form `C`.

### Complexity Analysis
- **Time Complexity**: `O(n * m)`, where `n` is the length of `A` and `m` is the length of `B`.
- **Space Complexity**: `O(n * m)`, for storing the DP table.