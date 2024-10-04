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

 Best case: O(n) , If the list is already sorted, where n is the number of           elements in the list.
 Average case: O(n 2 ) , If the list is randomly ordered.
 Worst case: O(n 2 ) , If the list is in reverse order .

# Space Complexity 

   Auxiliary Space: O(1), Insertion sort requires O(1) additional space, making it   a space-efficient sorting algorithm. 

# Advantages of Insertion Sort:

   1. Simple and easy to implement.
   2. Stable sorting algorithm.
   3. Efficient for small lists and nearly sorted lists.
   4. Space-efficient.
   5. Adoptive. the number of inversions is directly proportional to number of swaps. For example, no swapping happens for a sorted array and it takes O(n) time only.

 # Disadvantages of Insertion Sort:

   1. Inefficient for large lists.
   2. Not as efficient as other sorting algorithms (e.g., merge sort, quick sort) for most cases. 


