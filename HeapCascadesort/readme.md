# **Heap Cascade Sort**

## *Description*

Heap Cascade Sort sorts an array by utilizing a binary heap data structure. The algorithm involves building a max-heap from the input data, followed by repeatedly extracting the largest element (the root) and adjusting the heap structure, a process referred to as cascading.

Heap Cascade Sort operates in O(n log n) time, making it efficient for large datasets. 
The space complexity is O(1) since the sorting is done in place without requiring additional memory.

## **Algorithm Overview**

Heap Cascade Sort consists of two main phases:

### Building the Max-Heap:

The input array is rearranged to form a max-heap where the largest element is at the root.

### Sorting by Cascading:
In each iteration:

The root element (largest in the heap) is swapped with the last element in the heap.

The size of the heap is reduced by one.

The new root is cascaded down the heap by recursively swapping it with its largest child until the max-heap property is restored.

## Structures
Binary Heap: A complete binary tree that satisfies the heap property. In this case, it is used as a max-heap.

## Functions

### 1. void heapify(int arr[], int n, int i)
##### Description:
Restores the max-heap property for a subtree rooted at index i. The function assumes that the binary trees rooted at the left and right children are already heaps.

##### Parameters:
arr[]: The input array.

n: The size of the heap.

i: The root index of the subtree.

##### Returns:

This function does not return a value; it modifies the array in place.

### 2. void heapSort(int arr[], int n)

#### Description:

Implements the heap sort algorithm. First, it builds a max-heap from the input array. Then, it repeatedly extracts the largest element by swapping the root with the last element and cascades the new root down the heap.

#### Parameters:
arr[]: The input array.

n: The size of the array.

#### Returns:
This function does not return a value; it sorts the array in place.

## Main Function

### Description:
The entry point of the program:

1.Prompts the user to enter the size of the array.

2.Dynamically allocates memory for the array.

3.Prompts the user to input the elements of the array.

4.Calls heapSort() to sort the array.

5.Prints the sorted array.

6.Frees the dynamically allocated memory before exiting.

## **Memory Management**

#### Dynamic Memory Allocation:
The array is dynamically allocated based on the user input.

##### Freeing Memory:
The allocated memory is freed after the array is sorted to prevent memory leaks.

## **Time Complexity**

O(n log n) where n is the number of elements in the array:
Building the heap: O(n)
Cascading (heapify) after each extraction: O(log n) for each of the n elements.
Space Complexity
O(1) as the sorting is done in place, with no extra memory required.

## **Usage**

#### Compile the program using a C compiler (e.g., gcc):

gcc heap_sort.c -o heap_sort

#### Run the compiled program:

./heap_sort

Input the size and elements of the array when prompted, and the program will return the sorted array.

