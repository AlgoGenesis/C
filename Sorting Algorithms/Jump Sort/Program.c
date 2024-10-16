#include <stdio.h>
#include <math.h>

// Function to perform Jump Sort
void jump_sort(int arr[], int n) {
    int step = (int)sqrt(n);  // Determine the optimal jump step
    int prev = 0;

    // Finding the block where the element is present
    while (arr[step - 1] < arr[n - 1] && step < n) {
        prev = step;
        step += (int)sqrt(n);
        if (step > n) {
            step = n;
        }
    }

    // Linear search for the element in the block
    for (int i = prev; i < step; i++) {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
            // Swap arr[j] and arr[j-1]
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
        }
    }
}

// Function to print the array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Example usage
int main() {
    int arr[] = {10, 3, 2, 8, 6, 4, 5, 1, 9, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    print_array(arr, n);

    jump_sort(arr, n);

    printf("Sorted array: ");
    print_array(arr, n);

    return 0;
}
