#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        // Check if the current element is the target
        if (arr[i] == x) {
            return i; // Return the index of the target
        }
    }
    return -1; // Target not found
}

int main() {
    int arr[] = {2, 3, 4, 10, 40}; // Array
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;

    printf("Enter a number to search: ");
    scanf("%d", &x);

    int result = linearSearch(arr, n, x);
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
