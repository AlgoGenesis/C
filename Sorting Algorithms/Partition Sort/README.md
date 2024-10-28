# Partition Sort Algorithm

This document provides an overview of the Partition Sort algorithm, an implementation that uses the Hoare Partition scheme. This is a variant of the QuickSort algorithm that partitions the array around a pivot and recursively sorts the partitions.

## Code Description

The algorithm uses the following functions:

- `swap(int *a, int *b)`: Swaps two elements in an array.
- `partition(int arr[], int low, int high)`: Partitions the array based on the Hoare Partition scheme. It selects the first element as a pivot, then rearranges elements such that all elements smaller than the pivot are on the left, and all elements greater are on the right.
- `partitionSort(int arr[], int low, int high)`: Recursively sorts the array by partitioning it until each element is individually sorted.
- `printArray(int arr[], int n)`: Prints the contents of an array.

## Example Usage

The following example demonstrates the use of the algorithm with an array of random integers:

```c
#include <stdio.h>
#include <stdlib.h>

// Function implementations ...

int main()
{
    int arr[20];
    int range = 100;
    for (int i = 0; i < 20; i++)
    {
        arr[i] = rand() % range + 1;
    }
    
    printf("Unsorted Array: \n");
    printArray(arr, 20);

    partitionSort(arr, 0, 19);

    printf("Sorted Array: \n");
    printArray(arr, 20);

    return 0;
}
```

## Steps in the Algorithm

1. **Generate Random Array**: Create an array of random integers.
2. **Partitioning**: Select a pivot element and partition the array, moving elements less than the pivot to the left and greater ones to the right.
3. **Recursive Sort**: Recursively apply the `partitionSort` function to each partitioned segment until the entire array is sorted.
4. **Print the Sorted Array**: Use `printArray` to output the sorted array.

## Time Complexity

- **Best Case**: \(O(n \log n)\) - When the pivot divides the array into two equal halves.
- **Average Case**: \(O(n \log n)\) - Expected with random pivots.
- **Worst Case**: \(O(n^2)\) - Occurs when the pivot is always the smallest or largest element, leading to unbalanced partitions (for example, when the array is already sorted).

## Space Complexity

- **Space Complexity**: \(O(\log n)\) - This comes from the recursion stack used by the recursive calls of the `partitionSort` function.

