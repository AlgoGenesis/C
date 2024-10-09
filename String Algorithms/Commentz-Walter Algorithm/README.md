# Commentz-Walter Algorithm

## Description

The Commentz-Walter algorithm is an efficient algorithm for multiple string matching. It was developed by Beate Commentz-Walter in 1979 as an extension of the Boyer-Moore string searching algorithm to handle multiple patterns simultaneously. This algorithm is particularly useful when searching for multiple patterns in a large text.

### Problem Definition

Given:
- A set of pattern strings P = {p1, p2, ..., pk}
- A text string T

Objective:
- Find all occurrences of any pattern from P in T

### Algorithm Overview

1. **Preprocessing**:
   - Construct a trie of the reversed patterns
   - Compute shift functions similar to Boyer-Moore (bad character and good suffix)
   - Compute an output function for the trie nodes

2. **Searching**:
   - Scan the text from left to right
   - Use the shift functions to skip characters
   - When a potential match is found, verify it using the trie

### Key Features

- Combines ideas from Aho-Corasick and Boyer-Moore algorithms
- Efficient for multiple pattern matching
- Uses both character and substring information for shifting
- Can be more efficient than Aho-Corasick for certain pattern sets

### Time Complexity

- Preprocessing: O(m), where m is the total length of all patterns
- Searching: O(n + m + z) in the worst case, where n is the length of the text and z is the number of occurrences
- In practice, it can achieve sublinear time complexity in many cases

### Space Complexity

O(m), where m is the total length of all patterns

## Implementation

The implementation in C demonstrates a simplified version of the Commentz-Walter algorithm for multiple string matching. It includes:

1. Trie structure for storing reversed patterns
2. Functions to build the trie and compute shift values
3. The main search function implementing the Commentz-Walter algorithm
4. A demonstration of the algorithm's usage

## Usage

Compile the program and run it. The example in the main function demonstrates how to use the Commentz-Walter algorithm to find multiple patterns in a given text.

## Limitations

- This implementation is a simplified version and may not include all optimizations of the full Commentz-Walter algorithm.
- The implementation uses fixed-size arrays for simplicity, which may need to be adjusted for very large pattern sets or alphabets.

## Note

The Commentz-Walter algorithm can be complex to implement fully with all optimizations. This implementation provides a basic version to demonstrate the core concepts of the algorithm.