#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Flash sort algorithm function
void flashSort(int arr[], int n) {
    if (n == 0) return;  // No elements to sort

    // Step 1: Find the minimum and maximum values in the array
    int minVal = arr[0];  // Assume first element is the minimum
    int maxIdx = 0;       // Index of the maximum element
    
    for (int i = 1; i < n; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];  // Update minimum value
        }
        if (arr[i] > arr[maxIdx]) {
            maxIdx = i;  // Update index of the maximum value
        }
    }
    
    // If all elements are the same, the array is already sorted
    if (arr[maxIdx] == minVal) return;

    // Step 2: Create an array to hold bucket counts
    int numBuckets = (int)(n * 0.43);  // Number of buckets (can adjust the multiplier)
    int* bucket = (int*)calloc(numBuckets, sizeof(int));  // Allocate memory for bucket counts

    // Step 3: Distribute elements into buckets based on their value
    double scalingFactor = (numBuckets - 1) / (double)(arr[maxIdx] - minVal);  // Scaling factor to determine the bucket index
    for (int i = 0; i < n; ++i) {
        int bucketIdx = (int)(scalingFactor * (arr[i] - minVal));  // Find the bucket for each element
        bucket[bucketIdx]++;  // Increase the count for that bucket
    }

    // Step 4: Convert bucket counts into a cumulative distribution (prefix sum)
    for (int i = 1; i < numBuckets; ++i) {
        bucket[i] += bucket[i - 1];  // Cumulative sum for positioning
    }

    // Step 5: Permutation phase – move elements to their correct buckets
    int moveCount = 0;  // Track the number of moves
    int currentIdx = 0;  // Start from the first element
    int bucketIdx = numBuckets - 1;  // Start with the last bucket

    while (moveCount < n - 1) {
        // Skip already sorted elements
        while (currentIdx > bucket[bucketIdx] - 1) {
            currentIdx++;
            bucketIdx = (int)(scalingFactor * (arr[currentIdx] - minVal));  // Recalculate the bucket index
        }
        
        // Start the "flash" – placing elements in their correct positions
        int flashValue = arr[currentIdx];  // Store the value to move
        while (currentIdx != bucket[bucketIdx]) {  // Until the element is placed in the correct position
            bucketIdx = (int)(scalingFactor * (flashValue - minVal));  // Recalculate the bucket index
            swap(&arr[bucket[bucketIdx] - 1], &flashValue);  // Swap the value to its correct place
            bucket[bucketIdx]--;  // Update the bucket count
            moveCount++;  // Track the number of moved elements
        }
    }

    // Step 6: Use insertion sort for fine-tuning within the sorted sections
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Shift elements to the right to insert the current element at its correct position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    // Free dynamically allocated memory for buckets
    free(bucket);
}

// Helper function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Example array
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print the original array
    printf("Original array:\n");
    printArray(arr, n);

    // Perform flash sort on the array
    flashSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
