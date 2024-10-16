# Strand Sort Algorithm

## Description

Strand Sort is a sorting algorithm that builds a sorted array by repeatedly finding increasing subsequences in the input array. The algorithm extracts these subsequences, adds them to the sorted array, and removes them from the original array. This method is particularly effective for sorting data that is already partially sorted.

### Problem Definition

Given:
- An array `arr` of `n` elements.

Objective:
- Sort the array in ascending order using the Strand Sort algorithm.

### Algorithm Overview

1. **Find Increasing Subsequences**: Continuously find the longest increasing subsequence from the original array.
2. **Build Sorted Array**: Append the found subsequence to a sorted array and remove those elements from the original array.
3. **Repeat Until Sorted**: Repeat the process until no elements remain in the original array.
4. **End Sorting**: The algorithm completes when all elements have been processed and are in sorted order.

### Time Complexity

The time complexity of Strand Sort is generally as follows:

- **Best Case**: `O(n)` when the array is already sorted or nearly sorted.
- **Average Case**: `O(n^2)` under typical conditions, depending on the distribution of data.
- **Worst Case**: `O(n^2)` when the elements are in reverse order or highly mixed.

### Advantages

- Efficient for partially sorted data, leveraging existing order.
- Conceptually simple and easy to implement.

### Disadvantages

- Not suitable for large, completely unsorted datasets due to its quadratic time complexity.
- The algorithm's performance can degrade significantly based on input distribution.

### Conclusion

Strand Sort is a practical sorting algorithm that excels with partially sorted data. While it is not as efficient as more advanced sorting algorithms for large datasets, it provides a straightforward approach to sorting that is particularly effective in specific scenarios.
