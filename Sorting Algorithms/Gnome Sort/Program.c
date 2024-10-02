#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to sort the array using Gnome sort
void gnomeSort(int arr[], int n) {
    int index = 0;

    while (index < n) {
        if (index == 0)
            index++;
        if (arr[index] >= arr[index - 1])
            index++;
        else {
            swap(&arr[index], &arr[index - 1]);
            index--;
        }
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test Gnome Sort
int main() {
    int arr[] = {34, 2, 10, -9, 5, 23, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    gnomeSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}