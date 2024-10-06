#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKET_SIZE 256 // ASCII character set size

// Function to perform Insertion Sort on an array of strings
void insertionSort(char *bucket[], int count) {
    for (int i = 1; i < count; i++) {
        char *temp = bucket[i];
        int j = i - 1;
        while (j >= 0 && strcmp(bucket[j], temp) > 0) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = temp;
    }
}

// Function to perform Bucket Sort on an array of strings
void bucketSort(char *arr[], int n) {
    // Create buckets
    char **buckets[BUCKET_SIZE];
    int bucketCounts[BUCKET_SIZE] = {0};

    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = malloc(n * sizeof(char *));
    }

    // Distribute the strings into buckets based on their first character
    for (int i = 0; i < n; i++) {
        int index = (int)arr[i][0]; // Use the ASCII value of the first character
        buckets[index][bucketCounts[index]] = arr[i];
        bucketCounts[index]++;
    }

    // Sort each bucket and concatenate the results
    int idx = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        if (bucketCounts[i] > 0) {
            insertionSort(buckets[i], bucketCounts[i]);
            for (int j = 0; j < bucketCounts[i]; j++) {
                arr[idx++] = buckets[i][j];
            }
        }
    }

    // Free allocated memory
    for (int i = 0; i < BUCKET_SIZE; i++) {
        free(buckets[i]);
    }
}

// Function to print the array of strings
void printArray(char *arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

int main() {
    char *arr[] = {"apple", "orange", "banana", "grape", "cherry", "kiwi"};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
