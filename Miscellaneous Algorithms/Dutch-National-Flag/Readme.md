# Dutch National Flag Algorithm

## Overview

The Dutch National Flag algorithm is an efficient sorting algorithm that categorizes elements into three distinct groups. It was introduced by Edsger W. Dijkstra and is commonly used to solve problems where an array contains three distinct values.

This implementation sorts an array consisting of three different integers (0, 1, and 2), which can represent colors or categories.

## How It Works

The algorithm uses three pointers:

- `low`: Points to the position where the next 0 should go.
- `mid`: Points to the current element being examined.
- `high`: Points to the position where the next 2 should go.

### Steps:

1. Initialize `low` to 0, `mid` to 0, and `high` to the last index of the array.
2. Iterate through the array using the `mid` pointer:
   - If the current element is 0, swap it with the element at the `low` index and increment both `low` and `mid`.
   - If the current element is 1, just increment `mid`.
   - If the current element is 2, swap it with the element at the `high` index and decrement `high` (do not increment `mid` because the swapped element needs to be examined).
3. Repeat until `mid` exceeds `high`.

### Compilation

To compile the program, use the following command in your terminal:
gcc dutch_national_flag.c -o dutch_national_flag

## input:

int arr[] = {2, 0, 2, 1, 1, 0};

## output:

Original array:
2 0 2 1 1 0
Sorted array:
0 0 1 1 2 2

## Time Complexity

- **Best Case:** O(n)  
  In the best case scenario, the array is already sorted. The algorithm will still iterate through the entire array, resulting in linear time complexity.

- **Average Case:** O(n)  
  On average, the algorithm processes each element exactly once, leading to a linear time complexity.

- **Worst Case:** O(n)  
  In the worst-case scenario, the algorithm will examine each element of the array, making it O(n).

  ## Space Complexity

**Space Complexity:** O(1)  
 The algorithm sorts the array in place, requiring only a constant amount of additional space for the pointers.
