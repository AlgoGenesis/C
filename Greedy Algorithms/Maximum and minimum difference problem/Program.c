#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort (ascending order)
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    
    int *arr = (int *)malloc(n * sizeof(int)); // Dynamically allocate memory for the array
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array in ascending order
    qsort(arr, n, sizeof(int), compare);

    long long int min = 0;
    long long int max = 0;

    // Calculate max and min values
    for (int i = 0; i < n / 2; i++) {
        max += abs(arr[n - 1 - i] - arr[i]); // Calculate max
        min += abs(arr[2 * i] - arr[2 * i + 1]); // Calculate min
    }

    printf("%lld  %lld\n", max, min); // Print results

    free(arr); // Free allocated memory
    return 0;
}
