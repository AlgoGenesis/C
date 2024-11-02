#include <stdio.h>

void stalinSort(int arr[], int n) {
    int result[n];   // Array to store the sorted output
    int lastKept = arr[0];
    int j = 0;
    
    // Always keep the first element
    result[j++] = lastKept;

    // Traverse through the array, "keeping" elements that are greater than or equal to the last kept one
    for (int i = 1; i < n; i++) {
        if (arr[i] >= lastKept) {
            lastKept = arr[i];
            result[j++] = arr[i];
        }
    }

    // Print the resulting sorted list
    printf("Sorted numbers (using Stalin Sort): ");
    for (int i = 0; i < j; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of elements to sort (max 100): ");
    scanf("%d", &n);
    if (n > 100 || n < 1) {
        printf("Invalid input. Please enter a number between 1 and 100.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    stalinSort(arr, n);

    return 0;
}
