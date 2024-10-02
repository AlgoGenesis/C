# Insertion Sort

# Description

Insertion sort algorithm builds sorted array one element at a time. It divides the array array into sorted and Unsorted part. Initially , the sorted part contains first element , and the insorted part contains rest of the elements. The algo proceeds by taking an element and inserting it into its correct position in the sorted part, and the sorted list grows from left to right.

# Problem Definition

Given:
-An array arr of n elements.

Objectives:
-Sort the array in ascending order using the insertion Sort algorithm.

# Algorithm Overview

1. Start with the second element (index 1) as the current element(key).
2. Compare the key with the elements in the sorted part (to its left).
3. Move elements in the sorted part that are greater than the key one position to the right.
4. Insert the key in its correct position in the sorted part.
5. Repeat the process for all the elements until the entire array is sorted.

# Time Complexity

The time complexity of the Insertion Sort algorithm is O(n^2) i the worst and average cases, as there are two nested loops: one that iterates through each element and another that compares and shifts the element in the sorted part. However , the best-case time complexity is O(n) in case of already sorted array. Suitable for small dataset.
