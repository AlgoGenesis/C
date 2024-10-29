# Two-Way String-Matching Algorithm

## Description

The Two-Way String-Matching algorithm, developed by Crochemore and Perrin in 1991, is an efficient pattern matching algorithm that improves upon the Boyer-Moore algorithm by scanning the pattern in both directions. It combines forward and backward pattern scanning to achieve optimal searching in linear time.

### Problem Definition

Given:
- A pattern string P of length m
- A text string T of length n

Objective:
- Find all occurrences of P in T

### Algorithm Overview

1. **Pattern Analysis**:
   - Factorize the pattern into two parts
   - Compute the critical factorization point
   - Analyze pattern periodicity

2. **Searching Phase**:
   - Perform forward scan until a mismatch or potential match
   - For potential matches, perform backward scan
   - Use period information to make maximal shifts

### Key Features

- Combines advantages of Boyer-Moore and Knuth-Morris-Pratt algorithms
- Uses bidirectional pattern scanning
- Achieves optimal worst-case complexity
- Performs well on both short and long patterns
- Particularly efficient for patterns with low periodicity

### Time Complexity

- Preprocessing: O(m), where m is the length of the pattern
- Searching: O(n), where n is the length of the text
- Total: O(n + m)
- In practice, achieves sublinear time on many inputs

### Space Complexity

O(m), where m is the length of the pattern

## Implementation

The implementation in C demonstrates the Two-Way String-Matching algorithm for exact string matching. It includes:

1. Functions to analyze the pattern and find its critical factorization
2. The main two-way search algorithm
3. Helper functions for period computation
4. A demonstration of the algorithm's usage

## Usage

Compile the program and run it. The example in the main function demonstrates how to use the Two-Way String-Matching algorithm to find all occurrences of a pattern in a given text.

## Advantages

- Better average-case performance compared to classic algorithms
- Optimal worst-case complexity
- No preprocessing of the text required
- Efficient handling of patterns with non-trivial periods
- Suitable for both short and long patterns

## Limitations

- More complex implementation compared to simpler algorithms
- Preprocessing phase requires careful handling of pattern periodicity
- Memory usage proportional to pattern length

## Applications

- Text editors and word processors
- Bioinformatics sequence matching
- Network packet inspection
- Data compression algorithms
- Digital forensics