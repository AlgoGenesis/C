#include <stdio.h>
#include <stdlib.h>

void cocktailSort(int arr[], int n) {
    int swapped = 1;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = 0;

        // Forward pass: move the largest element to the end
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        --end;

        // Backward pass: move the smallest element to the beginning
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }

        ++start;
    }
}

// function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    
    // Size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamic memory allocation for the array
    int *arr = (int *)malloc(n * sizeof(int));
    
    // Input: Elements of the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: \n");
    printArray(arr, n);

    // Sorting the array
    cocktailSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
