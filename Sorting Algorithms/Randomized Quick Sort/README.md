# Randomized Quick Sort Algorithm

## Description

Randomized Quick Sort is an efficient sorting algorithm that uses the divide-and-conquer approach to sort an array. It works by selecting a random pivot element from the array, partitioning the other elements into two sub-arrays according to whether they are less than or greater than the pivot, and recursively sorting the sub-arrays. The randomization helps to avoid the worst-case time complexity that can occur with traditional Quick Sort.

### Problem Definition

Given:
- An array `arr` of `n` elements.

Objective:
- Sort the array in ascending order using the Randomized Quick Sort algorithm.

### Algorithm Overview

1. Select a random pivot element from the array.
2. Partition the array into two sub-arrays:
   - Elements less than the pivot.
   - Elements greater than the pivot.
3. Recursively apply the same logic to the left and right sub-arrays.
4. Continue until the base case is reached (when the sub-array has one or no elements).

### Time Complexity

The average time complexity of the Randomized Quick Sort algorithm is `O(n log(n))`, making it efficient for large datasets. However, its worst-case time complexity is `O(n^2)`, which can occur in cases of poorly balanced partitions. The randomization of pivot selection helps to mitigate this issue, leading to more balanced partitions on average.

### Space Complexity

The space complexity is `O(log(n))` due to the recursive calls on the call stack. In-place partitioning ensures that only a minimal amount of extra space is required.

### Example

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
int findFirstGreater(int *array, int start, int end, int pivot);
int findFirstSmaller(int *array, int start, int end, int pivot);
void swapElements(int *first, int *second);
void randomizedQuickSort(int *array, int left, int right);