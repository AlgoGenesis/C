// basic C header file
#include <stdio.h>

// function to perform insertion sort
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        // store the current element to be stored
        int key = arr[i];
        int j = i - 1;

        // move elements of arr[0...i-1]
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        // insert the key at the correct position
        arr[j + 1] = key;
    }
}
// function to print element
void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {78, 650, 100, 21, 23, 12, 90, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:- \n");
    print_array(arr, n);

    insertionSort(arr, n);

    printf("Sorted array:- \n");
    print_array(arr, n);
    return 0;
}