# Bucket Sort

## Description

Bucket Sort is a comparison-based sorting algorithm that distributes the elements of an array into a number of "buckets." Each bucket is then sorted individually, either using a different sorting algorithm or recursively applying the bucket sort. The final output is obtained by concatenating all sorted buckets. Bucket Sort is particularly useful for sorting uniformly distributed data.

### Problem Definition

Given:
- An array of floating-point numbers in the range \([0, 1)\).

Objective:
- Sort the array using the Bucket Sort algorithm.

### Algorithm Overview

1. **Create Buckets**: Initialize an array of empty buckets. The number of buckets can be decided based on the size of the input array.
2. **Distribute Elements**: For each element in the input array, determine the appropriate bucket by multiplying the element by the number of buckets. Place the element in the corresponding bucket.
3. **Sort Buckets**: Sort each non-empty bucket using an efficient sorting algorithm (e.g., insertion sort, quicksort).
4. **Concatenate Buckets**: Combine the sorted elements from each bucket to obtain the final sorted array.

### Time Complexity

The average time complexity of Bucket Sort is \( O(n + k) \), where \( n \) is the number of elements and \( k \) is the number of buckets. The worst-case time complexity is \( O(n^2) \) when all elements fall into the same bucket and the bucket sort algorithm used for sorting those elements has a worst-case time complexity of \( O(n^2) \).

