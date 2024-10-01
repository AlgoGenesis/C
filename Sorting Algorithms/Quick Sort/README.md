# Quick Sort

## Description

### Problem Definition

Given:
- An array of integers.

Objective:
- Sort the array using the Quick Sort algorithm.

### Algorithm Overview

1. **Choose a Pivot**: Select an element from the array as the pivot (commonly the last element).
2. **Partition**: Rearrange the array so that elements less than the pivot are on its left, and elements greater than the pivot are on its right.
3. **Recursively Sort**: Recursively apply the above steps to the sub-arrays on the left and right of the pivot.

### Time Complexity

The average time complexity of Quick Sort is \( O(n \log n) \), where \( n \) is the number of elements in the array. The worst-case time complexity is \( O(n^2) \), which occurs when the smallest or largest element is always chosen as the pivot.