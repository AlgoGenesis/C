# Merge Sort

# Description

Merge Sort is a divide and conquer sorting algorithm that divides the input array into two halves , sort each half, and then merges the two sorted halves back together. It is efficient for large dataset and is stable,means it maintains the relative order of equal elements.

# Problem Definition

Given:
-An array `arr` of `n` elements.

Objectives:
-Sort an array in ascending order using merge sort.

# Algorithm Overview

1. Divide:Split the array into two halves until each sub array contains a single element (the base case).
2. Conquer: Recursively sort each half.
3. Merge: Combine the two halves into sorted array:

- Create temporary array to contain the values of two halves.
- Compare the elements of the two arrays and insert the smaller element back into original array.
- If there are remaining elements in either temporary array, copy them back into original array.

# Time Complexity
    Best Case: O(n log n), When the array is already sorted or nearly sorted.
    Average Case: O(n log n), When the array is randomly ordered.
    Worst Case: O(n log n), When the array is sorted in reverse order. 
    
# Auxiliary Space
   O(n), Additional space is required for the temporary array used during merging. 

# Advantages of Merge Sort

    Stability 
    Guaranteed worst-case performance:
    Simple to implement
    Naturally Parallel

# Disadvantages of Merge Sort:

    Space complexity: requires additional memory to store
    Slower than QuickSort in general.
