## Problem: Maximum XOR of Two Numbers

### Problem Statement:
Given an array of non-negative integers, find the maximum XOR of two numbers in the array. The XOR operation between two integers results in a number where each bit is `1` if the corresponding bits of the two numbers differ, and `0` if they are the same.

### Approach Overview:
To find the maximum XOR of two numbers in an array, we use a **Binary Trie** data structure. This allows us to efficiently compare bits of numbers and attempt to maximize the XOR value.

### Steps:
1. **Binary TrieNode Structure**:
   - Each node has two children: `children[0]` for the bit `0` and `children[1]` for the bit `1`.
   - We represent numbers in their binary form (using up to 31 bits).

2. **Insertion**:
   - Each number in the array is inserted into the Trie bit by bit, starting from the most significant bit (MSB).
   - New nodes are created as necessary for each bit (`0` or `1`).

3. **Finding Maximum XOR**:
   - For each number, we traverse the Trie and try to maximize the XOR by choosing the opposite bit at each step (e.g., if the current bit is `0`, try to go to `1`, and vice versa).
   - The XOR is maximized when we take the opposite bit at each level of the Trie.

### Example:
```c
int nums[] = {3, 10, 5, 25, 2, 8};
```

1. Insert the numbers into the Trie.
2. For each number, calculate the maximum XOR by traversing the Trie and choosing the path that gives the highest XOR.

**Output**:
```
Maximum XOR: 28
```

### Key Points:
- The Binary Trie allows efficient lookup and insertion of binary representations of numbers.
- The XOR is maximized by selecting the opposite bit at each level, ensuring we get the maximum possible value.