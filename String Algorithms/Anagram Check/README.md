# Anagram Check Algorithm

## Description

The Anagram Check algorithm is used to determine if two strings are anagrams of each other. An anagram is a rearrangement(permutation) of the characters of one word or phrase to form another, using all the original characters exactly once. This algorithm can be useful in applications requiring string comparisons or pattern matching, such as spell-checking, cryptography, and text analysis.

```
Example:
str1 = This is true
str2 = Is this True

Output:
The strings are anagrams
```

### Problem Definition

Given:
- Two input strings, `str1` and `str2`

Objective:
- Determine if `str1` and `str2` are anagrams, regardless of case-sensitiveness.

### Algorithm Overview

1. **Preprocessing**:
   - Convert both strings to lowercase to ensure case-insensitive comparison.
   - Remove any whitespace or non-alphabetic characters (if needed for specific use cases).

2. **Character Counting**:
   - Initialize an array of fixed size to count character occurrences (assuming ASCII or Unicode).
   - For each character in `str1`, increment the count at its respective index.
   - For each character in `str2`, decrement the count at its respective index.

3. **Check Counts**:
   - Verify if all counts are zero. If true, the strings are anagrams; otherwise, they are not.
   
### Key Features

- Efficiently checks for anagram status by counting character frequencies in linear time.
- Can be modified to ignore whitespace or non-alphabetic characters as needed.
- Uses case-insensitive comparison to allow flexibility with different character cases.

### Time Complexity

- **Best case**: O(n) when `str1` and `str2` have different lengths and can be immediately identified as non-anagrams.
- **Average/Worst case**: O(n), where `n` is the length of each string, since we must examine each character.

### Space Complexity

- O(1) for the character count array of fixed size (e.g., 256 for ASCII).

## Implementation

The implementation in C includes:

1. Conversion functions to handle case-insensitive comparisons.
2. A function to count characters and check for anagram status.
3. A main function to demonstrate the usage of the Anagram Check algorithm.

## Usage

Compile and run the program. The example in the main function demonstrates how to use the Anagram Check algorithm to verify if two input strings are anagrams.