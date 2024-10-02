# Knuth-Morris-Pratt (KMP) Algorithm

## Description

The Knuth-Morris-Pratt (KMP) algorithm is an efficient string matching algorithm that finds occurrences of a "word" W within a main "text string" S by employing the observation that when a mismatch occurs, the word itself embodies sufficient information to determine where the next match could begin, thus bypassing re-examination of previously matched characters.

## How it works

1. Preprocessing: Create a prefix function (failure function) for the pattern.
2. Matching: Use the prefix function to efficiently find matches in the text.

## Time Complexity

- Preprocessing: O(m), where m is the length of the pattern
- Matching: O(n), where n is the length of the text
- Overall: O(m + n)

## Space Complexity

O(m), where m is the length of the pattern (for storing the prefix function)

## Use Cases

- Efficient string searching
- Detecting plagiarism
- Analyzing genetic sequences

## Advantages

- Linear time complexity for string matching
- Efficient for large texts and patterns
- No backtracking in the main text

## Disadvantages

- Requires preprocessing of the pattern
- More complex than naive string matching algorithms