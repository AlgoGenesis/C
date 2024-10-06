# Merge Sort Algorithm

## Description

Merge Sort is a comparison-based sorting algorithm that works by dividing the input array into two halves, then calling itself for these two halves, and finally it merges the two sorted halves. 

### Problem Definition
Merge Sort is based on the three principles: divide, conquer and combine which is better implemented using recursion using two functions:

mergeSort() – For Divide
merge() – For Conquer and Combine

Given:
-Single Dimensional Array arr[] with predefined elements.

Objective:
-To sort the array in minimum time complexity.

### Algorithm Overview

The Merge Sort algorithm follows these steps:
1. Divide: The array is divided into two halves recursively until each subarray contains only one element.
2. Conquer: Once the array is divided into single elements (each being trivially sorted), the merging phase begins. During the merging phase, adjacent subarrays are merged together in a sorted manner.
3. Combine: The merging process combines the sorted subarrays back together, ensuring that the merged array is sorted.

### Time Complexity

The time complexity of the Merge Sort is  O(n log(n) ) in all cases.
