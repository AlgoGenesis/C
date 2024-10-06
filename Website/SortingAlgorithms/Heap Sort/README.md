# Heap Sort

Heap Sort is a comparison-based sorting algorithm that uses a binary heap data structure. It sorts an array by first building heap from the array elements ans then repeatedly extracting the maximum element from the heap and reconstructing the heap until all elements are sorted.

# Problem Definition

Given:
-An array `arr` of `n` elements.

Objectives:
-Sort the array in ascending order using the insertion Sort algorithm.

# Algorithm Overview

1. Build a max-heap from input array. The array represent a binary tree where each parent node is greater then its child nodes.
2. Extract the maximum element and move it to the end of the array.
   Reduce the heap size by one and heapify thr eoot node to maintain max-heap property.
3. Repeat steps 2 and 3 until the heap size is reduced to 1.

# Time Complexity

The time complexity of the heap sort algorithm is O(n logn) for all cases (best, average, worst). This efficiency is due to the heapify operation, which has a logarithmic time complexity, and it is repeated n times during sorting process. Heapsot is suitable for large datasets.
