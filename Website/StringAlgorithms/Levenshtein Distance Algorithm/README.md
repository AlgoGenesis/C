# Levenshtein Distance Algorithm

## Description

The Levenshtein Distance Algorithm, also known as Edit Distance, is a string metric for measuring the difference between two sequences. It calculates the minimum number of single-character edits (insertions, deletions, or substitutions) required to change one word into another.

### Problem Definition

Given:
- Two strings str1 and str2

Objective:
- Calculate the minimum number of operations required to transform str1 into str2

### Algorithm Overview

1. **Initialize Matrix**: Create a matrix with (m+1) rows and (n+1) columns, where m and n are the lengths of str1 and str2 respectively.
2. **Fill First Row and Column**: Fill the first row and column with incremental values (0, 1, 2, ...).
3. **Fill Rest of Matrix**: For each cell (i, j) in the matrix:
   - If characters match, copy the value from (i-1, j-1).
   - If characters don't match, take the minimum of (i-1, j), (i, j-1), and (i-1, j-1) and add 1.
4. **Return Result**: The value in the bottom-right cell of the matrix is the Levenshtein distance.

### Key Features

- Measures similarity between two strings
- Accounts for insertions, deletions, and substitutions
- Widely used in spell checking, DNA sequence alignment, and plagiarism detection

### Time Complexity

O(mn), where m and n are the lengths of the two strings

### Space Complexity

O(mn) for the standard implementation, but can be optimized to O(min(m,n))

## Implementation

The implementation in C demonstrates the Levenshtein Distance Algorithm. It includes:

1. A function to calculate the Levenshtein distance between two strings
2. Helper functions to find the minimum of three integers and print the distance matrix
3. A demonstration of the algorithm's usage

## Usage

Compile the program and run it. The example in the main function demonstrates how to use the Levenshtein Distance Algorithm to calculate the edit distance between two strings.