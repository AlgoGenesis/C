# Binary Search Algorithm

## Description

Binary search is a fast search algorithm that finds the position of a target value within a sorted array. It works by repeatedly dividing the search interval in half. If the value of the search key is less than the item in the middle of the interval, the search continues in the lower half, or if greater, it continues in the upper half. This process is repeated until the value is found or the interval is empty.

### Problem Definition

Given:
- A sorted array `arr` of `n` elements.
- A target value `x` to search for.

Objective:
- Find the index of `x` in `arr`, or return `-1` if `x` is not present in the array.

### Algorithm Overview

1. Initialize two pointers, `left` and `right`, to the first and last index of the array, respectively.
2. While `left` is less than or equal to `right`:
   - Calculate the middle index `mid`.
   - If `arr[mid]` equals `x`, return `mid`.
   - If `arr[mid]` is less than `x`, move the `left` pointer to `mid + 1`.
   - If `arr[mid]` is greater than `x`, move the `right` pointer to `mid - 1`.
3. If the target value is not found, return `-1`.

### Recursive Binary Search

The recursive version of binary search follows the same logic but uses a recursive function to handle the subarray search instead of an iterative loop. 

1. The function accepts the array, the target `x`, and two boundary indices (`left` and `right`).
2. A base case is added to terminate the recursion when the `left` index exceeds `right`.
3. In each recursive step:
   - The middle index `mid` is calculated.
   - The function checks if `arr[mid]` matches the target `x`. If so, it returns `mid`.
   - If `x` is smaller, the function calls itself on the left subarray (`left` to `mid - 1`).
   - If `x` is larger, the function calls itself on the right subarray (`mid + 1` to `right`).

#### Time Complexity
- Like the iterative approach, the time complexity remains `O(log n)` because each step halves the search space.

#### Space Complexity
- **Recursive binary search** has a space complexity of **O(log n)** due to the additional memory consumed by recursive function calls (stack space).
- In contrast, the **iterative binary search** has a constant space complexity of **O(1)**.

### Time Complexity For Both Functions 

The time complexity of both recursive and iterative binary search algorithms is `O(log n)`, making them much more efficient than linear search for large datasets.
