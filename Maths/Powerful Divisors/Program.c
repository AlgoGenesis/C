#include <stdio.h>
#include <stdlib.h>

// Function to get the maximum value in the array
int getMax(int *A, int n) {
    int max = A[0];
    int i; // Declare the loop variable here
    for (i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

// Function to check if a number is a power of two
int isPower(int num) {
    return (num > 0) && ((num & (num - 1)) == 0);
}

// Function to calculate powerful divisors
int* powerfulDivisors(int* A, int n1, int *len1) {
    int max = getMax(A, n1);
    int* div = (int*)calloc(max + 1, sizeof(int)); // Array to count divisors
    int* good = (int*)calloc(max + 1, sizeof(int)); // Array to check powerful divisors
    int* prefix = (int*)calloc(max + 1, sizeof(int)); // Prefix sum array
    
    // Counting divisors
    for (int i = 1; i <= max; i++) {
        for (int j = i; j <= max; j += i) {
            div[j]++;
        }
    }
    
    // Identifying powerful divisors
    for (int i = 0; i <= max; i++) {
        if (isPower(div[i])) {
            good[i] = 1;
        }
    }
    
    // Building the prefix sum array
    prefix[0] = good[0];
    for (int i = 1; i <= max; i++) {
        prefix[i] = prefix[i - 1] + good[i];
    }
    
    // Preparing the result array
    *len1 = n1; // Set the length of the result array
    int* ans = (int*)malloc(n1 * sizeof(int));
    for (int i = 0; i < n1; i++) {
        ans[i] = prefix[A[i]] - 1; // Subtracting 1 for the count of 0
    }
    
    // Freeing allocated memory
    free(div);
    free(good);
    free(prefix);
    
    return ans;
}

// Example usage
int main() {
    int A[] = {3, 5, 10};
    int n1 = sizeof(A) / sizeof(A[0]);
    int len1;
    
    int* result = powerfulDivisors(A, n1, &len1);
    
    printf("Powerful Divisors Count:\n");
    for (int i = 0; i < len1; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    // Free the result array
    free(result);
    
    return 0;
}
