# Cycle Sort

## Description

Cycle Sort is an in-place, non-comparison-based sorting algorithm that is based on the idea of placing each element in its correct position by cycling through a series of positions in the array. This algorithm is particularly efficient when the number of writes (or swaps) is important, as it minimizes the number of swaps required to sort the array.

### Problem Definition

Given:
- An array of integers.

Objective:
- Sort the array using the Cycle Sort algorithm.

### Algorithm Overview

1. **Cycle through the array**: Starting from the first element, move each element to its correct position based on how many elements are smaller than it in the array.
2. **Find the correct position**: For each element, count the number of elements smaller than it and determine the correct position in the sorted array.
3. **Swap elements**: If the element is not already in its correct position, swap it with the element at its correct position.
4. **Repeat**: Continue this process for each element, ensuring that all elements are placed in their correct positions.

### Time Complexity

- **Time Complexity**: The time complexity of Cycle Sort is \( O(n^2) \) in the worst case, where \( n \) is the number of elements in the array. This is because for each element, the algorithm needs to traverse the array to count smaller elements.
- **Space Complexity**: The space complexity is \( O(1) \), as Cycle Sort is an in-place sorting algorithm and requires only a constant amount of extra space.

### Key Features of Cycle Sort

- Efficient with Writes: Cycle Sort minimizes the number of writes to the array, making it particularly useful in scenarios where minimizing write operations is critical, such as in flash memory.
- In-Place Sorting: The algorithm performs sorting in-place, so it doesn't require extra space beyond the given array.
- Not a Comparison Sort: Unlike comparison-based algorithms like quicksort or mergesort, Cycle Sort sorts elements based on their position relative to others, making it an efficient option in certain cases.
