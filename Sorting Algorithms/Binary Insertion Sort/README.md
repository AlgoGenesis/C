# Binary Insertion Sort

## Description

The Binary Insertion Sort is an optimization of the traditional insertion sort algorithm. It uses binary search to efficiently find the correct position for each element in a sorted subarray. This reduces the number of comparisons needed compared to a linear search. The program takes an unsorted array as input from the user, sorts it using binary insertion sort, and displays the sorted array.

### Problem Definition

Given:
- An unsorted array of integers.

Objective:
- Sort the array in ascending order using the Binary Insertion Sort algorithm, which uses binary search to find the correct insertion point for each element.

### Algorithm Overview

1. **Initialization:**
   - The user provides the size of the array and the elements to be sorted.

2. **Binary Search:**
   - For each element in the array, the algorithm uses binary search to find the appropriate position where the element should be inserted in the sorted portion of the array.

3. **Shifting Elements:**
   - Once the position is determined, all elements greater than the current element are shifted to the right to make space for the element to be inserted.

4. **Sorting Process:**
   - The array is sorted as each element is placed in its correct position, ensuring that the elements before the current element are always sorted.

### Example Output

```c
Enter the size of the array:
5
Enter the elements of the array:
12 4 7 9 3

Original array: 12 4 7 9 3 
Sorted array: 3 4 7 9 12
```

### Time Complexity

- **Binary Search:** Each binary search operation takes `O(log n)` time to find the correct position for an element.
- **Shifting Elements:** In the worst case, all elements may need to be shifted, which takes `O(n)` time.
- Therefore, the overall time complexity is `O(n^2)` due to the insertion step for each element.

### Space Complexity

- The space complexity is `O(1)` since the sorting is done in place using a fixed-size array.

### Usage

1. **Input:**
   - The user is prompted to enter the size of the array and the array elements.
   
2. **Output:**
   - The program displays the original unsorted array, then the array after sorting using Binary Insertion Sort.