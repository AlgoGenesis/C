#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int capacity;
    int size;
} MinHeap;

// Function to create a min-heap
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->capacity = capacity;
    minHeap->size = 0;
    minHeap->array = (int*)malloc(capacity * sizeof(int));
    return minHeap;
}

// Function to swap two elements in the heap
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to heapify the min-heap
void minHeapify(MinHeap *minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left] < minHeap->array[smallest]) {
        smallest = left;
    }
    if (right < minHeap->size && minHeap->array[right] < minHeap->array[smallest]) {
        smallest = right;
    }
    if (smallest != idx) {
        swap(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Function to insert a new element into the min-heap
void insertMinHeap(MinHeap *minHeap, int element) {
    if (minHeap->size == minHeap->capacity) {
        return; // Heap is full
    }
    minHeap->array[minHeap->size] = element;
    int current = minHeap->size;
    minHeap->size++;

    // Fix the min-heap property
    while (current != 0 && minHeap->array[current] < minHeap->array[(current - 1) / 2]) {
        swap(&minHeap->array[current], &minHeap->array[(current - 1) / 2]);
        current = (current - 1) / 2;
    }
}

// Function to extract the minimum element from the min-heap
int extractMin(MinHeap *minHeap) {
    if (minHeap->size <= 0) {
        return -1; // Heap is empty
    }
    if (minHeap->size == 1) {
        return minHeap->array[--minHeap->size];
    }

    int root = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);

    return root;
}

// Main function
int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    MinHeap *minHeap = createMinHeap(n); // Create a min-heap
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        insertMinHeap(minHeap, value); // Insert elements into the min-heap
    }

    while (minHeap->size > 1) {
        int x = extractMin(minHeap); // Extract the minimum element
        int y = extractMin(minHeap); // Extract the second minimum element
        insertMinHeap(minHeap, x + y); // Insert the sum back into the min-heap
    }

    printf("%d\n", extractMin(minHeap)); // Print the final result

    free(minHeap->array); // Free allocated memory
    free(minHeap); // Free the min-heap
    return 0;
}
