# Colussi Algorithm

## Description

The Colussi algorithm, also known as the KMP-Colussi algorithm, is a string matching algorithm that combines ideas from the Knuth-Morris-Pratt (KMP) algorithm and the Boyer-Moore algorithm. It was introduced by Livio Colussi in 1991. The algorithm achieves linear time complexity for string matching by utilizing the prefix function and a shifting heuristic.

### Problem Definition

Given:
- A text string T of length n
- A pattern string P of length m

Objective:
- Find all occurrences of pattern P in text T

### Algorithm Overview

1. **Preprocessing**:
   - Compute the prefix function for the pattern string
   - The prefix function helps in determining the proper shift when a mismatch occurs

2. **Searching**:
   - Scan the text from left to right
   - Compare characters of the text and pattern
   - If a match is found, continue comparing until either the end of the pattern is reached (indicating a complete match) or a mismatch occurs
   - In case of a mismatch, use the prefix function to determine the appropriate shift

### Time Complexity

- Preprocessing: O(m), where m is the length of the pattern
- Searching: O(n), where n is the length of the text
- Overall time complexity: O(n + m)

### Space Complexity

O(m), where m is the length of the pattern (for storing the prefix function)

## Implementation

The implementation in C demonstrates the Colussi algorithm for string matching. It includes:

1. Function to compute the prefix function for the pattern
2. The main string matching function implementing the Colussi algorithm
3. A demonstration of the algorithm's usage

## Usage

Compile the program and run it. The example in the main function demonstrates how to use the Colussi algorithm to find occurrences of a pattern string in a given text.

## Note

The Colussi algorithm combines the ideas of the KMP algorithm and the Boyer-Moore algorithm to achieve efficient string matching. It utilizes the prefix function for determining proper shifts and provides linear time complexity for searching patterns in a text.