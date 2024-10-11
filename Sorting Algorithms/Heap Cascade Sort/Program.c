// Heap Cascade Sorting Algorithm
// A variation of Heap Sort that builds the heap in a cascading manner. Instead of building a complete heap initially, it progressively inserts elements into a binary heap, 
// maintaining the heap property after each insertion.
#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to "bubble up" and restore the heap property after insertion
void bubbleUp(int arr[], int index) {
    int parent = (index - 1) / 2;

    // Continue bubbling up while the new node is greater than its parent
    if (index > 0 && arr[index] > arr[parent]) {
        swap(&arr[index], &arr[parent]);
        bubbleUp(arr, parent);  // Recursively bubble up
    }
}

// Function to progressively insert an element into the heap and maintain the heap property
void insertIntoHeap(int arr[], int size, int element) {
    arr[size] = element;  // Insert the new element at the end
    bubbleUp(arr, size);  // Restore heap property by bubbling up
}

// Function to "heapify down" after extracting the root
void heapifyDown(int arr[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapifyDown(arr, size, largest);
    }
}

// Function to perform the heap sort
void heapCascadeSort(int arr[], int n) {
    // Step 1: Progressive insertion to build the heap
    for (int i = 1; i < n; i++) {
        insertIntoHeap(arr, i, arr[i]);  // Insert and cascade (bubble up)
    }

    // Step 2: Heap extraction (similar to regular heap sort)
    for (int i = n - 1; i > 0; i--) {
        // Swap the current root (maximum) to the end of the array
        swap(&arr[0], &arr[i]);

        // Heapify the reduced heap
        heapifyDown(arr, i, 0);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver function
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    heapCascadeSort(arr, n);

    printf("Sorted array after Heap Cascade Sort:\n");
    printArray(arr, n);

    return 0;
}
