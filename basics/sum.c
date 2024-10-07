#include <stdio.h>

// Function to calculate the sum of the harmonic series
double sum_of_series(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / i; // Add the reciprocal of each integer
    }
    return sum;
}

int main() {
    int number;

    printf("Enter a positive integer n to calculate the sum of the series S = 1 + 1/2 + 1/3 + ... + 1/n: ");
    scanf("%d", &number);

    if (number <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        double result = sum_of_series(number);
        printf("The sum of the series up to %d is: %.6f\n", number, result);
    }

    return 0;
}