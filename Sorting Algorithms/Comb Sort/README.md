# Comb Sort

Comb Sort is an improvement over Bubble Sort. It eliminates small values near the end of the list which slows down the sorting in Bubble Sort (known as the "turtle problem").

## How it works

1. Initialize the gap size as the length of the array
2. Reduce the gap by a shrink factor (usually 1.3)
3. Compare elements that are 'gap' distance apart and swap if in wrong order
4. Repeat steps 2-3 until the gap size becomes 1
5. When gap is 1, do a final pass of bubble sort

## Time Complexity

- Worst-case time complexity: O(n^2)
- Average-case time complexity: O(n^2 / 2^p), where p is the number of increments
- Best-case time complexity: O(n log n)

## Space Complexity

O(1) - Comb Sort is an in-place sorting algorithm.

## Advantages

- Simple implementation
- Performs better than Bubble Sort, especially for larger lists
- Can perform well on nearly sorted lists

## Disadvantages

- Not stable (doesn't preserve the relative order of equal elements)
- Performance can vary based on the shrink factor chosen

## Use Cases

- When a simple, in-place sorting algorithm is needed
- As an improvement over Bubble Sort in existing systems
- For educational purposes to demonstrate sorting concepts