# Cocktail Shaker Sort

## What is Cocktail Shaker Sort?

Cocktail Shaker Sort, also known as bidirectional bubble sort, cocktail sort, shaker sort, ripple sort, shuffle sort, or shuttle sort, is a variation of bubble sort that is both a stable sorting algorithm and a comparison sort.

## How it works:

1. Traverse the list from left to right, comparing adjacent elements and swapping them if they are in the wrong order.
2. When the end of the list is reached, reverse direction and move from right to left, again swapping adjacent elements if needed.
3. Repeat this process, alternating directions each time, until no more swaps are needed.

## When to use:

- For small datasets
- When simplicity of implementation is more important than efficiency
- When the data is nearly sorted

## Pros and Cons:

Pros:
- Simple to understand and implement
- Slightly more efficient than bubble sort for some datasets
- Stable sort (maintains the relative order of equal elements)

Cons:
- Poor performance on large, unsorted datasets
- Not suitable for large-scale sorting tasks

## Time Complexity:
- Best case: O(n) when the array is already sorted
- Average case: O(n^2)
- Worst case: O(n^2)

## Space Complexity:
- O(1) as it's an in-place sorting algorithm