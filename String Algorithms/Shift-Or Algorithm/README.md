# Shift-Or Algorithm

## Description

The Shift-Or algorithm, also known as Shift-OR or Bitap, is an efficient string matching algorithm that uses bitwise operations. It was developed by Udi Manber and Sun Wu in 1992. The algorithm is particularly efficient for searching short patterns (up to the word size of the machine) and can be easily extended to handle approximate string matching.

### Problem Definition

Given:
- A pattern string P of length m
- A text string T of length n

Objective:
- Find all occurrences of P in T

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
- Performs well on short patterns (up to the word size of the machine)
- Can be easily extended to handle approximate matching (allowing for errors)
- Simple to implement and understand

### Time Complexity

- Preprocessing: O(m + σ), where m is the length of the pattern and σ is the size of the alphabet
- Searching: O(n), where n is the length of the text
- Total: O(n + m + σ)

### Space Complexity

O(σ), where σ is the size of the alphabet

## Implementation

The implementation in C demonstrates the Shift-Or algorithm for exact string matching. It includes:

1. A function to preprocess the pattern and create bit masks
2. The main search function implementing the Shift-Or algorithm
3. A demonstration of the algorithm's usage

## Usage

Compile the program and run it. The example in the main function demonstrates how to use the Shift-Or algorithm to find a pattern in a given text.

## Limitations

- The current implementation assumes a 64-bit word size. For patterns longer than 64 characters, modifications would be needed.
- This implementation demonstrates exact matching. For approximate matching, additional modifications would be required.

## Extensions

- The algorithm can be extended to handle approximate matching by using multiple bit vectors to represent different error levels.
- It can also be modified to find the best approximate match rather than just exact matches.