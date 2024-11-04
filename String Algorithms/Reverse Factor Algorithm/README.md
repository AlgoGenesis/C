# Reverse Factor Algorithm

## Description

The Reverse Factor Algorithm is a string-searching algorithm that checks if the reverse of a given pattern appears as a substring within a text. It can be applied in various situations where reverse-pattern matching is required, such as palindrome detection or specific text searching.

### Problem Definition

Given:
- A text string `T` of length `n`
- A pattern string `P` of length `m`

Objective:
- Find if the reverse of pattern `P` is present in text `T` and report its position.

### Algorithm Overview

1. **Reverse the Pattern**: Reverse the characters of the pattern string `P`.
2. **Search for the Reversed Pattern**: 
   - Slide the reversed pattern over the text one character at a time.
   - For each window of length `m` in the text, compare it with the reversed pattern.
3. **Report Matches**: If the reversed pattern matches a substring in the text, report the starting index.

### Key Features

- Simple string comparison to check for reversed pattern matches
- Applicable for reverse pattern detection in text or similar tasks
- Time complexity is linear with respect to the length of the text for most cases

### Time Complexity

- Best and Average Case: O(n)
- Worst Case: O(n * m), occurs when there are many partial matches in the text.

### Space Complexity

O(m), where `m` is the length of the pattern, as we store a reversed copy of the pattern.

## Implementation

The C implementation of the Reverse Factor Algorithm involves:

1. A function to reverse the given pattern string.
2. A function to check if the reversed pattern is a substring of the text.
3. A main function that demonstrates the usage of the algorithm.

## Usage

Compile the program and run it. The example in the `main` function shows how the Reverse Factor Algorithm works by finding if the reverse of a given pattern is present in a text string.