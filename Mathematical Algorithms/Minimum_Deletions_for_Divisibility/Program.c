#include <stdio.h>

// Function to calculate GCD of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate GCD of an array
int gcdArray(int arr[], int n) {
    int result = arr[0];
    for (int i = 1; i < n; i++) {
        result = gcd(result, arr[i]);
        if (result == 1) { // Early exit if GCD becomes 1
            break;
        }
    }
    return result;
}

// Function to find the minimum deletions required
int minimumDeletionsToDivisible(int arr[], int n) {
    int divisor = gcdArray(arr, n);
    int deletions = 0;
    
    // Count elements not divisible by the GCD of the array
    for (int i = 0; i < n; i++) {
        if (arr[i] % divisor != 0) {
            deletions++;
        }
    }
    
    return deletions;
}

int main() {
    int n;
    
    // Read the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Read the elements of the array
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Find and print the minimum deletions required
    int result = minimumDeletionsToDivisible(arr, n);
    printf("Minimum deletions required: %d\n", result);
    
    return 0;
}
