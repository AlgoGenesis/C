# Gnome Sort 

## Description

Gnome sort is a simple, comparison-based sorting algorithm similar to insertion sort. It works by iteratively comparing adjacent elements and swapping them if they are in the wrong order, similar to how a gnome would rearrange flower pots by stepping backward and forward. It is easy to implement but not very efficient for large datasets.

## Problem Definition

Given:
- An array `arr` of `n` elements.

Objectives:
- Sort the array in ascending order using the Gnome Sort algorithm.

## Algorithm Overview

1. **Iterate through the array**: Start at the beginning of the array.
2. **Compare and Swap**: Compare the current element with the previous element. If they are out of order, swap them and step back; otherwise, move forward.
3. **Step backward if necessary**: If a swap occurs, move back one position to ensure the previous elements are still in order.
4. **Complete when end is reached**: Repeat this process until the last element is reached and no swaps are necessary.

## Time Complexity

The time complexity of gnome sort is O(n^2), where:
- **n** is the number of elements in the array.

### Case-wise complexities:
- **Best case**: O(n) (when the array is already sorted)
- **Average case**: O(n^2)
- **Worst case**: O(n^2)

## Space Complexity

The space complexity is O(1) as gnome sort operates in-place and does not require any additional memory.

## Advantages

- Simple to implement.
- Can be useful for small datasets.
- Works well for nearly sorted arrays.

## Disadvantages

- Inefficient for large datasets.
- Slower than more advanced algorithms like quicksort or mergesort.

## Code Implementation

You can find the C implementation of Gnome Sort in the `program.c` file.
