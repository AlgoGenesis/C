# Z Algorithm

## Description

The Z Algorithm is a linear time string matching algorithm that finds all occurrences of a pattern in a text. It's particularly efficient for its ability to preprocess the pattern in linear time and perform the matching process without backtracking.

### Problem Definition

Given:
- A pattern string P of length m
- A text string T of length n

Objective:
- Find all occurrences of P in T

### Algorithm Overview

1. **Concatenate Strings**: Create a new string S = P$T, where $ is a character not present in P or T.
2. **Construct Z Array**: Build the Z array for S, where Z[i] is the length of the longest substring starting from S[i] that is also a prefix of S.
3. **Find Matches**: Identify positions in the Z array where Z[i] equals the pattern length m.

### Key Features

- Linear time complexity for both preprocessing and matching
- Efficient for multiple pattern searches in the same text
- No backtracking during the matching process
- Can be easily modified for various string matching problems

### Time Complexity

O(m + n), where m is the length of the pattern and n is the length of the text

### Space Complexity

O(m + n) to store the concatenated string and Z array

## Implementation

The implementation in C demonstrates the Z Algorithm for string matching. It includes:

1. A function to construct the Z array
2. A function to perform string matching using the Z Algorithm
3. A demonstration of the algorithm's usage

## Usage

Compile the program and run it. The example in the main function demonstrates how to use the Z Algorithm to find all occurrences of a pattern in a given text.