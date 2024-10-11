# Subset Sum Problem

## Description

The **Subset Sum Problem** is a decision problem in computer science. It asks whether there is a subset of a given set of numbers such that the sum of the elements in the subset is equal to a given target value.

### Problem Definition

Given:
- A set of `n` integers.
- A target sum `S`.

Objective:
- Determine whether there is a subset of the given set whose sum equals `S`.

### Example

Consider the set `{3, 34, 4, 12, 5, 2}` and target sum `S = 9`.

- The subset `{4, 5}` sums up to `9`, so the answer is `True`.

### Algorithm Overview

This is a classic backtracking problem. The algorithm tries to include each element of the set in the subset or exclude it and checks if the sum of the included elements matches the target value.

Steps:
1. Start with an empty subset.
2. For each element in the set, either:
   - Include the element in the subset and reduce the remaining sum.
   - Exclude the element and move to the next one.
3. If the remaining sum becomes `0`, return `True` (a valid subset is found).
4. If all elements are processed and no valid subset is found, return `False`.

### Time Complexity

- **Worst-case**: `O(2^n)` due to the combinatorial nature of trying all possible subsets.

### Applications

The Subset Sum Problem is closely related to problems in cryptography, resource allocation, and scheduling.
