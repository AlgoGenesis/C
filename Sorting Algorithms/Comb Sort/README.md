# Comb Sort

## What is Comb Sort?

Comb Sort is an improvement over Bubble Sort. The basic idea is to eliminate turtles, or small values near the end of the list, since in a bubble sort these slow the sorting down tremendously. Comb Sort improves on Bubble Sort by using gap of size more than 1.

## How it works:

1. Initialize gap size as array length.
2. Divide gap by a shrink factor (usually 1.3) in every iteration.
3. Compare elements with the given gap and swap if they are in the wrong order.
4. Repeat steps 2-3 until the gap becomes 1.
5. When gap is 1, do a final bubble sort.

## When to use:

- When you need a simple improvement over Bubble Sort
- For educational purposes to understand sorting algorithm improvements

## Pros and Cons:

Pros:
- Better than Bubble Sort, especially for larger lists
- Simple to implement

Cons:
- Not stable (may change the relative order of equal elements)
- Not as efficient as more advanced algorithms like Quick Sort or Merge Sort

## Time Complexity:
- Best case: O(n log n)
- Average case: O(n^2 / 2^p), where p is the number of increments
- Worst case: O(n^2)

## Space Complexity:
- O(1) as it's an in-place sorting algorithm