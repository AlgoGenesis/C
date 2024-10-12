#include <stdio.h>

void fibonacci_recursive(int n) {
    if (n < 0) {
        return;
    }
    else if (n == 0) {
        printf("%d, ", 0);
        return;
    }
    else if (n == 1) {
        printf("%d, ", 0);
        printf("%d, ", 1);
        return;
    }

    int a = 0, b = 1, next;
    printf("Fibonacci Series (Recursive): %d, %d, ", a, b);

    for (int i = 2; i < n; i++) {
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
        fibonacci_recursive(n);
    }
    return 0;
}
