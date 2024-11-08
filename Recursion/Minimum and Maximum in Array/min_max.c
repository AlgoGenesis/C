#include <stdio.h>

int findMin(int arr[], int n, int index) {
    // Base case: If we've reached the end of the array
    if (index == n - 1)
        return arr[index];
    
    // Recursive step: Find minimum of the current element and the rest
    int minRest = findMin(arr, n, index + 1);
    return (arr[index] < minRest) ? arr[index] : minRest;
}

int findMax(int arr[], int n, int index) {
    // Base case: If we've reached the end of the array
    if (index == n - 1)
        return arr[index];
    
    // Recursive step: Find maximum of the current element and the rest
    int maxRest = findMax(arr, n, index + 1);
    return (arr[index] > maxRest) ? arr[index] : maxRest;
}

int main() {
    int n;

    // Input size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n]; // Declare array

    // Input array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Print the array
    printf("The elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    // Go to next line before printing the maximum and minimum element in the array
    printf("\n");

    // Find minimum and maximum
    int min = findMin(arr, n, 0);
    int max = findMax(arr, n, 0);

    // Print results
    printf("Minimum element in the array: %d\n", min);
    printf("Maximum element in the array: %d\n", max);

    return 0;
}