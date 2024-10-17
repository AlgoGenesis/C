# Tag Sort Algorithm

## Description

Tag Sort is a comparison-based sorting algorithm that organizes elements based on their indices rather than their actual values. This technique allows it to maintain the original order of elements while sorting. 

### Problem Definition

Given:
- An array `arr` of `n` elements.

Objective:
- Sort the array in ascending order using the Tag Sort algorithm.

### Algorithm Overview

1. Initialization: Create a tag[] array to hold indices of the original array.
2. Tag Sorting: Use a nested loop to compare elements of the original array via the tag[] indices.
Swap the indices in the tag[] array based on the comparisons.
3. Output: Access and print the elements of the original array using the sorted indices from the tag[].

### Time Complexity

The time complexity of Tree Sort is generally as follows:

- **Best Case**: `O(n^2)` 
- **Average Case**: `O(n^2)` 
- **Worst Case**: `O(n^2)` 

### Advantages

- Stable Sorting Algorithm: Maintains the relative order of equal elements.
- Preserves Original Array: The original array remains unchanged.
- Works with Indirect Data: Useful for sorting without directly modifying the data.
- Simple to Implement: Easy to understand and code.
- Suitable for Multi-Dimensional Data: Can handle complex data structures without altering them.

### Disadvantages

- Inefficient Time Complexity:`O(n^2)' in best, worst, and average cases.
- Extra Space Requirement: Requires an additional array, leading to O(n) space complexity.
- Not Adaptive: Performance doesn't improve for already sorted or partially sorted arrays.

### Conclusion

Tag Sort is a simple and stable sorting algorithm that preserves the original array and works well for sorting indirect or multi-dimensional data. However, its 
 `O(n^2)' time complexity, extra space requirement, and lack of adaptability make it inefficient for large datasets or practical applications.