#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure for a Min-Heap
typedef struct
{
    int *array;
    int size;
    int capacity;
} MinHeap;

// Function to create a Min-Heap with a given capacity
MinHeap *createMinHeap(int capacity)
{
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->array = (int *)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    return minHeap;
}

// Function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Heapify function to maintain the Min-Heap property
void minHeapify(MinHeap *minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left] < minHeap->array[smallest])
        smallest = left;

    if (right < minHeap->size && minHeap->array[right] < minHeap->array[smallest])
        smallest = right;

    if (smallest != idx)
    {
        swap(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Function to insert an element into the Min-Heap
void insertMinHeap(MinHeap *minHeap, int val)
{
    if (minHeap->size == minHeap->capacity)
    {
        printf("Heap overflow\n");
        return;
    }

    int i = minHeap->size++;
    minHeap->array[i] = val;

    // Fix the min heap property if it's violated
    while (i != 0 && minHeap->array[(i - 1) / 2] > minHeap->array[i])
    {
        swap(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to extract the minimum element from the Min-Heap
int extractMin(MinHeap *minHeap)
{
    if (minHeap->size <= 0)
        return INT_MAX;

    if (minHeap->size == 1)
        return minHeap->array[--minHeap->size];

    int root = minHeap->array[0];
    minHeap->array[0] = minHeap->array[--minHeap->size];
    minHeapify(minHeap, 0);

    return root;
}

// Function to merge two sorted arrays using a priority queue (Min-Heap)
void mergeArrays(int arr1[], int size1, int arr2[], int size2)
{
    int mergedSize = size1 + size2;
    MinHeap *minHeap = createMinHeap(mergedSize);

    // Insert all elements of both arrays into the min-heap
    for (int i = 0; i < size1; i++)
    {
        insertMinHeap(minHeap, arr1[i]);
    }

    for (int i = 0; i < size2; i++)
    {
        insertMinHeap(minHeap, arr2[i]);
    }

    // Extract all elements from the min-heap to get them in sorted order
    printf("Merged Array:\n");
    for (int i = 0; i < mergedSize; i++)
    {
        printf("%d ", extractMin(minHeap));
    }

    printf("\n");

    // Free the heap
    free(minHeap->array);
    free(minHeap);
}

int main()
{
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    mergeArrays(arr1, size1, arr2, size2);

    return 0;
}