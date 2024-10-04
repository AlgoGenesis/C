#include <stdio.h>

// Function to swap two numbers 
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Wave sort function 
void waveSort(int arr[], int n) {
    for (int i = 0; i < n; i += 2) {
        if (i > 0 && arr[i] < arr[i - 1]) {
            swap(arr, i, i - 1);
        }
        if (i < n - 1 && arr[i] < arr[i + 1]) {
            swap(arr, i, i + 1);
        }
    }
}

// Main function 
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the array elements: ");
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    waveSort(arr, n);
    printf("Wave sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
