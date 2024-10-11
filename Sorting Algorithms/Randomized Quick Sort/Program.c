#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to find the first index greater than the pivot
int findFirstGreater(int *array, int start, int end, int pivot)
{
    for (int index = start; index <= end; index++)
    {
        if (array[index] > pivot)
            return index; // Return index if element is greater than pivot
    }
    return end + 1; // Return out of bounds if no greater element found
}

// Function to find the first index smaller than the pivot
int findFirstSmaller(int *array, int start, int end, int pivot)
{
    for (int index = start; index >= end; index--)
    {
        if (array[index] < pivot)
            return index; // Return index if element is smaller than pivot
    }
    return -1; // Return -1 if no smaller element found
}

// Function to swap two elements in the array
void swapElements(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

// Function to perform the Randomized Quick Sort algorithm
void randomizedQuickSort(int *array, int left, int right)
{
    if (left >= right)
        return; // Base case: if the array has one or no element

    int randomIndex = left + (rand() % (right - left));
    int pivot = array[randomIndex]; // Select a random pivot
    int i = findFirstGreater(array, left, right, pivot);
    int j = findFirstSmaller(array, right, left, pivot);

    // Partitioning the array around the pivot
    while (i <= j)
    {
        swapElements(&array[i], &array[j]); // Swap elements
        i = findFirstGreater(array, i, right, pivot);
        j = findFirstSmaller(array, j, left, pivot);
    }

    // Recursive calls to sort the sub-arrays
    if (randomIndex > j && randomIndex > i)
    {
        swapElements(&array[i], &array[randomIndex]);
        randomizedQuickSort(array, left, i - 1);
        randomizedQuickSort(array, i + 1, right);
    }
    else if (randomIndex < j && randomIndex < i)
    {
        swapElements(&array[j], &array[randomIndex]);
        randomizedQuickSort(array, left, j - 1);
        randomizedQuickSort(array, j + 1, right);
    }
    else
    {
        randomizedQuickSort(array, left, randomIndex - 1);
        randomizedQuickSort(array, randomIndex + 1, right);
    }
}

int main()
{
    srand(time(0));
    int elementCount;

    // Prompt user for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &elementCount);

    int *array = (int *)malloc(elementCount * sizeof(int));
    
    // Prompt user for the elements of the array
    printf("Enter the elements: ");
    for (int i = 0; i < elementCount; i++)
    {
        scanf("%d", &array[i]);
    }

    randomizedQuickSort(array, 0, elementCount - 1);
    
    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < elementCount; i++)
    {
        printf("%d ", array[i]);
    }

    free(array);
    printf("\n");

    return 0;
}