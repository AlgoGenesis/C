# Rabin-Karp Algorithm

## Description

The Rabin-Karp algorithm is a string searching algorithm that uses hashing to find an occurrence of a pattern in a text. It is particularly useful when searching for multiple patterns in a text.

### Problem Definition

Given:
- A text `text` of length `n`.
- A pattern `pattern` of length `m`.

Objective:
- Find all occurrences of `pattern` in `text`.

### Algorithm Overview

1. Precompute the hash of the pattern and the hash of the first window of text.
2. Slide the pattern over the text:
   - If the hash values match, check the characters one by one.
   - If the characters match, return the starting index of the occurrence.
   - Recompute the hash for the next window efficiently.
3. Repeat the process until the pattern is found or the text ends.

### Time Complexity

- The average time complexity of Rabin-Karp is `O(n + m)` for searching a single pattern.
- The worst-case time complexity can be `O(n*m)` in cases of hash collisions.
