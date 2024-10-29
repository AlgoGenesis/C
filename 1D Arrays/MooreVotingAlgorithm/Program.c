#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to find the candidate for the majority element
int findCandidate(int* arr, int n) {
    int count = 1, candidate = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] == candidate)
            count++;
        else
            count--;

        if (count == 0) {
            candidate = arr[i];
            count = 1;
        }
    }

    return candidate;
}

// Function to check if the candidate is actually the majority element
bool isMajority(int* arr, int n, int candidate) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate)
            count++;
    }
    return count > n / 2;
}

// Function to print the majority element, if it exists
void printMajority(int* arr, int n) {
    int candidate = findCandidate(arr, n);

    if (isMajority(arr, n, candidate))
        printf("The majority element is %d\n", candidate);
    else
        printf("No majority element exists\n");
}

// Main function
int main() {
    int n;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int* arr = (int*)malloc(n * sizeof(int));
    
    // Input the elements of the array
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the function to print the majority element
    printMajority(arr, n);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
