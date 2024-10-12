# Edit Distance (Levenshtein Distance) - Dynamic Programming

## Problem Statement
The **Edit Distance (Levenshtein Distance)** problem is to find the minimum number of operations required to convert one string into another. The permitted operations are:
1. **Insertion** of a character.
2. **Deletion** of a character.
3. **Replacement** of a character.

For example, to transform the string `"kitten"` into `"sitting"`, the minimum number of operations required is 3:
- Replace 'k' with 's'.
- Replace 'e' with 'i'.
- Insert 'g' at the end.

The Edit Distance is therefore 3.

## Algorithm Overview
The solution uses **Dynamic Programming** to find the Edit Distance. We maintain a 2D table `dp[][]` where `dp[i][j]` represents the minimum number of operations required to convert the first `i` characters of `str1` to the first `j` characters of `str2`.

### Psuedocode 
```java
for i from 0 to m:
    for j from 0 to n:
        if i == 0:
            dp[i][j] = j  // Insert all characters of str2 into str1
        else if j == 0:
            dp[i][j] = i  // Remove all characters of str1
        else if str1[i-1] == str2[j-1]:
            dp[i][j] = dp[i-1][j-1]
        else:
            dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1])
return dp[m][n]

```
## Time Complexity
- **Time Complexity**: `O(m * n)`
  - The 2D `dp` table is filled in `O(m * n)` time where `m` and `n` are the lengths of the two strings.
- **Space Complexity**: `O(m * n)`
  - The `dp` array requires `O(m * n)` additional space to store the edit distances for all combinations of prefixes of the two strings.

