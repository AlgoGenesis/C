# Heap Sort

## What is Heap Sort?

Heap Sort is a comparison-based sorting algorithm that uses a binary heap data structure. It divides its input into a sorted and an unsorted region, and iteratively shrinks the unsorted region by extracting the largest element and moving it to the sorted region.

## How it works:

1. Build a max heap from the input data.
2. Swap the root (maximum element) with the last element of the heap.
3. Reduce the heap size by 1 and heapify the root.
4. Repeat steps 2-3 until the heap size is 1.

## When to use:

- When you need a consistent O(n log n) performance
- When memory usage is a concern

## Pros and Cons:

Pros:
- Efficient for large datasets
- In-place sorting algorithm
- Consistent performance (O(n log n) in all cases)

Cons:
- Not stable (may change the relative order of equal elements)
- Poor cache performance due to its non-localized memory access

## Time Complexity:
- Best case: O(n log n)
- Average case: O(n log n)
- Worst case: O(n log n)