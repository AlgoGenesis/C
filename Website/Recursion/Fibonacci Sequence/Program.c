#include <stdio.h>

// Recursive function
int factorial(int n)
{
    return (n == 0) ? 1 : n * factorial(n - 1);
}

int main()
{
    int n;
    // Taking input from user
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    if (n < 0)
    { // base case
        printf("Factorial is not defined for negative integers.\n");
        return 1;
    }

    // Print the factorial
    printf("Factorial of %d is %d\n", n, factorial(n));

    return 0;
}