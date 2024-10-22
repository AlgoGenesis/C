#include <stdio.h>
#include <math.h>

int metaBinarySearch(int arr[], int size, int target) {
    int pos = 0;
    // Calculate the number of bits needed to represent the index
    int bits = (int)(log2(size - 1)) + 1; 

    for (int i = bits; i >= 0; i--) {
        // Check if the current position contains the target
        if (arr[pos] == target) {
            return pos; // Target found
        }

        // Calculate the new position using bitwise OR
        int newPos = pos | (1 << i);

        // If the new position is within bounds and the element is less than or equal to the target
        if (newPos < size && arr[newPos] <= target) {
            pos = newPos; // Update position
        }
    }

    // Final check if the target is at the current position
    return (arr[pos] == target) ? pos : -1; // Return -1 if not found
}

int main() {
    int arr[] = {-2, 10, 100, 250, 32315}; // Example sorted array
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10; // Element to search for

    int result = metaBinarySearch(arr, size, target);

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found.\n");
    }

    return 0;
}
