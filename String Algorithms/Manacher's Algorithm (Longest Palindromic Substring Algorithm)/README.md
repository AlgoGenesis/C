# Manacher's Algorithm (Longest Palindromic Substring Algorithm)

## Description

Manacher's Algorithm is a linear time algorithm used to find the **longest palindromic substring** in a given string. This problem involves identifying the longest contiguous substring that reads the same backward as forward. Unlike the naive approach, which takes quadratic time, Manacher's Algorithm achieves this in linear time by transforming the string and using a symmetry property to skip redundant checks.

### Problem Definition

Given:
- A string `s`

Objective:
- Find the longest substring in `s` that is a palindrome.

### Algorithm Overview

1. **Preprocessing**:
   - Transform the original string `s` by inserting special characters (e.g., `#`) between every character and at the beginning and end of the string. This allows uniform handling of both even-length and odd-length palindromes.
   - Example: Transform `"abba"` into `"#a#b#b#a#"`.
   
2. **Searching**:
   - Use a new array `P` where `P[i]` stores the radius of the palindrome centered at index `i` in the transformed string.
   - Maintain a center `C` and a right boundary `R` representing the center and right edge of the rightmost palindrome found so far.
   - For each index `i`, mirror the palindrome around the current center `C` if possible to avoid redundant computations:
     - If `i` lies inside the current palindrome, use the symmetry property to initialize `P[i]`.
     - Expand the palindrome around `i` by comparing characters on both sides until a mismatch is found.
     - Update `C` and `R` when a larger palindrome is found.
   
3. **Extract the Longest Palindrome**:
   - After the array `P` is computed, the maximum value in `P` gives the length of the longest palindromic substring. The center of this palindrome in the transformed string can be mapped back to the original string.

4. **Repeat** this process for all characters in the transformed string.

### Time Complexity

- Preprocessing: O(n), where `n` is the length of the transformed string (or `2 * length of original string + 1`).
- Searching: O(n), because each character is visited at most twice (once during expansion and once during contraction).
- Overall Time Complexity: O(n)

### Benefits of Manacher's Algorithm

Manacher's Algorithm is highly efficient, performing the task of finding the longest palindromic substring in linear time, which makes it useful for various real-time applications, such as searching for palindromes in DNA sequences or detecting mirrored patterns in data.

