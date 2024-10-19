
# Word Ladder II Problem

## Problem Description:
Given two distinct words `startWord` and `targetWord`, and a list denoting `wordList` of unique words of equal lengths, the task is to find all shortest transformation sequence(s) from `startWord` to `targetWord`. The result can be returned in any order.

### Key Points:
- A word can only consist of lowercase characters.
- Only one letter can be changed in each transformation.
- Each transformed word must exist in the `wordList`, including the `targetWord`.
- `startWord` may or may not be part of the `wordList`.
- Return an empty list if no transformation sequence exists.

### Example 1:
```
Input:
startWord = "der", targetWord = "dfs",
wordList = {"des","der","dfr","dgt","dfs"}

Output:
[ [ "der", "dfr", "dfs" ], [ "der", "des", "dfs" ] ]
```

#### Explanation:
The length of the smallest transformation sequence is 3. The two shortest paths are:
- "der" -> "dfr" -> "dfs"
- "der" -> "des" -> "dfs"

### Example 2:
```
Input:
startWord = "gedk", targetWord = "geek",
wordList = {"geek", "gefk"}

Output:
[ [ "gedk", "geek" ] ]
```

#### Explanation:
The shortest path is:
- "gedk" -> "geek"

### Intuition:
This problem can be solved using **BFS traversal**. It explores all possible ways to reach the `targetWord` by replacing letters one at a time, level by level.

### Approach:
1. **Initial Setup:**
   - Create a **Queue** to store level-wise sequences. Each queue entry will store a list of strings representing the path.
   - Use a **Hash Set** to store the `wordList` for fast search and delete operations.
   - Define vectors `usedOnLevel` to track words used in transformations at each level and `ans` to store the shortest transformation sequences.

2. **BFS Traversal:**
   - Start by adding `startWord` to the queue and mark it as used on the current level.
   - Perform BFS: For each word in the sequence, replace each character ('a' to 'z') and check if the new word exists in the `wordList`.
   - If a match is found, add the word to the sequence and continue.
   - After processing all words at a level, remove the used words from `wordList` to prevent revisiting them.

3. **Handling Target:**
   - If a sequence ends with the `targetWord`, add it to the `ans` vector.
   - Ensure only the shortest transformation sequences are stored.

4. **Edge Case:**
   - If no sequence is found, return an empty list.

## Conclusion:
This BFS-based approach ensures finding all shortest transformation sequences while avoiding redundant paths.

