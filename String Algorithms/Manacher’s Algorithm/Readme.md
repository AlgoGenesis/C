# Manacher's Algorithm

## Overview

This program uses **Manacher’s Algorithm** to find the **longest palindromic substring** in a given string. The algorithm efficiently computes the result in **O(n)** time, making it significantly faster than traditional methods that take **O(n²)** time. The algorithm handles both odd and even-length palindromes by transforming the string.

## Data Structure

### Structures Used:
- **Array `P[]`**: An integer array that holds the radius of the palindrome centered at each position in the transformed string.
  
- **Transformed String**: The original input string is transformed by adding delimiters (e.g., `#`) between characters to handle odd and even-length palindromes uniformly.

### Functions:

1. **char* preprocessString(char* s)**:  
   Returns the transformed string by adding `#` delimiters and `^` at the beginning and `$` at the end of the string to simplify boundary conditions.

2. **void findLongestPalindrome(char* s)**:  
   Implements the core logic of Manacher's algorithm. It creates the array `P[]` and tracks the center and right edge of the current longest palindrome to calculate the longest palindromic substring efficiently.

3. **void printLongestPalindrome(char* s, int start, int maxLength)**:  
   Prints the longest palindromic substring by extracting the relevant portion of the original string based on the values calculated.

4. **int min(int a, int b)**:  
   Returns the smaller of two integers.

## Memory Management

- **Dynamic Memory Allocation**:  
  The transformed string and palindrome lengths array `P[]` are dynamically allocated to handle strings of arbitrary length.

- **Freeing Memory**:  
  After the longest palindromic substring is found, dynamically allocated memory (such as for the transformed string and `P[]`) is freed to avoid memory leaks.

### Functions for Memory Management:
1. **char* preprocessString(char* s)**:  
   Dynamically allocates memory for the transformed string.
   
2. **void freeMemory(char* processedStr, int* P)**:  
   Frees the dynamically allocated memory for both the processed string and the palindrome radius array.

## Time and Space Complexity

- **Time Complexity**:  
  The algorithm runs in **O(n)** time, where `n` is the length of the transformed string (including delimiters).
  
- **Space Complexity**:  
  The space complexity is **O(n)** due to the extra storage required for the transformed string and the palindrome radius array `P[]`.
