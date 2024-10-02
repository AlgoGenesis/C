# Manacher's Algorithm

## Description

Manacher's Algorithm is a linear-time algorithm for finding the longest palindromic substring in a string. It's an optimization over the naive approach which would take O(n^2) time.

## How it works

1. Preprocess the string by inserting special characters between each character and at the ends.
2. Compute the LPS (Longest Palindromic Substring) array.
3. Use the LPS array to find the longest palindrome.

## Time Complexity

O(n), where n is the length of the string

## Space Complexity

O(n)

## Use Cases

- Finding the longest palindromic substring
- Text analysis and processing
- Bioinformatics (DNA sequence analysis)

## Advantages

- Linear time complexity
- Finds all palindromes in one pass

## Disadvantages

- Can be complex to understand and implement
- Requires additional space for the LPS array