#include <stdio.h>
#include <stdlib.h>

#define RUN 32 // Defining the size of run for insertion sort

// Function to perform insertion sort on a subarray
void insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// Function to merge two sorted subarrays
void merge(int arr[], int left, int mid, int right) {
    int len1 = mid - left + 1, len2 = right - mid;
    int *leftArr = (int*)malloc(len1 * sizeof(int));
    int *rightArr = (int*)malloc(len2 * sizeof(int));

    // Copy data to temporary arrays
    for (int i = 0; i < len1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < len2; i++)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    // Merge the temp arrays back into arr[left...right]
    while (i < len1 && j < len2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr, if any
    while (i < len1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr, if any
    while (j < len2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    free(leftArr);
    free(rightArr);
}

// Function to perform TimSort on the array
void timSort(int arr[], int n) {
    // Sort individual subarrays of size RUN using insertion sort
    for (int i = 0; i < n; i += RUN)
        insertionSort(arr, i, i + RUN - 1 < n - 1 ? i + RUN - 1 : n - 1);

    // Start merging the sorted subarrays
    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = (left + 2 * size - 1 < n - 1) ? left + 2 * size - 1 : n - 1;

            if (mid < right)
                merge(arr, left, mid, right);
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Example usage
int main() {
    int arr[] = {10, 3, 2, 8, 6, 4, 5, 1, 9, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    timSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
