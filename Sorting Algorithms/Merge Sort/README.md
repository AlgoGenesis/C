# Merge Sort

## What is Merge Sort?

Merge Sort is a divide-and-conquer algorithm that divides the input array into two halves, recursively sorts them, and then merges the two sorted halves.

## How it works:

1. Divide the unsorted array into n subarrays, each containing one element (a list of one element is considered sorted).
2. Repeatedly merge subarrays to produce new sorted subarrays until there is only one subarray remaining. This will be the sorted array.

## When to use:

- When you need a stable, efficient sorting algorithm
- When dealing with large datasets

## Pros and Cons:

Pros:
- Efficient for large datasets
- Stable sort (maintains the relative order of equal elements)
- Guaranteed O(n log n) time complexity in all cases

Cons:
- Requires additional memory space

## Time Complexity:
- Best case: O(n log n)
- Average case: O(n log n)
- Worst case: O(n log n)