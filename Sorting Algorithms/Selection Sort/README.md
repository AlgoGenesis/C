# Selection Sort Algorithm

## Description

Selection Sort is a comparison-based sorting algorithm. The idea is to repeatedly select the smallest element from the unsorted portion of the array and move it to the beginning, progressively growing the sorted portion of the array. It is an **in-place algorithm**, meaning it requires only a constant amount of additional memory space and rearranges elements directly within the array.

The process of sorting begins at the first position in the array and proceeds by identifying the smallest element from the unsorted part of the array. This element is swapped with the element at the current index of the sorted portion. After this swap, the sorted portion increases in size by one, and the unsorted portion shrinks accordingly. The algorithm continues until all elements are sorted.

### Key Concept:
- **Selection Sort** repeatedly identifies the smallest element from the unsorted section of the array and swaps it with the first element of the unsorted section.

## Problem Definition

Given an array of integers, the task is to sort the array in ascending order using the **Selection Sort** algorithm.

### Example:
- **Input**: `[64, 25, 12, 22, 11]`  
  **Output**: `[11, 12, 22, 25, 64]`
  
- **Input**: `[29, 10, 14, 37, 13]`  
  **Output**: `[10, 13, 14, 29, 37]`

### Detailed Steps:

1. **Start from the first element**:  
   Begin with the first element of the array and assume it is the minimum element.
   
2. **Find the minimum element in the unsorted portion**:  
   Compare the current minimum with the remaining elements in the unsorted portion to find the actual minimum element.
   
3. **Swap the minimum element**:  
   Swap the smallest found element with the current element (starting element of the unsorted portion).
   
4. **Repeat**:  
   Repeat steps 1 to 3 for the remaining unsorted part of the array until the entire array is sorted.

## Algorithm Analysis

- **Time Complexity**:  
  Selection Sort has a time complexity of **O(n^2)**, where **n** is the number of elements in the array. This is because for each element in the array, we search the entire unsorted portion to find the minimum element, resulting in nested loops.
  
- **Space Complexity**:  
  The space complexity is **O(1)** because the algorithm operates in place and requires only a constant amount of extra memory.

- **Best Case**: **O(n^2)** (even if the array is already sorted, the algorithm still compares all elements).
  
- **Worst Case**: **O(n^2)** (for a completely unsorted array).

- **Stability**:  
  Selection Sort is **not a stable sort**, meaning that the relative order of equal elements may not be preserved.

## Practical Use

Although Selection Sort is simple and easy to implement, it is generally inefficient for large datasets due to its **O(n^2)** time complexity. It is, however, useful in situations where memory is limited, and the number of elements to be sorted is relatively small. It’s also a good algorithm to understand as a building block for more advanced sorting techniques.
