# Permutations and Combinations

## Description

**Permutations** and **Combinations** are two fundamental concepts in combinatorics. They are used to describe how objects from a set can be selected and arranged.

- **Permutations**: The arrangement of all or part of a set of objects, where the order of selection matters.
- **Combinations**: The selection of all or part of a set of objects, where the order of selection does not matter.

### Problem Definition

Given:
- A set of `n` distinct objects.
- A selection of `r` objects from the set.

Objective:
- For permutations, calculate the number of ways to arrange `r` objects from `n`.
- For combinations, calculate the number of ways to select `r` objects from `n`.

### Example

For a set `{A, B, C}`, the permutations for selecting 2 objects are:

- `AB`, `BA`, `AC`, `CA`, `BC`, `CB`.

The combinations for selecting 2 objects are:

- `AB`, `AC`, `BC`.

### Algorithm Overview

**Permutations**:
1. Choose an element from the set.
2. Recur for the remaining elements and generate all possible arrangements.
3. Backtrack after considering each element to explore other possibilities.

**Combinations**:
1. For each element, choose whether to include it in the subset or not.
2. Recur for the remaining elements.

### Time Complexity

- **Permutations**: `O(n!)` where `n!` is the factorial of `n`.
- **Combinations**: `O(2^n)` due to the binary choice for each element.

### Applications

Permutations and combinations are used in:
- Probability and statistics.
- Game theory.
- Cryptography.
