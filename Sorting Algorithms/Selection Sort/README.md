# Selection Sort Algorithm

## Description

Selection Sort is a simple and intuitive sorting algorithm that repeatedly selects the minimum (or maximum) element from the unsorted portion of the array and moves it to the beginning (or end). It is an in-place comparison-based sorting algorithm.

### Problem Definition

Given:
- An array `arr[]` of `n` elements.

Objective:
- Sort the array in ascending order using the Selection Sort algorithm.

### Algorithm Overview

1. Start with the first element of the array as the current minimum.
2. Iterate through the unsorted portion of the array to find the minimum element.
3. Swap the found minimum element with the first unsorted element.
4. Move the boundary between sorted and unsorted portions of the array to the right.
5. Repeat steps 1-4 until the entire array is sorted.

### Time Complexity

The time complexity of Selection Sort is \(O(n^2)\), where \(n\) is the number of elements in the array. The space complexity is \(O(1)\), as it sorts the array in place.