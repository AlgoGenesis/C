Here’s a different classic *Dynamic Programming* problem: *Edit Distance (Levenshtein Distance)*. This problem demonstrates the DP approach to solving string manipulation problems efficiently.

### Problem:
Given two strings, str1 and str2, find the minimum number of operations required to convert str1 into str2. The allowed operations are:
- *Insert* a character
- *Remove* a character
- *Replace* a character

### Algorithm:
1. We define a 2D DP table dp[i][j], where dp[i][j] represents the minimum number of operations required to convert the first i characters of str1 to the first j characters of str2.
2. The base case is:
   - If one of the strings is empty, the edit distance is the length of the other string (since we need to insert all characters).
3. For each character in the strings, if they are the same, no operation is needed; otherwise, we consider the minimum cost among the three possible operations: insert, delete, or replace.


### Code Explanation:

1. *Base Case*:
   - If one string is empty, the only way to convert it to the other is by performing insert operations for every character of the other string.
   
2. *Recurrence Relation*:
   - If the characters match (str1[i-1] == str2[j-1]), no operation is needed, so dp[i][j] = dp[i-1][j-1].
   - If they don’t match, consider the minimum of the three operations:
     - *Insert*: dp[i][j-1] + 1
     - *Remove*: dp[i-1][j] + 1
     - *Replace*: dp[i-1][j-1] + 1

### Example:

For the input strings:
- str1 = "sunday"
- str2 = "saturday"

The output will be:


Minimum number of operations to convert sunday to saturday is: 3


This means that the minimum number of insertions, deletions, or replacements needed to convert sunday into saturday is 3.

### Operations:
- Insert 'a' after 's'.
- Insert 't' after 's'.
- Replace 'n' with 'r'.