## Problem: K-th Lexicographical String in Trie

### Problem Statement:
Given a set of strings, your task is to find the **k-th lexicographical string** from this set. The lexicographical order is the same as dictionary order, where words are sorted alphabetically. To solve this problem efficiently, we can use a **Trie (Prefix Tree)**, which naturally maintains the order of characters and helps in finding lexicographical order.

### Approach Overview:
A **Trie (Prefix Tree)** allows us to store words in a hierarchical structure, with each node representing a character. By traversing this Trie in alphabetical order, we can collect the strings in lexicographical order and directly retrieve the k-th word.

### Steps:

1. **TrieNode Structure**: 
   - Each node in the Trie has an array `children[26]` for the lowercase English alphabet (`'a'` to `'z'`).
   - `isEndOfWord` marks if the node is the end of a valid word.
   - Each node can have 26 possible children, corresponding to each letter.

2. **Insertion**:
   - Each word from the input list is inserted into the Trie, character by character.
   - If a node for a character does not exist, a new node is created.
   - At the end of each word, mark the final node as an `end of word`.

3. **Depth-First Search (DFS)** for K-th Lexicographical Word:
   - After inserting the words into the Trie, perform a DFS traversal.
   - Start at the root node and visit each child in lexicographical order (starting from `'a'` to `'z'`).
   - For each word ending node, decrement the counter `k`.
   - Once `k` reaches zero, the current string is the desired k-th lexicographical string.

### Example:
```c
char *words[] = {"banana", "apple", "grape", "mango", "orange"};
int k = 3;
```

1. Insert all the words into the Trie.
2. Traverse the Trie using DFS and find the 3rd lexicographical word.

**Output**:
```
The 3rd lexicographical word is: grape
```
### Key Points:
- The Trie efficiently organizes words such that DFS traversal yields lexicographical order.
- The traversal is designed to visit child nodes from `'a'` to `'z'`, ensuring that words are checked in alphabetical order.
- The algorithm stops when the k-th lexicographical word is found.

### Time Complexity:
- **Insertion**: Inserting all words into the Trie takes O(n * m) time, where `n` is the number of words, and `m` is the average length of the words.
- **Finding the k-th word**: Traversing the Trie in lexicographical order takes O(26 * m), where `m` is the length of the longest word.