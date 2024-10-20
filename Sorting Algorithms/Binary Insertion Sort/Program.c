#include <stdio.h>
#include <stdlib.h>

/* Function to display the array */
void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int findPosition(int *array, int key, int low, int high)
{
    if (low >= high)
        return (key > array[low]) ? (low + 1) : low;

    int mid = low + (high - 1) / 2;

    if (array[mid] == key)
        return mid + 1;
    else if (array[mid] > key)
        return findPosition(array, key, low, mid - 1);
    else
        return findPosition(array, key, mid + 1, high);
}

/* Sort the array using Binary Insertion Sort */
void binaryInsertionSort(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        int key = array[i];
        int j = i - 1;
        int position = findPosition(array, key, 0, j);

        while (j >= position)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

int main()
{
    int n;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);

    int *array = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Original array: ");
    printArray(array, n);

    binaryInsertionSort(array, n);

    printf("Sorted array: ");
    printArray(array, n);

    free(array);
    return 0;
}