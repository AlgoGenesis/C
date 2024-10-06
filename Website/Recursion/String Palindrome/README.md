# String Palindrome Using Recursion

## Description

A palindrome is a string that reads the same forward and backward. To check whether a string is a palindrome, we can use a recursive approach. The idea is to compare the characters at the beginning and end of the string and gradually move inward.

### Problem Definition

Given a string `s`, determine whether it is a palindrome by recursively comparing its characters.

### Examples:
- **Input**: "racecar"  
  **Output**: True (since "racecar" reads the same forward and backward)
  
- **Input**: "hello"  
  **Output**: False (since "hello" is not a palindrome)

### Algorithm Overview

1. **Base Case**:  
   - If the start index becomes greater than or equal to the end index, the string is a palindrome, so return `True`.
   
2. **Recursive Case**:  
   - Compare the characters at the start and end indices. If they are equal, recursively check the substring that excludes these characters (i.e., move inward). If they are not equal, return `False` as the string is not a palindrome.

### Detailed Steps:

1. **Function Definition**: Define a recursive function `isPalindrome(s, start, end)` where `start` and `end` represent the indices of the string to be compared.
2. **Base Condition**: If `start >= end`, return `True`.
3. **Recursive Call**: If `s[start] == s[end]`, call `isPalindrome(s, start + 1, end - 1)` to check the inner substring.
4. **Return Result**: If at any point `s[start] != s[end]`, return `False`.

### Time Complexity

The time complexity of this recursive solution is **O(n)**, where `n` is the length of the string. We make approximately `n/2` comparisons as the recursion progresses from the outer characters inward.
