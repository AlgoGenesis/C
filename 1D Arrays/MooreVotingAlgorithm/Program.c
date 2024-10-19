#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to find the majority element if it exists
void findAndPrintMajority(int* arr, int n) {
    if (n == 0) {  // Handle empty array case
        printf("No majority element exists\n");
        return;
    }

    // Step 1: Find the candidate for majority element using Boyer-Moore Voting Algorithm
    int candidate = arr[0];
    int count = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == candidate) {
            count++;
        } else {
            count--;
            if (count == 0) {
                candidate = arr[i];
                count = 1;
            }
        }
    }

    // Step 2: Verify if the candidate is the majority element in a single pass
    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate) {
            count++;
        }
    }

    // Step 3: Output the result
    if (count > n / 2) {
        printf("The majority element is %d\n", candidate);
    } else {
        printf("No majority element exists\n");
    }
}

// Main function
int main() {
    int n;

    // Input the number of elements
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {  // Validate input for positive integer
        printf("Invalid number of elements!\n");
        return 1;
    }

    // Dynamically allocate memory for the array and check for malloc failure
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input the elements of the array
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {  // Validate integer input
            printf("Invalid input!\n");
            free(arr);
            return 1;
        }
    }

    // Find and print the majority element
    findAndPrintMajority(arr, n);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
