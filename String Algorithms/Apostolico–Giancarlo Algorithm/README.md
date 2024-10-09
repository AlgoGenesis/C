# Apostolico-Giancarlo Algorithm

## Description

The Apostolico-Giancarlo algorithm is an efficient string matching algorithm that improves upon the Boyer-Moore algorithm. It was developed by Alberto Apostolico and Raffaele Giancarlo in 1986. This algorithm is particularly useful for searching for a pattern within a large text, especially when the pattern is relatively long.

### Problem Definition

Given:
- A pattern string P of length m
- A text string T of length n

Objective:
- Find all occurrences of P in T

### Algorithm Overview

1. **Preprocessing**:
   - Compute the Boyer-Moore bad character heuristic
   - Compute the Boyer-Moore good suffix heuristic
   - Compute the match skip array

2. **Searching**:
   - Align the pattern with the beginning of the text
   - Compare characters from right to left
   - Use the preprocessed information to skip unnecessary comparisons
   - Use the match skip array to avoid redundant comparisons

### Key Features

- Combines the advantages of the Boyer-Moore algorithm with additional optimizations
- Uses a match skip array to avoid redundant comparisons
- Performs well on both short and long patterns
- Particularly efficient for long patterns and large alphabets

### Time Complexity

- Preprocessing: O(m + σ), where m is the length of the pattern and σ is the size of the alphabet
- Best case: O(n/m)
- Worst case: O(n)
- Average case: O(n/m)

### Space Complexity

O(m + σ), where m is the length of the pattern and σ is the size of the alphabet

## Implementation

The implementation in C demonstrates the Apostolico-Giancarlo algorithm for string matching. It includes:

1. Functions to preprocess the pattern (bad character, good suffix, and match skip)
2. The main search function implementing the Apostolico-Giancarlo algorithm
3. A demonstration of the algorithm's usage

## Usage

Compile the program and run it. The example in the main function demonstrates how to use the Apostolico-Giancarlo algorithm to find a pattern in a given text.