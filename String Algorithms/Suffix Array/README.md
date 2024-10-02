# Suffix Array

## Description

A Suffix Array is a sorted array of all suffixes of a given string. It allows for efficient string matching and is often used in conjunction with the LCP (Longest Common Prefix) array for various string processing tasks.

## How it works

1. Generate all suffixes of the string.
2. Sort the suffixes lexicographically.
3. Store the starting indices of the sorted suffixes.

## Time Complexity

O(n log n) for construction using efficient algorithms

## Space Complexity

O(n)

## Use Cases

- Pattern matching
- Finding the longest repeated substring
- Data compression algorithms

## Advantages

- Allows for binary search on suffixes
- Efficient for various string processing tasks

## Disadvantages

- Construction can be complex
- Requires additional space