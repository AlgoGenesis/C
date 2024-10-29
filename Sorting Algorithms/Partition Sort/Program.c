#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements in the array
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Partition function implementing Hoare's partitioning scheme
// It rearranges the elements around a pivot and returns the index where partitioning ends
int partition(int arr[], int low, int high)
{
    int pivot = arr[low]; // Selecting the first element as the pivot
    int i = low - 1, j = high + 1;

    while (1)
    {
        // Move `i` right until an element >= pivot is found
        do
        {
            i++;
        } while (arr[i] < pivot);

        // Move `j` left until an element <= pivot is found
        do
        {
            j--;
        } while (arr[j] > pivot);

        // If pointers cross, partitioning is complete
        if (i >= j)
            return j;

        // Swap elements at `i` and `j` to move them to correct sides of the pivot
        swap(&arr[i], &arr[j]);
    }
}

// Recursive function to apply partition sort to subarrays
void partitionSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Partition the array and get the partition index
        int value = partition(arr, low, high);

        // Recursively sort elements before and after partition
        partitionSort(arr, low, value);
        partitionSort(arr, value + 1, high);
    }
}

// Function to print the elements of the array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[20];             // Array to hold random numbers
    int range = 100;          // Range of random numbers to generate

    // Fill the array with random numbers from 1 to 100
    for (int i = 0; i < 20; i++)
    {
        arr[i] = rand() % range + 1;
    }

    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    printf("Array: \n");
    printArray(arr, size); // Print the unsorted array

    partitionSort(arr, 0, size - 1); // Sort the array using partition sort
    printf("Sorted Array: \n");
    printArray(arr, size); // Print the sorted array

    return 0;
}