# Levenshtein Distance in C

## Problem Statement
The Levenshtein distance between two strings is the minimum number of single-character edits (insertions, deletions, or substitutions) required to transform one string into the other. This algorithm is commonly used in spell checkers, DNA sequencing, and natural language processing.

### Examples

#### Example 1
**Input:**
s1 = "kitten" s2 = "sitting"
**Output:**
3

**Explanation:** 
The minimum edits to transform "kitten" to "sitting" are:
1. Substitute "k" with "s"
2. Substitute "e" with "i"
3. Append "g"

#### Example 2
**Input:**
s1 = "flaw" s2 = "lawn"
**Output:**
2

**Explanation:** 
The minimum edits to transform "flaw" to "lawn" are:
1. Substitute "f" with "l"
2. Substitute "w" with "n"

---

## Approach
This solution uses Dynamic Programming (DP) to calculate the Levenshtein distance between two strings efficiently.

### DP Recurrence Relation
Define `dp[i][j]` as the Levenshtein distance between the first `i` characters of `s1` and the first `j` characters of `s2`.

1. **If characters match** (`s1[i-1] == s2[j-1]`):
   - `dp[i][j] = dp[i-1][j-1]`
2. **If characters do not match**:
   - `dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])`
   
   where:
   - `dp[i-1][j] + 1` represents a deletion.
   - `dp[i][j-1] + 1` represents an insertion.
   - `dp[i-1][j-1] + 1` represents a substitution.

### Complexity
- **Time Complexity:** \(O(n \times m)\), where `n` is the length of `s1` and `m` is the length of `s2`.
- **Space Complexity:** \(O(n \times m)\), as we use a 2D array to store the distances.

---

## Code
The full code is available in `program.c`.

## Running the Code

### Prerequisites
Ensure you have a C compiler installed, such as GCC.

### Instructions
1. Clone this repository.
2. Compile the C file:

   ```bash
   gcc program.c -o program

3. Run the compiled program:
   ./program
