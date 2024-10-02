# Selection Sort Algorithm

## Description

Selection Sort is a simple comparison-based sorting algorithm. It divides the input list into two parts: a sorted portion at the left end and an unsorted portion at the right end. Initially, the sorted portion is empty and the unsorted portion is the entire list. The algorithm repeatedly selects the smallest (or largest, depending on the desired order) element from the unsorted portion and moves it to the end of the sorted portion.

### Problem Definition

Given:
- An array `arr` of `n` elements.

Objective:
- Sort the array in ascending order using the Selection Sort algorithm.

### Algorithm Overview

1. Iterate through the array from index 0 to n-1.
2. For each iteration i, find the minimum element in the subarray from index i to n-1.
3. Swap the minimum element with the element at index i.
4. Repeat steps 2-3 until the entire array is sorted.

### Time Complexity

- Worst-case time complexity: O(n^2)
- Average-case time complexity: O(n^2)
- Best-case time complexity: O(n^2)

Selection Sort always performs n(n-1)/2 comparisons, regardless of the input, making its time complexity O(n^2) for all cases.

### Space Complexity

The space complexity of Selection Sort is O(1) as it only requires a constant amount of additional memory space for the swap operation.

### Advantages and Disadvantages

Advantages:
- Simple and easy to understand
- Performs well on small lists
- In-place sorting algorithm (doesn't require much additional memory)

Disadvantages:
- Inefficient for large lists due to its quadratic time complexity
- Not stable (may change the relative order of equal elements)

## Implementation

The implementation of the Selection Sort algorithm can be found in the accompanying `Program.c` file.