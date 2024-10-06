# Rabin-Karp Algorithm

## Description

The Rabin-Karp algorithm is an efficient string-searching algorithm that uses hashing to find patterns in strings. It's particularly useful for multi-pattern string matching and plagiarism detection.

### Problem Definition

Given:
- A text string T of length n
- A pattern string P of length m

Objective:
- Find all occurrences of P in T

### Algorithm Overview

1. **Compute Hash**: Calculate hash values for the pattern P and the first m characters of T.
2. **Sliding Window**: Slide the pattern over the text one character at a time:
   - Recalculate the hash value for the current window of T.
   - If the hash values match, compare the window with the pattern character by character.
3. **Report Matches**: If a full match is found, report the starting index.

### Key Features

- Uses rolling hash function for efficient computation
- Performs character comparisons only when hash values match
- Average and best-case time complexity: O(n+m)
- Worst-case time complexity: O(nm)

### Time Complexity

- Average and Best Case: O(n+m)
- Worst Case: O(nm), occurs when there are many hash collisions

### Space Complexity

O(1), as it only uses a constant amount of extra space.

## Implementation

The implementation in C demonstrates the Rabin-Karp algorithm for single pattern matching in a given text. It includes:

1. A function to compute the hash value
2. The main Rabin-Karp function to find pattern occurrences
3. A demonstration of the algorithm's usage

## Usage

Compile the program and run it. The example in the main function demonstrates how to use the Rabin-Karp algorithm to find a pattern in a given text.