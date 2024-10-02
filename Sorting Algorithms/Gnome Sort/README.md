# Gnome Sort

## What is Gnome Sort?

Gnome Sort, also called Stupid Sort, is a sorting algorithm originally proposed by Dr. Hamid Sarbazi-Azad in 2000. It is a simple sorting algorithm that is similar to Insertion Sort, but moves elements to their proper position by a series of swaps, similar to Bubble Sort.

## How it works:

1. Start with an index of 1.
2. If the current element is larger than or equal to the previous element, move to the next element.
3. If the current element is smaller than the previous element, swap them and move back one position.
4. If at the start of the array, move to the next element.
5. Repeat until the end of the array is reached.

## When to use:

- For very small datasets
- When simplicity of implementation is more important than efficiency
- For educational purposes

## Pros and Cons:

Pros:
- Simple to implement
- Performs well for nearly sorted lists

Cons:
- Not efficient for large datasets
- Generally performs worse than Insertion Sort

## Time Complexity:
- Best case: O(n) when the array is already sorted
- Average case: O(n^2)
- Worst case: O(n^2)

## Space Complexity:
- O(1) as it's an in-place sorting algorithm