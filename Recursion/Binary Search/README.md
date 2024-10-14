# Binary Search (Recursive)

## Description

Binary Search is an efficient algorithm for finding an item from a sorted list of items. It works by repeatedly dividing the search interval in half, which reduces the time complexity compared to linear search. The key requirement for binary search is that the array must be sorted beforehand.

### Problem Definition

Given:

- A sorted array of integers.
- An integer value to search for in the array.

Objective:

- Find the index of the target value in the array using recursive binary search.

### Algorithm Overview

1. **Base Case**: If the left index exceeds the right index, the target value is not present in the array; return -1.
2. **Calculate Midpoint**: Find the middle index of the current search interval:
   \[
   \text{mid} = \text{left} + \frac{\text{right} - \text{left}}{2}
   \]
3. **Compare and Recur**:
   - If the target value equals the middle element, return the middle index.
   - If the target value is less than the middle element, recursively search the left half of the array.
   - If the target value is greater than the middle element, recursively search the right half of the array.

### Time Complexity

The time complexity of binary search is \( O(\log n) \), where \( n \) is the number of elements in the array. This is because the search space is halved with each recursive call.
c
