# Bit-parallel Nondeterministic DAWG Matching (BNDM) Algorithm

## Description

The Bit-parallel Nondeterministic DAWG (Directed Acyclic Word Graph) Matching (BNDM) algorithm is an efficient string matching algorithm that combines bit-parallelism with the concept of a nondeterministic automaton. It was developed by Gonzalo Navarro and Mathieu Raffinot in 1998. This algorithm is particularly useful for searching for a pattern within a large text, especially when the pattern is relatively short (up to the word size of the machine).

### Problem Definition

Given:
- A pattern string P of length m
- A text string T of length n

Objective:
- Find all occurrences of P in T

### Algorithm Overview

1. **Preprocessing**:
   - Compute a bit mask for each character in the alphabet
   - Initialize the automaton state

2. **Searching**:
   - Scan the text from right to left within a window of size m
   - Use bit-parallel operations to update the automaton state
   - When a match is found, shift the window and continue

### Key Features

- Uses bit-parallelism to simulate a nondeterministic automaton
- Performs well on short patterns (up to the word size of the machine)
- Can be extended to multiple pattern matching
- Efficient for small alphabets

### Time Complexity

- Preprocessing: O(m + σ), where m is the length of the pattern and σ is the size of the alphabet
- Searching: O(n*m) worst case, but O(n*logσ(m)/m) on average
- Best case: O(n/m)

### Space Complexity

O(σ), where σ is the size of the alphabet

## Implementation

The implementation in C demonstrates the BNDM algorithm for string matching. It includes:

1. A function to preprocess the pattern and create bit masks
2. The main search function implementing the BNDM algorithm
3. A demonstration of the algorithm's usage

## Usage

Compile the program and run it. The example in the main function demonstrates how to use the BNDM algorithm to find a pattern in a given text.

## Limitations

- The current implementation assumes a 32-bit word size. For patterns longer than 32 characters, modifications would be needed.
- The algorithm is most efficient for patterns shorter than or equal to the word size of the machine.