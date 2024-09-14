#include <stdio.h>

// Recursive function to calculate Fibonacci number
int fibonacci(int n) {
    if (n == 0) {
        return 0; // Base case: F(0) = 0
    } else if (n == 1) {
        return 1; // Base case: F(1) = 1
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
    }
}

int main() {
    int n;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1; // Exit if input is negative
    }

    printf("Fibonacci number F(%d) = %d\n", n, fibonacci(n));
    return 0;
}
