# Cocktail Shaker Sort

## Description
Cocktail Shaker Sort, also known as Bidirectional Bubble Sort, is an extension of the Bubble Sort algorithm. It sorts the array in both directions, making it more efficient in some cases. The algorithm performs multiple passes through the array, first moving the larger elements to the end and then moving the smaller elements to the beginning.

## Problem Definition
Given:
- An array `arr` of `n` elements.

Objectives:
- Sort the array in ascending order using the Cocktail Shaker Sort algorithm.

## Algorithm Overview
1. **Initialization**: Set two pointers, `start` and `end`, to indicate the current range of the unsorted elements.
2. **Forward Pass**: Compare each pair of adjacent elements from `start` to `end`, swapping them if they are out of order.
3. **Backward Pass**: Compare each pair of adjacent elements from `end` to `start`, swapping them if they are out of order.
4. Repeat the forward and backward passes until no swaps are needed, indicating the array is sorted.

## Time Complexity
Time complexity of Cocktail Shaker Sort is O(n^2):

- Best case: O(n)
- Average case: O(n^2)
- Worst case: O(n^2)

where:
- n is the number of elements in the input array.

## Space Complexity
The space complexity is O(1) since it only requires a constant amount of additional space for variables.

## Advantages
- Improved performance over Bubble Sort for certain data distributions.
- More efficient than simple sorting algorithms for medium-sized arrays.

## Disadvantages
- Still not suitable for large datasets.
- Performance is similar to other O(n^2) sorting algorithms.

