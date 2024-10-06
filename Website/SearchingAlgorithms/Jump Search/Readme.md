# Jump Search Algorithm

## Description

Jump search is an efficient search algorithm for sorted arrays. It works by dividing the array into blocks of a fixed size and performing a linear search within the block where the target value is likely to be found. This method reduces the number of comparisons needed compared to linear search while maintaining a straightforward implementation.

## Problem Definition

**Given:**
- A sorted array `arr` of `n` elements.
- A target value `x` to search for.
- A jump size `m`, which determines how far to jump in the array.

**Objective:**
- Find the index of `x` in `arr`, or return `-1` if `x` is not present in the array.

## Algorithm Overview

1. **Initialization**:
   - Set the jump size `m` (typically `sqrt(n)`).
   - Initialize `prev` to `0` and `curr` to `0`.

2. **Jump Phase**:
   - While `curr` is less than `n` and `arr[curr]` is less than `x`:
     - Update `prev` to `curr`.
     - Move `curr` forward by `m` steps (i.e., `curr += m`).

3. **Linear Search Phase**:
   - Perform a linear search in the range from `prev` to the minimum of `curr` and `n`:
     - If `arr[i]` equals `x`, return `i`.

4. **Conclusion**:
   - If the target value is not found, return `-1`.

## Time Complexity

The time complexity of the jump search algorithm is `O(√n)` for searching and `O(√n)` for the linear search within a block, making it more efficient than linear search for larger datasets, though not as efficient as binary search for sorted arrays.

