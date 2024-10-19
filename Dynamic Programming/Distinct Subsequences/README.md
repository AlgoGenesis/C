# Distinct Subsequences

## Problem Statement

We are given two strings `S1` and `S2`, and the goal is to determine how many distinct subsequences of `S2` are present in `S1`. A subsequence of a string is a new string generated from the original string by deleting some (or no) characters without changing the relative order of the remaining characters.

### Example

#### Example 1:
- **Input**:  
  `S1 = "rabbbit"`,  
  `S2 = "rabbit"`
- **Output**: `3`

#### Example 2:
- **Input**:  
  `S1 = "babgbag"`,  
  `S2 = "bag"`
- **Output**: `5`

### Approach

We will solve this problem using **dynamic programming** and optimize it using **space optimization**.

#### Intuition:

We will maintain a `dp` array where `dp[j]` will store the number of ways to match `S2[0..j-1]` as a subsequence in `S1`. We update this array in a space-optimized manner where we only keep track of the current and previous row instead of using a full DP table.

The recurrence relation is:
- If `S1[i-1] == S2[j-1]`, then:  
  `dp[j] = dp[j-1] + dp[j]`  
  (either match the characters or skip `S1[i-1]`)
- Otherwise:  
  `dp[j] = dp[j]`  
  (skip `S1[i-1]`)

We initialize `dp[0]` to `1` for all `i`, because there is exactly one way to match an empty subsequence.

### Algorithm

1. Create a `dp` array initialized to `0` of size `(n+1)`, where `n` is the length of `S2`.
2. Initialize `dp[0]` to `1` since there is one way to match an empty subsequence.
3. Loop over the characters of `S1`, and for each character, loop backward over the characters of `S2` to update the `dp` array.
4. After processing all characters, the value in `dp[m]` (where `m` is the length of `S2`) will contain the result.

### Time Complexity
- **Time Complexity**: `O(n * m)` where `n` is the length of `S1` and `m` is the length of `S2`.
- **Space Complexity**: `O(m)` since we use only a single row for DP.

### Solution Code

The space-optimized dynamic programming solution can be found in the `program.c` file.

## Running the Code

To run the code:

1. Clone this repository.
2. Compile the C file using a C compiler like GCC:
    ```bash
    gcc program.c -o program
    ```
3. Run the compiled program:
    ```bash
    ./program
    ```
