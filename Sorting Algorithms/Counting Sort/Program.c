#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void countingSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    int* count = (int*)calloc(max + 1, sizeof(int));
    int* output = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    free(count);
    free(output);
}

// Optimized version using in-place counting
void optimizedCountingSort(int arr[], int n) {
    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    int range = max - min + 1;
    int* count = (int*)calloc(range, sizeof(int));

    for (int i = 0; i < n; i++)
        count[arr[i] - min]++;

    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            arr[index++] = i + min;
            count[i]--;
        }
    }

    free(count);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    countingSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    // Reset array for optimized version
    int arr2[] = {4, 2, 2, 8, 3, 3, 1};

    printf("Original array (for optimized version): \n");
    printArray(arr2, n);

    optimizedCountingSort(arr2, n);

    printf("Sorted array (optimized version): \n");
    printArray(arr2, n);

    return 0;
}