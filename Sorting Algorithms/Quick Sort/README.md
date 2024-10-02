# Quick Sort

## What is Quick Sort?

Quick Sort is a highly efficient, comparison-based sorting algorithm that uses a divide-and-conquer strategy. It works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot.

## How it works:

1. Choose a pivot element from the array (usually the last element or a random one).
2. Partition the array:
   - Move all elements smaller than the pivot to the left side of the array.
   - Move all elements larger than the pivot to the right side.
   - The pivot is now in its final sorted position.
3. Recursively apply steps 1-2 to the sub-array of elements with smaller values and the sub-array of elements with larger values.

## When to use:

- When you need an efficient, in-place sorting algorithm for large datasets
- When average-case performance is more important than worst-case performance

## Pros and Cons:

Pros:
- Very efficient on average (O(n log n))
- In-place sorting (requires little additional memory)
- Cache-friendly (good locality of reference)

Cons:
- Unstable sort (may change the relative order of equal elements)
- Worst-case time complexity of O(n^2) (though rare in practice)
- Performance depends on the choice of pivot

## Time Complexity:
- Best case: O(n log n)
- Average case: O(n log n)
- Worst case: O(n^2) (rare, occurs when the pivot is always the smallest or largest element)

## Space Complexity:
- O(log n) average case for the recursive call stack
- O(n) worst case for the recursive call stack (unlikely with good pivot selection)