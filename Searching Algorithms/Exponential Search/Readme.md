
# Exponential Search

## Description

Exponential Search is an algorithm used to search for an element in a **sorted array**. It works by initially trying to find the range where the element could possibly exist by using exponentially growing indices, and then it narrows down the search using binary search within that range. This method is especially efficient when the element to be found is located near the beginning of the array, but it can be used for the entire array as well.

### Problem Definition

Given:

- A **sorted array** of `n` elements.
- A target element `x` to find in the array.

Objective:

- Find the position of the target element `x` in the array or determine that the element is not present.

### Algorithm Overview

The `Exponential Search` algorithm follows these steps:

1. Start at the beginning:

   - Check if the first element of the array matches the target `x`. If it does, return the index 0.

2. Find Range for Binary Search:

   - Start from index 1 and double the index (`2^i` for increasing `i`) until you find an index where the element at that index is greater than or equal to the target element or you reach the end of the array.

3. Perform Binary Search:

   - After finding a valid range where the element might be present, perform a **binary search** within that range to find the target element.
   - The range for binary search is `[previous_exponential_index, min(current_exponential_index, n-1)]`.

4. Return Result:

   - If the element is found, return its index.
   - If the element is not found, return `-1`.

### Algorithm Steps

1. Base Case:
   - If the target element `x` is present at index 0, return 0.

2. Exponential Step:
   - Start with index 1 and check elements at indices `2^i` (1, 2, 4, 8, 16, ...).
   - Keep doubling the index until you find an element greater than or equal to `x` or you exceed the array bounds.

3. Binary Search:
   - Perform a binary search between the last valid index and the current upper bound where the element might exist.
   - If the element is found, return its index.
   - If not found, return `-1`.

### Time Complexity

- **Best case** (when the target is near the beginning): `O(1)`.
- **Average case**: `O(log i)` where `i` is the index where the element is found or where it should be.
- **Worst case**: `O(log n)` for both the exponential search and binary search phases.

Since binary search is used after determining the range, and finding the range itself is logarithmic in nature, the overall time complexity is `O(log n)`.