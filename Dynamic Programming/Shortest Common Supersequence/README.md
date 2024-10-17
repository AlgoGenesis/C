# Shortest Common Supersequence

## Problem Statement

We are given two strings `S1` and `S2`. The task is to return their **Shortest Common Supersequence** (SCS). A supersequence is defined as a string that contains both `S1` and `S2` as subsequences. The goal is to find the **shortest** such supersequence.

### Example

#### Example 1:
- **Input**:  
  `S1 = "brute"`,  
  `S2 = "groot"`
- **Output**: `bgruoote`
- **Explanation**: "bgruoote" is the shortest string that contains both "brute" and "groot" as subsequences.

### Approach

The brute force way to create a supersequence is to concatenate `S1` and `S2`. However, we want to find the shortest such sequence. This can be optimized by using the **Longest Common Subsequence (LCS)** between the two strings.

#### Key Insight:

- We can build the **Shortest Common Supersequence (SCS)** by combining the characters from `S1` and `S2`, avoiding duplicate characters that form the **Longest Common Subsequence (LCS)**. 
- Any character from the **LCS** appears only once in the result, and characters from `S1` and `S2` that are not part of the **LCS** are placed in their respective order around the common characters.

#### Steps:

1. **Find the Longest Common Subsequence (LCS)** of `S1` and `S2` using Dynamic Programming (DP).
2. **Construct the SCS** by traversing the DP table in reverse to collect characters from both strings.
3. **Time Complexity**: `O(n * m)` where `n` is the length of `S1` and `m` is the length of `S2`.
4. **Space Complexity**: `O(n * m)` for the DP table.

### Algorithm

1. **Initialize a DP table** with dimensions `(n+1) x (m+1)` where `n` is the length of `S1` and `m` is the length of `S2`.
2. **Build the DP table**:
   - If `S1[i-1] == S2[j-1]`, then `dp[i][j] = 1 + dp[i-1][j-1]`.
   - If `S1[i-1] != S2[j-1]`, then `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`.
3. **Traceback** from the bottom-right of the DP table to construct the SCS string:
   - If characters match (`S1[i-1] == S2[j-1]`), include that character only once and move diagonally in the DP table.
   - Otherwise, move in the direction that gives the larger value (left or top) and append the character from the corresponding string.
4. **Handle remaining characters** from either string and append them to the result.
5. **Reverse the result string** to get the correct order.

### Dry Run Example:

For `S1 = "brute"` and `S2 = "groot"`:

1. **LCS** is `"ruo"`.
2. The **SCS** constructed by traversing the DP table is `"bgruoote"`.

### Time and Space Complexity

- **Time Complexity**: `O(n * m)` due to filling the DP table and tracing back.
- **Space Complexity**: `O(n * m)` for the DP table.

### Solution Code

You can find the implementation in the `program.c` file.

## Running the Code

1. Clone this repository.
2. Compile the C file using a C compiler like GCC:
    ```bash
    gcc program.c -o program
    ```
3. Run the compiled program:
    ```bash
    ./program
    ```

---

