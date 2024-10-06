# Aho-Corasick Algorithm

## Description

The Aho-Corasick algorithm is an efficient string matching algorithm used to find occurrences of multiple patterns in a given text simultaneously. It's particularly useful for applications such as virus scanning, intrusion detection systems, and DNA sequence analysis.

### Problem Definition

Given:
- A set of pattern strings P = {p1, p2, ..., pk}
- A text string T

Objective:
- Find all occurrences of any pattern from P in T

### Algorithm Overview

1. **Construct Trie**: Build a trie (prefix tree) from the set of patterns.
2. **Add Failure Links**: Construct failure links for each node in the trie.
3. **Add Output Links**: Add output links to nodes where patterns end.
4. **Search Text**: Traverse the text using the constructed automaton to find matches.

### Key Features

- Preprocesses the patterns to build an efficient automaton
- Searches for all patterns simultaneously in a single pass through the text
- Handles overlapping patterns efficiently
- Time complexity is linear in the sum of the pattern lengths, text length, and number of outputs

### Time Complexity

- Preprocessing: O(m), where m is the sum of the lengths of all patterns
- Searching: O(n + z), where n is the length of the text and z is the number of pattern occurrences

### Space Complexity

O(m), where m is the sum of the lengths of all patterns

## Implementation

The implementation in C demonstrates the Aho-Corasick algorithm for multi-pattern string matching. It includes:

1. A trie structure to represent the automaton
2. Functions to build the trie and add failure and output links
3. A search function to find all pattern occurrences in the text
4. A demonstration of the algorithm's usage

## Usage

Compile the program and run it. The example in the main function demonstrates how to use the Aho-Corasick algorithm to find multiple patterns in a given text.