# Cycle Sort

Cycle Sort is an in-place, unstable sorting algorithm that is theoretically optimal in terms of the total number of writes to the original array. It's particularly useful when write operations are costly.

## How it works

1. Start from the first element as the current element
2. Find the correct position for the current element in the sorted array
3. If the element is already in the correct position, move to the next element
4. If not, swap it with the element in its correct position
5. Repeat steps 2-4 until the element returns to its original position, completing a cycle
6. Move to the next element and repeat the process until all elements are sorted

## Time Complexity

- Worst-case time complexity: O(n^2)
- Average-case time complexity: O(n^2)
- Best-case time complexity: O(n^2)

## Space Complexity

O(1) - Cycle Sort is an in-place sorting algorithm.

## Advantages

- Minimizes the number of memory writes
- Optimal in terms of total number of writes to the original array
- In-place sorting algorithm (doesn't require additional memory)

## Disadvantages

- Not stable (doesn't preserve the relative order of equal elements)
- Inefficient for large datasets due to its quadratic time complexity
- Complex implementation compared to other simple sorting algorithms

## Use Cases

- When write operations to memory are significantly more expensive than read operations
- In scenarios where minimizing writes is more important than minimizing time complexity
- For educational purposes to demonstrate the concept of cycle detection in arrays