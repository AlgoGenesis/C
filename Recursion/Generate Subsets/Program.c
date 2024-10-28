#include <stdio.h>

void generateSubsets(int arr[], int n, int index, int subset[], int subsetSize) {
    // Base case: If we've processed all elements
    if (index == n) {
        printf("{ ");
        for (int i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("}\n");
        return;
    }

    // Exclude the current element and move to the next
    generateSubsets(arr, n, index + 1, subset, subsetSize);

    // Include the current element in the subset and move to the next
    subset[subsetSize] = arr[index];
    generateSubsets(arr, n, index + 1, subset, subsetSize + 1);
}

int main() {
    int arr[] = {1, 2, 3};  // Example set
    int n = sizeof(arr) / sizeof(arr[0]);

    int subset[n];  // Temporary array to store the subset
    generateSubsets(arr, n, 0, subset, 0);  // Start recursion

    return 0;
}
