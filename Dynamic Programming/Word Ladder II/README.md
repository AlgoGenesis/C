# Word Ladder II

This is a C implementation of the **Word Ladder II** algorithm, which finds the shortest transformation sequence from a `beginWord` to an `endWord`, modifying one character at a time. Each intermediate word in the sequence must exist in a given word list, and only one letter can be changed at each step.

## Problem Description

Given a `beginWord`, an `endWord`, and a list of words (`wordList`), the task is to find the shortest transformation sequence from `beginWord` to `endWord` such that:
1. Only one letter can be changed at a time.
2. Each transformed word must exist in `wordList`.
3. Return the length of the shortest transformation sequence. If no such sequence exists, return `0`.

## Example

**Input:**
- `beginWord`: "hit"
- `endWord`: "cog"
- `wordList`: ["hot", "dot", "dog", "lot", "log", "cog"]

**Output:**

Here’s a README.md file in markdown syntax for the Word Ladder problem:

markdown
Copy code
# Word Ladder

This is a C implementation of the **Word Ladder** algorithm, which finds the shortest transformation sequence from a `beginWord` to an `endWord`, modifying one character at a time. Each intermediate word in the sequence must exist in a given word list, and only one letter can be changed at each step.

## Problem Description

Given a `beginWord`, an `endWord`, and a list of words (`wordList`), the task is to find the shortest transformation sequence from `beginWord` to `endWord` such that:
1. Only one letter can be changed at a time.
2. Each transformed word must exist in `wordList`.
3. Return the length of the shortest transformation sequence. If no such sequence exists, return `0`.

## Example

**Input:**
- `beginWord`: "hit"
- `endWord`: "cog"
- `wordList`: ["hot", "dot", "dog", "lot", "log", "cog"]

**Output:**
Shortest transformation sequence length: 5


**Explanation:**
One of the shortest transformations is `"hit" -> "hot" -> "dot" -> "dog" -> "cog"`, which has 5 steps.

## Approach

This algorithm uses **Breadth-First Search (BFS)** to find the shortest path from the `beginWord` to the `endWord`. BFS is well-suited for finding the shortest path in an unweighted graph, where each word transformation represents an edge between nodes (words).

### Steps:
1. Initialize a queue with the `beginWord` and set its distance to 1.
2. For each word in the queue:
   - Check if it matches the `endWord`. If yes, return the current distance.
   - For each character position in the word, try substituting every possible letter (`a` to `z`).
   - If a transformed word exists in the `wordList`, add it to the queue and mark it as visited by removing it from `wordList`.
3. If the queue is exhausted and `endWord` has not been reached, return `0`.