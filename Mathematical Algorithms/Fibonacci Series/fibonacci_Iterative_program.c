#include <stdio.h>

void fibonacci_iterative(int n) {
    int a = 0, b = 1, next;
    
    printf("Fibonacci Series (Iterative): ");
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%d, ", a);
            continue;
        }
        if (i == 1) {
            printf("%d, ", b);
            continue;
        }
        next = a + b;
        printf("%d, ", next);
        a = b;
        b = next;
    }
    printf("\b\b  \n"); // To remove the last comma and space
}

int main() {
    int n;
    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &n); // Take user input
    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
    } else {
        fibonacci_iterative(n);
    }
    return 0;
}
