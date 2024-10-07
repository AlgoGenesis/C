#include <stdio.h>

// Function to print Fibonacci series iteratively
void fibonacci_iterative(int n) {
    int a = 0, b = 1, next;

    printf("Fibonacci Series (Iterative): ");
    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i; // First two Fibonacci numbers are 0 and 1
        } else {
            next = a + b; // Next number is the sum of the previous two
            a = b; // Update a to the last number
            b = next; // Update b to the current number
        }
        printf("%d ", next);
    }
    printf("\n");
}

// Function to calculate Fibonacci number recursively
int fibonacci_recursive(int n) {
    if (n <= 1) {
        return n; // Base case: return n for 0 and 1
    }
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2); // Recursive case
}

int main() {
    int number;

    printf("Enter the number of terms for Fibonacci series: ");
    scanf("%d", &number);

    if (number <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        // Generate Fibonacci series using iterative method
        fibonacci_iterative(number);

        // Generate Fibonacci series using recursive method
        printf("Fibonacci Series (Recursive): ");
        for (int i = 0; i < number; i++) {
            printf("%d ", fibonacci_recursive(i));
        }
        printf("\n");
    }

    return 0;
}