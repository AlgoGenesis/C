#include <stdio.h>
#include <stdlib.h>

// Function to recursively find all subset sums
void findSubsetSums(int arr[], int n, int index, int current_sum, int result[], int *result_index) {
    // Base condition: if we have traversed the entire array
    if (index == n) {
        result[*result_index] = current_sum;  // Add the current sum to the result array
        (*result_index)++;
        return;
    }

    // Recursive case: two choices for each element
    // 1. Pick the element (include it in the sum)
    findSubsetSums(arr, n, index + 1, current_sum + arr[index], result, result_index);

    // 2. Don't pick the element (exclude it from the sum)
    findSubsetSums(arr, n, index + 1, current_sum, result, result_index);
}

// Function to compare two integers for sorting
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;

    // Input: Number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input: Array elements
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // There are 2^n subsets, so we need an array to store the subset sums
    int result[1 << n];  // This is 2^n in size
    int result_index = 0;

    // Call the recursive function starting from index 0 and current sum 0
    findSubsetSums(arr, n, 0, 0, result, &result_index);

    // Sort the subset sums
    qsort(result, result_index, sizeof(int), compare);

    // Output: All subset sums in increasing order
    printf("Subset sums in increasing order: ");
    for (int i = 0; i < result_index; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
