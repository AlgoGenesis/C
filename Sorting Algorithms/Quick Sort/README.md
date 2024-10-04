# Quick Sort

# Description

Quick sort is highly efficient sorting algorithm and is based on divide-and-conquer
strategy. It works by choosing "pivot" element from array and partitioning the other elements into to sub arrays accordingly . The sub arrays are then sorted recursively.The process is repeated until the array is sorted.

# Problem Definition

Given:
-An array `arr` of `n` elements.

Objectives:
-Sort an array in ascending order using quick sort.

# Algorithm Overview

1. Select a pivot element from an array.
2. Partition the array into two sub arrays:
   *Elements greater than pivot
   *Elements less or equal to the pivot.
3. Recursively apply above stepsto sub arrays.
4. Combine the sorted sub arrays to produce the sorted array.

# Steps:

1. Chose rightmost element as the pivot.
2. Initialize two pointers: one at the start(low) and one at the end(high).
3. Rearrange the elements in such a way that all elements less than the pivot are on the left, and all elements greater than the pivot are on the right.
4. Recursively apply the same logic to the lest and right sub arrays until they are fully sorted.
5. Combine the results.

# Time Complexity

- Best case: O(n log n)
- Average Case: O(n log n)
- Worst case: O(n^2)

# Auxiliary Space

   O(n), due to recursive call stack

#  Advantages of Quick Sort

   1. It is a divide-and-conquer algorithm that makes it easier to solve problems.
   2. It is efficient on large data sets.
   3. It has a low overhead, as it only requires a small amount of memory to function.
   4. It is Cache Friendly as we work on the same array to sort and do not copy data to any auxiliary       array.
   5. Fastest general purpose algorithm for large data when stability is not required.
   6. It is tail recursive and hence all the tail call optimization can be done.

#  Disadvantages of Quick Sort

   1. It has a worst-case time complexity of O(n2), which occurs when the pivot is chosen poorly.
   2. It is not a good choice for small data sets. 
   3. It is not a stable sort.
