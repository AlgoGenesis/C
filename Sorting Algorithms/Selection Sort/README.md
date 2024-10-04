# Selection Sort

Selection Sort is a simple comparison-based sorting algorithm. It divides the input list into two parts:

1. A sorted portion at the left end
2. An unsorted portion at the right end

The algorithm repeatedly selects the smallest (or largest) element from the unsorted portion and moves it to the sorted portion.

## How it works

1. Find the minimum element in the unsorted array
2. Swap it with the first element of the unsorted part
3. Move the boundary of the unsorted array one element to the right
4. Repeat steps 1-3 until the entire array is sorted

## Time Complexity

- Worst-case time complexity: O(n^2)
- Average-case time complexity: O(n^2)
- Best-case time complexity: O(n^2)

Where n is the number of items in the array.

## Space Complexity

O(1) - Selection Sort is an in-place sorting algorithm, meaning it doesn't require any extra space proportional to the input size.

## Advantages

- Simple implementation
- Performs well on small lists
- In-place sorting (doesn't require additional memory)

## Disadvantages

- Inefficient for large lists
- Does not preserve the relative order of items with equal keys (not stable)

## Use Cases

Selection Sort is typically used for:

- Small arrays (usually less than 20 elements)
- When memory space is limited
- When the cost of swapping is not high

While Selection Sort is not the most efficient algorithm for larger datasets, its simplicity makes it a good choice for educational purposes and small-scale sorting tasks.