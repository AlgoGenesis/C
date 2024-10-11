## Problem Statement
The **Word Break Problem** involves determining if a given string can be segmented into words from a specified dictionary. This problem can be efficiently solved using Dynamic Programming.

### Example
Given the string `"leetcode"` and a dictionary containing the words `["leet", "code"]`, the string can be segmented as `["leet", "code"]`.

## Algorithm Overview
1. **Define the Problem State**: Use a boolean array `dp` where `dp[i]` indicates whether the substring `s[0:i]` can be segmented into words from the dictionary.
2. **Base Case**: Initialize `dp[0]` to `true` because an empty string can always be segmented.
3. **Dynamic Programming Approach**:
   - For each position `i` in the string, iterate through each word in the dictionary.
   - Check if the substring ending at `i` matches a word in the dictionary and if the preceding substring can also be segmented.

### Pseudocode
```c
function wordBreak(s, wordDict): 
    n = length of s
    create a boolean array dp of size (n + 1) 
    dp[0] = true
    for i from 1 to n:
        for each word in wordDict:
            if i >= length of word and dp[i - length of word] is true and substring s[i - length of word to i] equals word:
                dp[i] = true
                break

return dp[n]
```
## Time Complexity
- **Time Complexity**: `O(n * m * k)`
  - Where `n` is the length of the string, `m` is the number of words in the dictionary, and `k` is the maximum length of the words in the dictionary.
- **Space Complexity**: `O(n)`
  - The `dp` array requires space proportional to the length of the string.
