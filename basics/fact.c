#include <stdio.h>

// Function to calculate factorial iteratively
unsigned long long factorial_iterative(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate factorial recursively
unsigned long long factorial_recursive(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial_recursive(n - 1);
}

int main() {
    int number;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        // Calculate factorial using iterative method
        unsigned long long iterative_result = factorial_iterative(number);
        printf("Factorial of %d (iterative) is: %llu\n", number, iterative_result);

        // Calculate factorial using recursive method
        unsigned long long recursive_result = factorial_recursive(number);
        printf("Factorial of %d (recursive) is: %llu\n", number, recursive_result);
    }

    return 0;
}