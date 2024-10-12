# Stooge Sort Algorithm

## Description

Stooge Sort is a recursive sorting algorithm that follows a divide-and-conquer strategy. It is primarily used for educational purposes due to its inefficiency. The algorithm recursively sorts sections of the array by repeatedly swapping elements based on their values and dividing the array into thirds.

### Problem Definition

Given:
- An array `arr` of `n` elements.

Objective:
- Sort the array in ascending order using the Stooge Sort algorithm.

### Algorithm Overview

1. **Base Case**: If the first index `l` is greater than or equal to the last index `h`, return (the array is already sorted).
2. **Swap Elements**: If the first element `arr[l]` is greater than the last element `arr[h]`, swap them.
3. **Check Size**: If there are more than two elements in the current section (i.e., `h - l + 1 > 2`), proceed with further sorting:
   - Calculate `t`, which is one-third of the current section size.
   - Recursively sort the first two-thirds of the array: `stooge_sort(arr, l, h - t)`.
   - Recursively sort the last two-thirds of the array: `stooge_sort(arr, l + t, h)`.
   - Recursively sort the first two-thirds again: `stooge_sort(arr, l, h - t)`.
4. **End Sorting**: The algorithm ends when the entire array is sorted through recursive calls.

### Time Complexity

Stooge Sort is highly inefficient, and its time complexity is as follows:

- **Best Case**: `O(n^(log 3 / log 1.5))`, which is approximately `O(n^2.7095)`.
- **Average Case**: `O(n^(log 3 / log 1.5))`.
- **Worst Case**: `O(n^(log 3 / log 1.5))`.

### Advantages

- Simple to understand and implement.
- Useful for educational purposes to illustrate recursive algorithms.

### Disadvantages

- Highly inefficient for large datasets, much slower than standard sorting algorithms like Quick Sort or Merge Sort.
- Not practical for real-world applications due to its poor performance.

### Conclusion

Stooge Sort is primarily a theoretical algorithm that serves to illustrate recursion and the concept of sorting. While it is not suitable for practical use, it offers insights into the challenges of sorting algorithms and the importance of efficiency in algorithm design.
