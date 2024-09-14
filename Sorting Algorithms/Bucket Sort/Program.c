#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10 // Number of buckets

// Function to perform insertion sort on a bucket
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;

        // Move elements that are greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to perform Bucket Sort
void bucketSort(float arr[], int n) {
    // Create an array of buckets
    float** buckets = (float**)malloc(BUCKET_SIZE * sizeof(float*));
    int* bucketSizes = (int*)calloc(BUCKET_SIZE, sizeof(int));

    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = (float*)malloc(n * sizeof(float)); // Allocate memory for each bucket
    }

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(BUCKET_SIZE * arr[i]);
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i]; // Place element in bucket
    }

    // Sort each bucket
    for (int i = 0; i < BUCKET_SIZE; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
        }
    }

    // Concatenate sorted buckets
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    // Free allocated memory
    for (int i = 0; i < BUCKET_SIZE; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

int main() {
    float arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n); // Perform Bucket Sort

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");

    return 0;
}