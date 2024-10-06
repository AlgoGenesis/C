# Bubble Sort Algorithm

## Description

Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted. The algorithm gets its name from the way larger elements "bubble" to the top of the list.

### Problem Definition

Given:
- An array `arr` of `n` elements.

Objective:
- Sort the array in ascending order using the Bubble Sort algorithm.

### Algorithm Overview

1. Loop through the entire array.
2. For each element, compare it with the next element.
3. If the current element is greater than the next element, swap them.
4. Repeat the process for each element until no swaps are needed, indicating that the array is sorted.

### Time Complexity

The time complexity of the Bubble Sort algorithm is `O(n^2)`, making it inefficient on large datasets compared to more advanced sorting algorithms like Quick Sort and Merge Sort. However, it is simple to implement and can be useful for small datasets or educational purposes.
