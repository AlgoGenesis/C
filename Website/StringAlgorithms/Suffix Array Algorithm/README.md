# Suffix Array Algorithm

## Description

The Suffix Array Algorithm is a powerful data structure used for efficient string processing. It represents all suffixes of a string in lexicographically sorted order, allowing for fast pattern matching and other string operations.

### Problem Definition

Given:
- A string S of length n

Objective:
- Construct a suffix array for S, which is an array of integers giving the starting positions of suffixes of S in lexicographical order.

### Algorithm Overview

1. **Generate Suffixes**: Create all suffixes of the input string.
2. **Sort Suffixes**: Sort the suffixes lexicographically.
3. **Create Suffix Array**: Store the starting indices of the sorted suffixes.

### Key Features

- Enables efficient string matching and longest common prefix (LCP) computations
- Supports various string processing tasks like finding repeating substrings
- Often used in bioinformatics for genome analysis

### Time Complexity

- Naive implementation: O(n^2 log n), where n is the length of the string
- Optimized implementations can achieve O(n log n) or even O(n) time complexity

### Space Complexity

O(n) for storing the suffix array

## Implementation

The implementation in C demonstrates a basic Suffix Array Algorithm. It includes:

1. A structure to represent suffixes
2. A comparison function for sorting suffixes
3. A function to build the suffix array
4. A function to print the suffix array
5. A demonstration of the algorithm's usage

## Usage

Compile the program and run it. The example in the main function demonstrates how to use the Suffix Array Algorithm to construct and print the suffix array for a given string.

## Note

This implementation uses a naive O(n^2 log n) approach for simplicity and clarity. For large strings or performance-critical applications, more efficient algorithms like SA-IS (Suffix Array - Induced Sorting) should be considered.