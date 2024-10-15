#include <stdio.h>
#include <stdlib.h>

// Function to merge two subarrays
void merge(int arr[], int start, int mid, int end) {
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    int* left = (int*)malloc(leftSize * sizeof(int));
    int* right = (int*)malloc(rightSize * sizeof(int));

    for (int i = 0; i < leftSize; i++)
        left[i] = arr[start + i];
    for (int j = 0; j < rightSize; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = start;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < leftSize) {
        arr[k++] = left[i++];
    }

    while (j < rightSize) {
        arr[k++] = right[j++];
    }

    free(left);
    free(right);
}

// Function to perform Strand Sort
void strand_sort(int arr[], int n) {
    if (n <= 1) return;

    int* sorted = (int*)malloc(n * sizeof(int));
    int sortedIndex = 0;

    while (n > 0) {
        // Find the next increasing subsequence
        int* subsequence = (int*)malloc(n * sizeof(int));
        int subsequenceSize = 0;

        subsequence[subsequenceSize++] = arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i] >= subsequence[subsequenceSize - 1]) {
                subsequence[subsequenceSize++] = arr[i];
            }
        }

        // Copy the found subsequence to the sorted array
        for (int i = 0; i < subsequenceSize; i++) {
            sorted[sortedIndex++] = subsequence[i];
        }

        // Remove the found subsequence from the original array
        int newSize = 0;
        for (int i = 0; i < n; i++) {
            int found = 0;
            for (int j = 0; j < subsequenceSize; j++) {
                if (arr[i] == subsequence[j]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                arr[newSize++] = arr[i];
            }
        }
        n = newSize;

        free(subsequence);
    }

    // Copy sorted elements back to the original array
    for (int i = 0; i < sortedIndex; i++) {
        arr[i] = sorted[i];
    }

    free(sorted);
}

// Function to print the array
void print_array(int arr[], int n) {
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
    print_array(arr, n);

    strand_sort(arr, n);

    printf("Sorted array: ");
    print_array(arr, n);

    return 0;
}
