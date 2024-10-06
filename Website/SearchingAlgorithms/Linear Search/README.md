# Linear Search Algorithm

## Description

Linear search is a simple search algorithm where each element in the array is checked one by one until the target value is found. It can be used for both unsorted and sorted arrays, but is less efficient than binary search for large datasets.

### Problem Definition

Given:
- An array `arr` of `n` elements.
- A target value `x` to search for.

Objective:
- Find the index of `x` in `arr`, or return `-1` if `x` is not found.

### Algorithm Overview

1. Start from the first element of the array.
2. Compare each element with `x`.
3. If `x` is found, return its index.
4. If the array is fully traversed without finding `x`, return `-1`.

### Time Complexity

The time complexity of linear search is `O(n)`, where `n` is the size of the array.
