# Cocktail Shaking Sort

## Description

Cocktail Shaking Sort is a variation of Bubble Sort. It differs from Bubble Sort by traversing the list in both directions alternatively. This allows the algorithm to move both the largest and smallest elements towards their correct positions, improving the performance compared to the traditional Bubble Sort in some cases.

## Problem Definition

Given:
- An array `arr` of `n` elements.

Objectives:
- Sort the array in ascending order using the Cocktail Shaking Sort algorithm.

## Algorithm Overview

1. **Iterate in both directions**: 
   - Traverse the array from left to right, swapping adjacent elements if they are in the wrong order. 
   - After reaching the end, reverse the direction and traverse from right to left, swapping elements as necessary.
2. **Reduce bounds**: 
   - After each complete left-to-right and right-to-left pass, the next pass ignores the elements that are already sorted at the ends of the array.
3. **Repeat until sorted**: 
   - Continue this process until no more swaps are necessary in a complete pass.

## Time Complexity

The time complexity of Cocktail Shaking Sort is O(n^2), where:
- **n** is the number of elements in the array.

### Case-wise complexities:
- **Best case**: O(n) (when the array is already sorted)
- **Average case**: O(n^2)
- **Worst case**: O(n^2)

## Space Complexity

The space complexity is O(1) as Cocktail Shaking Sort operates in-place and does not require any additional memory.

## Advantages

- Provides better performance than Bubble Sort in some cases.
- Useful for nearly sorted arrays, as it reduces unnecessary comparisons by handling both ends of the array.

## Disadvantages

- Inefficient for large datasets.
- Still has a time complexity of O(n^2), making it less optimal compared to advanced algorithms like quicksort or mergesort.

## Code Implementation

You can find the C implementation of Cocktail Shaking Sort in the `program.c` file.
