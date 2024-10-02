# Insertion Sort

## What is Insertion Sort?

Insertion Sort is a simple sorting algorithm that works similar to how you might sort playing cards in your hand. It builds the final sorted array one item at a time.

## How it works:

1. Start with the second element (consider the first element as already sorted).
2. Compare the second element with the first and swap if necessary.
3. Move to the next element and insert it into its correct position among the previously sorted elements.
4. Repeat step 3 until the entire array is sorted.

## When to use:

- For small datasets
- When the array is nearly sorted

## Pros and Cons:

Pros:
- Simple to understand and implement
- Efficient for small datasets
- Works well with nearly sorted data

Cons:
- Slow for large datasets

## Time Complexity:
- Best case: O(n) when the array is already sorted
- Average case: O(n^2)
- Worst case: O(n^2) when the array is reverse sorted