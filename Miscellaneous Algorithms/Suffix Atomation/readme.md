# Suffix Array and Suffix Tree Algorithm in C

Welcome to the **Suffix Array and Suffix Tree** algorithm implementation in C. This project demonstrates how to build and use both the **Suffix Array** and **Suffix Tree** for efficient string pattern matching, substring search, and more advanced string processing tasks.

## Overview

The **Suffix Array** and **Suffix Tree** are powerful data structures designed to represent all possible suffixes of a given string in a way that facilitates efficient search operations. These structures are used in various applications, such as **full-text indexing**, **string matching**, **genomics**, and **data compression**.

### Key Features
- **Suffix Array**: A sorted array of all suffixes of a given string.
- **Suffix Tree**: A compressed trie of all suffixes of a string, providing faster string matching.
- Both structures support operations like pattern matching, longest common prefix (LCP), and substring search.
- Efficient construction and searching algorithms.

## Algorithm Explanation

### Suffix Array

The **Suffix Array** of a string is a sorted array of all suffixes of that string. It allows you to perform various string operations in logarithmic time, making it highly useful in fields like bioinformatics.

#### Steps to Construct a Suffix Array:
1. Generate all suffixes of the input string.
2. Sort the suffixes lexicographically.
3. Store the starting indices of these sorted suffixes in an array.

#### Applications of Suffix Array:
- Efficient pattern matching.
- Finding the longest repeated substring.
- Fast substring search.

### Suffix Tree

The **Suffix Tree** is a compressed trie of all suffixes of a string. It provides extremely fast searching capabilities, often linear in time.

#### Steps to Construct a Suffix Tree:
1. Start from an empty tree and add each suffix of the string one by one.
2. Use **Ukkonen's Algorithm** for efficient construction in linear time.

#### Applications of Suffix Tree:
- Fast string matching and pattern searching.
- Finding the longest common substring between two strings.
- Solving problems like finding the **Longest Palindromic Substring**.

## Files in this Repository

- `suffix_array.c`: Contains the implementation of the Suffix Array.
- `suffix_tree.c`: Contains the implementation of the Suffix Tree.
- `README.md`: Project documentation (this file).

## Installation and Compilation

To compile and run the Suffix Array and Suffix Tree programs:

1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/Suffix-Algorithm.git

   cd Suffix-Algorithm

   gcc suffix_array.c -o suffix_array

   gcc suffix_tree.c -o suffix_tree

    ./suffix_array
    ./suffix_tree




This README file provides an overview of the **Suffix Array** and **Suffix Tree** algorithms, explains their use cases, and includes steps for compiling and running the program in C.
