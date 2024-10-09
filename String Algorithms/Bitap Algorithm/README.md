# Bitap Algorithm (Shift-Or / Shift-And)

## Description

The Bitap algorithm, also known as the Shift-Or or Shift-And algorithm, is an approximate string matching algorithm. It was developed by Udi Manber and Sun Wu in 1991. The algorithm is particularly efficient for searching short patterns (up to the word size of the machine) and can be easily extended to handle fuzzy string matching.

### Problem Definition

Given:
- A pattern string P of length m
- A text string T of length n
- (Optional) A maximum number of allowed errors k

Objective:
- Find all occurrences of P in T, possibly with up to k errors

### Algorithm Overview

1. **Preprocessing**:
   - Compute a bit mask for each character in the alphabet

2. **Searching**:
   - Initialize the state as a bit vector
   - For each character in the text:
     - Update the state using bitwise operations
     - Check if the state represents a match

### Key Features

- Uses bit-parallelism for efficient computation
- Can be easily extended to handle fuzzy matching (allowing for errors)
- Performs well on short patterns (up to the word size of the machine)
- Can be implemented using either Shift-Or or Shift-And logic

### Time Complexity

- Preprocessing: O(m + σ), where m is the length of the pattern and σ is the size of the alphabet
- Searching: O(n), where n is the length of the text
- Total: O(n + m + σ)

### Space Complexity

O(σ), where σ is the size of the alphabet

## Implementation

The implementation in C demonstrates the Bitap algorithm for exact string matching. It includes:

1. A function to preprocess the pattern and create bit masks
2. The main search function implementing the Bitap algorithm
3. A demonstration of the algorithm's usage

## Usage

Compile the program and run it. The example in the main function demonstrates how to use the Bitap algorithm to find a pattern in a given text.

## Limitations

- The current implementation assumes a 64-bit word size. For patterns longer than 64 characters, modifications would be needed.
- This implementation demonstrates exact matching. For fuzzy matching, additional modifications would be required.

## Extensions

- The algorithm can be extended to handle fuzzy matching by using multiple bit vectors to represent different error levels.
- It can also be modified to find the best approximate match rather than just exact matches.