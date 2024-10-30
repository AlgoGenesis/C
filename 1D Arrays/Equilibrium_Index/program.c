#include <stdio.h>
#include <stdbool.h>

// Function to find the equilibrium index in the given array
int arrayEquilibriumIndex(int* arr, int n) {
    // If the length of the array is 0, no equilibrium index can exist
    if (n == 0) {
        return -1;
    }

    // Declare arrays to store the left sum and right sum
    int leftSum[n];
    int rightSum[n];

    // Initialize the left sum array
    leftSum[0] = 0;
    for (int i = 1; i < n; i++) {
        leftSum[i] = leftSum[i - 1] + arr[i - 1];
    }

    // Initialize the right sum array
    rightSum[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        rightSum[i] = rightSum[i + 1] + arr[i + 1];
    }

    // Find the equilibrium index
    for (int i = 0; i < n; i++) {
        if (leftSum[i] == rightSum[i]) {
            return i; // Equilibrium index found
        }
    }

    return -1; // No equilibrium index found
}

// Main function to test the arrayEquilibriumIndex function
int main() {
    int n;

    // Prompt the user for the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Check for valid array size
    if (n < 1) {
        printf("Array must have at least 1 element to find an equilibrium index.\n");
        return 1; // Exit with error code
    }

    int arr[n];

    // Prompt the user to enter the elements of the array
    printf("Enter the elements of the array (space-separated):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the function to find the equilibrium index
    int result = arrayEquilibriumIndex(arr, n);

    if (result != -1) {
        printf("Equilibrium Index: %d\n", result);
    } else {
        printf("No equilibrium index exists in the array.\n");
    }

    return 0;
}
