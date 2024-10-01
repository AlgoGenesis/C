# Selection Sort

## Description

### Problem Definition

Given:
- An array of integers.

Objective:
- Sort the array using the Selection Sort algorithm.

### Algorithm Overview

1. **Select Minimum**: Start from the first element and assume it is the minimum.
2. **Find Minimum**: Compare this minimum with the other elements in the array to find the actual minimum.
3. **Swap**: Swap the found minimum element with the first element of the unsorted part of the array.
4. **Repeat**: Move the boundary of the sorted and unsorted parts of the array one element to the right and repeat the process until the entire array is sorted.

### Time Complexity

The time complexity of Selection Sort is \( O(n^2) \), where \( n \) is the number of elements in the array. This is due to the two nested loops: one for iterating through the array and another for finding the minimum element.
