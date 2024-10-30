#include <stdio.h>

#define MAX_DEPTH 32 

void insertionSort(int arr[], int left, int right, int reverse) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && ((reverse == -1 && arr[j] < key) || (reverse == 1 && arr[j] > key))) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void heapify(int arr[], int n, int i, int reverse) {
    int extreme = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && ((reverse == -1 && arr[left] > arr[extreme]) || (reverse == 1 && arr[left] < arr[extreme])))
        extreme = left;

    if (right < n && ((reverse == -1 && arr[right] > arr[extreme]) || (reverse == 1 && arr[right] < arr[extreme])))
        extreme = right;

    if (extreme != i) {
        int temp = arr[i];
        arr[i] = arr[extreme];
        arr[extreme] = temp;
        heapify(arr, n, extreme, reverse);
    }
}


void heapsort(int arr[], int n, int reverse) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, reverse);

    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0, reverse);
    }
}

// For Quicksort
int partition(int arr[], int low, int high, int reverse) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if ((reverse == -1 && arr[j] > pivot) || (reverse == 1 && arr[j] < pivot)) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void introsortUtil(int arr[], int low, int high, int depthLimit, int reverse) {
    if (high - low < 16) { // Use Insertion Sort for small arrays
        insertionSort(arr, low, high, reverse);
        return;
    }
    
    if (depthLimit == 0) { // If depth limit is reached, use Heapsort
        heapsort(arr + low, high - low + 1, reverse);
        return;
    }
    
    int pivotIndex = partition(arr, low, high, reverse);
    introsortUtil(arr, low, pivotIndex - 1, depthLimit - 1, reverse);
    introsortUtil(arr, pivotIndex + 1, high, depthLimit - 1, reverse);
}

// Main Introsort function
void introsort(int arr[], int n, int reverse) {
    introsortUtil(arr, 0, n - 1, MAX_DEPTH, reverse);
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {34, 7, 23, 32, 5, 62};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    // Sort in ascending order
    introsort(arr, n, 1);
    printf("Sorted array (ascending): ");
    printArray(arr, n);

    // Sort in descending order
    introsort(arr, n, -1);
    printf("Sorted array (descending): ");
    printArray(arr, n);

    return 0;
}
