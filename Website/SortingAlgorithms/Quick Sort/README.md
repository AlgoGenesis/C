# Quick Sort

# Description

Quick sort is highly efficient sorting algorithm and is based on divide-and-conquer
stategy. It works by choosing "pivot" element from array and partitioning the other elements into to subarrays accordingily . The subarrays are then sorted recursively.The process is repeated until the array is sorted.

# Problem Definition

Given:
-An array `arr` of `n` elements.

Objectives:
-Sort an array in ascending order using quick sort.

# Algorithm Overview

1. Select a pivot element from an array.
2. Partition the array into two subarrays:
   *Elements greater than pivot
   *Elements less or equal to the pivot.
3. Recursively apply above stepsto subarrays.
4. Combine the sorted subarrays to produce the sorted array.

# Steps:

1. Chose rightmost element as the pivot.
2. Initialize two pointers: one at the start(low) and one at the end(high).
3. Rearrange the elements in such a way that all elements less than the pivot are on the left, and all elements greater than the pivot are on the right.
4. Recursively apply the same logic to the lest and rigth subarrays until they are fully sorted.
5. Combine the results.

# Time Complexity

- Best case: O(n logn)
- Average Case: O(n logn)
- Worst case: O(n^2)
