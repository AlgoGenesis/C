# Gnome Sort

Gnome Sort, also called Stupid Sort, is a sorting algorithm originally proposed by Dr. Hamid Sarbazi-Azad in 2000. It's a simple sorting algorithm that works similar to Insertion Sort but moves elements to their proper position by a series of swaps.

## How it works

1. Start with an index pointing to the first element
2. If the current element is larger or equal to the previous one, move to the next element
3. If the current element is smaller than the previous one, swap them and move back one position
4. If at the start of the array, move to the next element
5. Repeat until the end of the array is reached

## Time Complexity

- Worst-case time complexity: O(n^2)
- Average-case time complexity: O(n^2)
- Best-case time complexity: O(n) (when the list is already sorted)

## Space Complexity

O(1) - Gnome Sort is an in-place sorting algorithm.

## Advantages

- Simple implementation
- Works well for small datasets
- Performs well on nearly sorted lists

## Disadvantages

- Inefficient for large, unsorted datasets
- Performs many swaps which can be costly in some scenarios

## Use Cases

- For educational purposes to demonstrate sorting concepts
- In scenarios where simplicity of implementation is more important than efficiency
- For small datasets or nearly sorted lists