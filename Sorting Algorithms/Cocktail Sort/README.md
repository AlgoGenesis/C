# Cocktail Sort

## Description

Cocktail Sort is a variation of Bubble Sort that sorts the array in both directions, making it more efficient than standard Bubble Sort. It traverses the list in a bidirectional manner, moving large elements to the end and small elements to the start during each iteration. This approach minimizes the number of unnecessary comparisons and improves performance on nearly sorted arrays.

## Problem Definition

Given:
- An array `arr` of `n` elements.

Objectives:
- Sort the array in ascending order using the Cocktail Sort algorithm.

## Algorithm Overview

1. **Forward Pass**: Traverse the array from left to right, comparing adjacent elements. If two elements are in the wrong order, swap them. Move the largest element to its correct position at the end of the array.
2. **Backward Pass**: Traverse the array from right to left, comparing adjacent elements. If two elements are in the wrong order, swap them. Move the smallest element to its correct position at the beginning of the array.
3. **Repeat**: Repeat the forward and backward passes until no swaps are made during a complete traversal, indicating that the array is sorted.

## Time Complexity

The time complexity of Cocktail Sort is O(n²) in the worst case, similar to Bubble Sort. However, it can perform better on nearly sorted arrays.

- Best case: O(n) (when the array is nearly sorted)
- Average case: O(n²)
- Worst case: O(n²)

Where:
- n is the number of elements in the input array.

## Space Complexity

The space complexity is O(1) because it only uses a constant amount of additional space for temporary variables during the swapping process.

## Advantages

- More efficient than Bubble Sort for nearly sorted data due to its bidirectional nature.
- Simple and easy to implement.

## Disadvantages

- The worst-case performance is still O(n²), which makes it inefficient for large datasets.
- It is not a stable sort (equal elements may not preserve their original order).

## Conclusion

Cocktail Sort is a simple and intuitive sorting algorithm that improves upon Bubble Sort by making use of bidirectional traversal. While not suitable for very large datasets, it can be a good choice for smaller or nearly sorted arrays where it performs quite efficiently.
