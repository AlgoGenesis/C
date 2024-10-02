#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition function for QuickSort
int partition(int arr[], int low, int high) {
    // Choose the rightmost element as pivot
    int pivot = arr[high];
    // Index of smaller element and indicates
    // the right position of pivot found so far
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            // Increment index of smaller element
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Basic QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[p] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Optimized QuickSort (using insertion sort for small subarrays)
void insertionSort(int arr[], int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void optimizedQuickSort(int arr[], int low, int high) {
    while (low < high) {
        // Use insertion sort for small subarrays
        if (high - low + 1 < 10) {
            insertionSort(arr, low, high);
            break;
        } else {
            int pi = partition(arr, low, high);

            // Optimize recursion by handling smaller partition first
            if (pi - low < high - pi) {
                optimizedQuickSort(arr, low, pi - 1);
                low = pi + 1;
            } else {
                optimizedQuickSort(arr, pi + 1, high);
                high = pi - 1;
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

    quickSort(arr, 0, n - 1);

    printf("Sorted array: \n");
    printArray(arr, n);

    // Reset array for optimized version
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};

    printf("Original array (for optimized version): \n");
    printArray(arr2, n);

    optimizedQuickSort(arr2, 0, n - 1);

    printf("Sorted array (optimized version): \n");
    printArray(arr2, n);

    return 0;
}