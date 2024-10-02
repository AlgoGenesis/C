#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// To find gap between elements
int getNextGap(int gap) {
    // Shrink gap by shrink factor
    gap = (gap * 10) / 13;
    if (gap < 1)
        return 1;
    return gap;
}

// Function to sort array using Comb Sort
void combSort(int arr[], int n) {
    // Initialize gap
    int gap = n;

    // Initialize swapped as true to make sure that
    // loop runs
    int swapped = 1;

    // Keep running while gap is more than 1 and last
    // iteration caused a swap
    while (gap != 1 || swapped == 1) {
        // Find next gap
        gap = getNextGap(gap);

        // Initialize swapped as false so that we can
        // check if swap happened or not
        swapped = 0;

        // Compare all elements with current gap
        for (int i = 0; i < n - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(&arr[i], &arr[i + gap]);
                swapped = 1;
            }
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    combSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}