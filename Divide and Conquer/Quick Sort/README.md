# Quick Sort Algorithm

## Description

QuickSort is one of the best sorting algorithms that follows the divide-and-conquer approach like Merge Sort but unlike Merge Sort, this algorithm does in place sorting.

### Problem Definition
QuickSort is to select a pivot element from the array and partition the other elements into two sub-arrays according to whether they are less than or greater than the pivot. The sub-arrays are then sorted recursively. This process of partitioning and sorting continues until the entire array is sorted.

Given:
-Single Dimensional unsorted Array arr[] with predefined elements.

Objective:
-Efficiency: Quick Sort is known for its efficiency and is often faster in practice compared to other sorting algorithms such as Merge Sort or Heap Sort.
-Randomized Pivot Selection: To mitigate the worst-case time complexity of Quick Sort, it is common to use randomized pivot selection techniques that help avoid worst-case scenarios, ensuring a more balanced partitioning of the array. 

### Algorithm Overview

The quicksort() function first calls the partition() function. The partition() function rearranges the given subarray around the selected pivot such that all the elements less that pivot are placed left of it and all the elements greater that pivot are placed right of the pivot. Finally, it returns the index of the pivot to the quicksort.

Then quicksort() function divides the array into two subarrays based on this index and repeats the process for these two subarrays. This will go on till the given subarray cannot be further divided. At this point, the array is already sorted.

### Time Complexity

The time complexity of the Quick Sort is  O(n log(n) ) in all cases.
