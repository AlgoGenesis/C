#include <stdio.h>

// Function to perform Gnome Sort
void gnomeSort(int arr[], int n) {
    int index = 0;

    while (index < n) {
        if (index == 0) {
            index++;
        }
        if (arr[index] >= arr[index - 1]) {
            index++;
        } else {
            // Swap the elements
            int temp = arr[index];
            arr[index] = arr[index - 1];
            arr[index - 1] = temp;
            index--;
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

// Main function
int main() {
    int arr[] = {34, 2, 10, -9};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: \n");
    printArray(arr, n);

    gnomeSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
