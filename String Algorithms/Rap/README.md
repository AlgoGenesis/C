# Find the Index of the First Occurrence in a String (KMP Algorithm in C)

## Description

The "Find the Index of the First Occurrence in a String" problem is about finding the first index where a substring (needle) appears in a main string (haystack). The KMP (Knuth-Morris-Pratt) algorithm is an efficient solution that preprocesses the pattern to minimize unnecessary comparisons during the search.

### Problem Definition

Given:
- A string `haystack` (the text).
- A string `needle` (the pattern to search for).

Objective:
- Return the index of the first occurrence of the `needle` in the `haystack`. If the `needle` is not found, return `-1`.

### Algorithm Overview

1. **Preprocess the Pattern**: 
   - Create the LPS (Longest Prefix Suffix) array that helps skip redundant comparisons.
   
2. **Search the Text**: 
   - Traverse through the `haystack` while adjusting the search position using the LPS array.

### Time Complexity

- **Preprocessing (LPS array)**: O(m), where `m` is the length of the `needle`.
- **Searching**: O(n), where `n` is the length of the `haystack`.

Overall time complexity: O(n + m).

### Space Complexity

- **Space Complexity**: O(m), for storing the LPS array.

## Usage

The program will search for the first occurrence of the `needle` in the `haystack` and print the index if found, or indicate that the `needle` was not found.

### Example

For input:

- `haystack = "hello"`
- `needle = "ll"`

The program will output:

```
First occurrence of needle found at index: 2
```

## Key Features

- **Efficient Search**: The KMP algorithm avoids redundant comparisons by using the LPS array, making it more efficient than naive string search methods.
- **LPS Preprocessing**: The LPS array allows the algorithm to skip portions of the text when mismatches are found, speeding up the search process.