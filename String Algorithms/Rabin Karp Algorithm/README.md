# Rabin-Karp Algorithm

## Description

The Rabin-Karp algorithm is used to search for a pattern in a text by comparing hash values. It is efficient in finding multiple pattern matches within the text by sliding the pattern over the text and checking the hash value at each step.

### Problem Definition

Given:
- A string `txt` of length `n`.
- A pattern `pat` of length `m`.

Objective:
- Find the starting indices of all occurrences of `pat` in `txt`.

### Algorithm Overview

1. Compute the hash value of the pattern and the initial window of the text.
2. Slide the pattern over the text, updating the hash value for each new window.
3. Compare the hash values. If they match, verify the characters one by one.
4. If a match is found, return the starting index.

### Time Complexity

- **Average case**: `O(n + m)`
- **Worst case**: `O(n * m)` (due to hash collisions)
