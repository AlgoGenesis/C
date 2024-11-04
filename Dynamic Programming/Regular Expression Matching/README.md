# Regular Expression Matching in C

## Problem Statement
We are given two strings `S1` and `S2`. String `S1` may contain two special characters:

- `'?'` which can match any single character of `S2`.
- `'*'` which can match any sequence of characters, including an empty sequence from `S2`.

Our goal is to determine if the two strings match based on these wildcard rules.

### Examples

#### Example 1
**Input:**
S1 = "a*?b" S2 = "axxb"
**Output:**
True
**Explanation:** The `*` can match "xx" and `?` can match "x", making the entire string match.

#### Example 2
**Input:**
S1 = "a*b" S2 = "acdfb"
**Output:**
True

**Explanation:** The `*` matches "cdf" and the rest of the characters align.

---

## Approach
This problem can be efficiently solved using Dynamic Programming (DP) with space optimization to reduce memory usage.

### Key Insights

- If we encounter a `?`, it must match exactly one character from `S2`.
- If we encounter a `*`, it can match any sequence of characters (including an empty string), which gives us two options:
  - Consider the `*` as matching nothing (move to the next character in `S1`).
  - Consider the `*` as matching one or more characters (move to the next character in `S2`).

### DP Recurrence Relation
To build our DP table:
1. **If `S1[i-1] == S2[j-1]` or `S1[i-1] == '?'`:**
   - `dp[i][j] = dp[i-1][j-1]`
   
2. **If `S1[i-1] == '*'`:**
   - `dp[i][j] = dp[i-1][j] || dp[i][j-1]`

   - The first term `dp[i-1][j]` considers skipping the `*` (treating it as an empty sequence).
   - The second term `dp[i][j-1]` allows `*` to match one or more characters in `S2`.

### Space Optimization
To reduce memory usage, we use two 1D arrays, `prev` and `cur`:

- `prev[j]`: Stores results for the previous row.
- `cur[j]`: Stores results for the current row.

1. Initialize the `prev` array based on base cases. Matching an empty `S1` against `S2` depends on whether `S1` contains only `*`.

2. For each character in `S1`, update the `cur` array based on the recurrence rules.

3. After processing each row, set `prev = cur` for the next iteration.

4. At the end, return `prev[m]` where `m` is the length of `S2`.

---

## Complexity Analysis
- **Time Complexity:** `O(n * m)` where `n` is the length of `S1` and `m` is the length of `S2`.
- **Space Complexity:** `O(m)` as we are only using two rows of size `m` for space optimization.

---

## Solution Code
The C implementation of the space-optimized dynamic programming solution is in the `program.c` file.

---

## Running the Code
1. Clone this repository.
2. Compile the C file using a C compiler like GCC:

   ```bash
   gcc program.c -o program
  

3. Run the compiled program:
   ./program
