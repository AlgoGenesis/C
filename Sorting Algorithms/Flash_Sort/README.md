# Flash Sort Algorithm

- Flash Sort is a fast, non-comparison-based sorting algorithm that works particularly well with uniformly distributed data. 
- It combines elements of classification sorting and insertion sort, making it a hybrid approach that achieves O(n) performance in the best case. 

- This algorithm is ideal when you need a quick sorting solution for a dataset that fits its characteristics, such as data that is mostly uniformly distributed.

## Table of Contents

- [Flash Sort Algorithm](#flash-sort-algorithm)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Algorithm](#algorithm)
  - [Code Explanation](#code-explanation)
  - [Example:](#example)
  - [Complexity](#complexity)

## Introduction

- Flash Sort divides the input array into buckets (or classes) based on the data range. 
- It then permutes the elements into their correct classes, followed by insertion sort for the final sorted result.
- This method is highly efficient for large datasets with certain characteristics.

## Algorithm

1. **Identify Min and Max Values**: The algorithm begins by identifying the minimum and maximum values in the array.
   
2. **Create Buckets**: The array is divided into several buckets based on the values' range.

3. **Classify Elements**: Each element is placed into its corresponding bucket.

4. **Permutation**: The elements are permuted into their approximate correct positions based on the bucket they fall into.

5. **Final Insertion Sort**: A final insertion sort is applied to sort the elements within each bucket.

## Code Explanation

- Swap Function: A helper function to swap two elements in the array.

- flashSort Function: The main Flash Sort implementation.

- Finding Min and Max: We first find the minimum and maximum elements to understand the range.
Buckets (Classes): The array is divided into buckets, where each bucket represents a range of values.

- Permutation: The elements are permuted into their appropriate positions.
Insertion Sort: A final pass of insertion sort is used to sort elements within each bucket.
- printArray Function: A utility function to print the array contents.

- Main Function: This function demonstrates how to use the Flash Sort algorithm to sort an array of integers.


## Example: 

Input 
```cpp
Original array: 38 27 43 3 9 82 10
```

Output
```cpp
Sorted array: 3 9 10 27 38 43 82
```

## Complexity

- Time Complexity:
    - Best case: O(n) when elements are uniformly distributed.
    - Worst case: O(n^2) if elements are highly non-uniformly distributed.
- Space Complexity: O(n) due to the bucket array.