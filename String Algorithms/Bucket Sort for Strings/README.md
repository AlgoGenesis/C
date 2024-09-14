# Bucket Sort for Strings

## Description

Bucket Sort is a distribution sorting algorithm that divides the input into several "buckets." Each bucket is then sorted individually, either using a different sorting algorithm or recursively applying the bucket sort. This algorithm is particularly effective when the input is uniformly distributed.

### Problem Definition

Given:
- An array of strings.

Objective:
- Sort the array of strings in lexicographical (dictionary) order using the Bucket Sort algorithm.

### Algorithm Overview

1. **Initialization**: Create a number of empty buckets (arrays) to hold the strings based on their first character or a specific criterion.
2. **Distribution**: Loop through the array of strings and place each string into the appropriate bucket based on the sorting criterion (e.g., the first character).
3. **Sorting**: Sort each non-empty bucket individually using a stable sorting algorithm (e.g., Insertion Sort or another instance of Bucket Sort).
4. **Concatenation**: Merge all the sorted buckets back into a single array.

### Time Complexity

The average time complexity of Bucket Sort is `O(n + k)`, where `n` is the number of strings and `k` is the number of buckets. The worst-case time complexity can be `O(n^2)` if all strings end up in a single bucket.
