# Bubble Sort Algorithm

## Description

Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted. The algorithm gets its name from the way larger elements "bubble" to the top of the list.

### Problem Definition

Given:
- An array `arr` of `n` elements.

Objective:
- Sort the array in ascending order using the Bubble Sort algorithm.

### Algorithm Overview

1. Loop through the entire array.
2. For each element, compare it with the next element.
3. If the current element is greater than the next element, swap them.
4. Repeat the process for each element until no swaps are needed, indicating that the array is sorted.

### Key Updates in Implementation

- **User Input**: The updated program allows users to enter their own array size and elements instead of using a predefined array. This makes the algorithm more interactive.

    ```c
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    // Dynamically allocate memory for the array
    arr = (int *)malloc(n * sizeof(int));
    ```

- **Dynamic Memory Allocation**: The implementation now uses dynamic memory allocation (`malloc`) to create an array based on the user's input, allowing for any size of the array.

    ```c
    arr = (int *)malloc(n * sizeof(int));
    ```

- **Sorting Order Selection**: Users can choose whether to sort the array in ascending or descending order by entering `1` or `0`, enhancing the program's usability.

    ```c
    printf("Enter 1 for ascending order or 0 for descending order: ");
    scanf("%d", &ascending);
    ```

- **Improved Print Function**: The `printArray()` function is used to display the original and sorted arrays clearly.

    ```c
    printf("Original array: \n");
    printArray(arr, n);
    
    printf("Sorted array: \n");
    printArray(arr, n);
    ```

- **Error Handling**: Basic error handling has been added to check if memory allocation was successful.

    ```c
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit if memory allocation fails
    }
    ```

### Time Complexity

The time complexity of the Bubble Sort algorithm is `O(n^2)`, making it inefficient on large datasets compared to more advanced sorting algorithms like Quick Sort and Merge Sort. However, it is simple to implement and can be useful for small datasets or educational purposes.