#include <stdio.h>

// Function to perform cocktail shaker sort
void cocktail_shaker_sort(int arr[], int n) {
    int swapped;
    int start = 0;
    int end = n - 1;

    do {
        swapped = 0;

        // Forward pass
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1; // Swap occurred
            }
        }

        // If nothing moved, then the array is sorted
        if (!swapped) break;

        // Last element is in place, reduce the end
        end--;

        swapped = 0;

        // Backward pass
        for (int i = end; i > start; i--) {
            if (arr[i] < arr[i - 1]) {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                swapped = 1; // Swap occurred
            }
        }

        // Increase the start for the next pass
        start++;

    } while (swapped);
}

// Function to print the array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = {34, 2, 10, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    print_array(arr, n);

    cocktail_shaker_sort(arr, n);

    printf("Sorted array: \n");
    print_array(arr, n);

    return 0;
}
