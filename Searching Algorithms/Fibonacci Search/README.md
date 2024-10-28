# Fibonacci Search Algorithm

## Description

Fibonacci Search is an efficient search algorithm that uses Fibonacci numbers to divide the array into sections. It is similar to binary search but uses Fibonacci numbers to calculate the mid-point, making it useful for searching sorted arrays.

### Problem Definition

Given:
- A sorted array `arr[]` of `n` elements.
- A target value `x`.

Objective:
- Search for the target value `x` in the array using Fibonacci Search and return its index if found, or -1 if not found.

### Algorithm Overview

1. Generate Fibonacci numbers until the largest Fibonacci number is greater than or equal to the length of the array.
2. Use the Fibonacci numbers to divide the array and narrow down the search range.
3. Compare the target value with the elements at the calculated indices.
4. Continue until the element is found or the range is exhausted.

### Time Complexity

The time complexity of Fibonacci Search is `O(log n)`, making it efficient for large datasets.