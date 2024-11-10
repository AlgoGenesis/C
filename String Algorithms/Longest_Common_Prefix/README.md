# Longest Common Prefix

## Description

This program finds the Longest Common Prefix (LCP) among an array of strings. The LCP is the longest sequence of characters shared at the beginning of all strings in the array. The program employs an efficient algorithm to identify the common prefix by comparing the strings character by character.

```
Example:
Enter the number of strings: 5
Enter the strings:
String 1: prawn
String 2: prajakta
String 3: prince
String 4: probably
String 5: project

Output:
The longest common prefix is: pr
```

### Problem Definition

1.  **Given**:
- An array of strings and the number of strings, `n`.

2.  **Objective**:
- Find the longest sequence of characters common to the beginning of all strings in the array.

### Algorithm Overview

1. **Input Validation**:
   - Ensure the array contains at least one string.

2. **Prefix Comparison**:
   - Start with the first string as the initial prefix.
   - Compare the prefix with each subsequent string character by character.
   - Update the prefix to the common portion after each comparison.

3. **Early Termination**:
   - If the prefix becomes empty at any point, terminate early as there is no common prefix.

5. **Output Result**:
   - Display the longest common prefix if found; otherwise, indicate no common prefix.

### Key Features

- Efficiently determines the common prefix without unnecessary comparisons.
- Handles edge cases such as identical strings, empty strings, and no common prefix.
- User-friendly input and output.

### Time Complexity

- **Best case**: `O(n * m)`, where `n` is the number of strings and `m` is the length of the shortest string.
- **Worst case**: Same as the best case since each character is processed at most once.

### Space Complexity

- `O(m)` for storing the prefix, where `m` is the length of the shortest string

## Implementation

The implementation in C includes:

1. **Input Handling**:
   - Accepts the number of strings and their contents.

2. **Logic**:
   - A function to iteratively compute the longest common prefix.
   - Compares the prefix with each string and updates it to the common characters.

## Edge Cases for Testing

1. **No Common Prefix**:
   - Input: `["dog", "racecar", "car"]`
   - Output: `There is no common prefix among the strings.`
2. **All Strings Identical**:
   - Input: `["apple", "apple", "apple"]`
   - Output: `The longest common prefix is: apple`
3. **Single String**:
   - Input: `["alone"]`
   - Output: `The longest common prefix is: alone`
4. **Empty Strings**:
   - Input: `["", "abc", "abcd"]`
   - Output: `There is no common prefix among the strings.`

## Usage

- Compile the program using a C compiler (e.g., `gcc longest_common_prefix.c -o lcp`).
- Run the program (`./lcp`).
- Input the number of strings and their values as prompted.
- Observe the output indicating the longest common prefix or a message stating there is no common prefix.