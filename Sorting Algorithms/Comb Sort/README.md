# Comb Sort

## Description

Comb Sort is an efficient sorting algorithm that improves upon the basic bubble sort by using a gap sequence to compare and swap elements. This method eliminates small values at the end of the list, resulting in better performance.

## Problem Definition

Given:
- An array `arr` of `n` elements.

Objectives:
- Sort the array in ascending order using the Comb Sort algorithm.

## Algorithm Overview

1. **Calculate Initial Gap**: Start with a large gap (approximately the length of the array) and decrease it over time.
2. **Compare and Swap**: Compare elements that are the current gap apart. If they are in the wrong order, swap them.
3. **Shrink the Gap**: Reduce the gap using a shrink factor (commonly 1.3) and repeat the comparison and swapping until the gap becomes 1.
4. **Final Pass**: Perform a final pass with a gap of 1 to ensure all elements are sorted.

## Time Complexity

The time complexity of Comb Sort is O(n^2) in the worst case, but it can perform better than O(n log n) for many datasets.

- Best case: O(n)
- Average case: O(n log n)
- Worst case: O(n^2)

Where:
- n is the number of elements in the input array.

## Space Complexity

The space complexity is O(1) because it uses only a constant amount of additional space for swapping elements.

## Advantages

- More efficient than Bubble Sort and Insertion Sort for large lists.
- Reduces the number of comparisons and swaps.
- Simple to implement.

## Disadvantages

- Not a stable sort (equal elements may not preserve their original order).
- Performance can degrade on very small arrays.
