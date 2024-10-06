# Binary Search Algorithm

## Description

Binary search is a fast search algorithm that finds the position of a target value within a sorted array. It works by repeatedly dividing the search interval in half. If the value of the search key is less than the item in the middle of the interval, the search continues in the lower half, or if greater, it continues in the upper half. This process is repeated until the value is found or the interval is empty.

### Problem Definition

Given:
- A sorted array `arr` of `n` elements.
- A target value `x` to search for.

Objective:
- Find the index of `x` in `arr`, or return `-1` if `x` is not present in the array.

### Algorithm Overview

1. Initialize two pointers, `left` and `right`, to the first and last index of the array, respectively.
2. While `left` is less than or equal to `right`:
   - Calculate the middle index `mid`.
   - If `arr[mid]` equals `x`, return `mid`.
   - If `arr[mid]` is less than `x`, move the `left` pointer to `mid + 1`.
   - If `arr[mid]` is greater than `x`, move the `right` pointer to `mid - 1`.
3. If the target value is not found, return `-1`.

### Time Complexity

The time complexity of the binary search algorithm is `O(log n)`, making it much more efficient than linear search for large datasets.

