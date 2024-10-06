# Merge Sort

# Description

Merge Sort is a divide and conquer sorting algorithm that divides the input array into two hallves , sort each half, and then merges the two sorted halves back together. It is efficient for large dataset and is stable,means it maintains the relative order of equal elements.

# Proobblem Definition

Given:
-An array `arr` of `n` elements.

Objectives:
-Sort an array in ascending order using merge sort.

# Algorithm Overview

1. Divide:Split the array into two halves until each subarray contains a single element (the base case).
2. Conquer: Recursively sort each half.
3. Merge: Combine the two halves into sorted array:

- Create temporary array to contain the values of two halves.
- Compare the elements of the two arrays and insert the smaller element back into original array.
- If there are remaining elements in either temporary array, copy them back into original array.

# Time Complexity

The time complexity of the Merge sort algorithm is O(n*logn) in all cases(best, average and worst) due to consistent division of an array and merging. This algorithm is suitable for large data sets due to efficiency and is often used in applications, such as external sorting of large files.
