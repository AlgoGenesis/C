# Selection Sort

# Description

Selection sort is a simple, comparison-based sorting algorithm that divides the input array into two parts: a sorted subarray and an unsorted subarray. It repeatedly selects the smallest (or largest, depending on sorting order) element from the unsorted subarray and swaps it with the first unsorted element, effectively growing the sorted subarray by one element in each iteration.

# Problem Definition

Given:
-An array `arr` of `n` elements.

Objectives:
-Sort the array in ascending order using the selection Sort algorithm.

# Algorithm Overview

1.  Start from the first element of the array.
2.  Find the smallest element in the unsorted subarray.
3.  Swap it with the element at the beginning of the unsorted subarray.
4.  Move the boundary between the sorted and unsorted subarrays one element to the right.
5.  Repeat steps 2–4 until all elements are sorted.


# Time complexity

The time complexity of selection sort is o(n^2) due to nested loops, where:

- The outer loop runs for n elements.
- The inner loop, which finds the minimum element, iterates through the remaining n-1 elements in each pass.


# Advantages

- Simple to implement
- Performs well on small datasets
- In-place Sorting

# Disadvantages

- Inefficient for large datasets
- Not stable
