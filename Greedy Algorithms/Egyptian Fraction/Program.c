#include <stdio.h>

// Function to print an Egyptian Fraction
void printEgyptianFraction(int numerator, int denominator) {
    // If the numerator is zero, no need to process further
    if (numerator == 0 || denominator == 0) {
        return;
    }

    // If the numerator divides the denominator perfectly
    if (denominator % numerator == 0) {
        printf("1/%d\n", denominator / numerator);
        return;
    }

    // If the numerator is greater than the denominator
    if (numerator > denominator) {
        printf("%d + ", numerator / denominator);
        printEgyptianFraction(numerator % denominator, denominator);
        return;
    }

    // Get the ceiling of denominator / numerator and print the unit fraction
    int n = denominator / numerator + 1;
    printf("1/%d + ", n);

    // Recur for the remaining fraction
    printEgyptianFraction(numerator * n - denominator, denominator * n);
}

int main() {
    int numerator, denominator;

    // Input numerator and denominator
    printf("Enter the numerator: ");
    scanf("%d", &numerator);
    printf("Enter the denominator: ");
    scanf("%d", &denominator);

    printf("Egyptian Fraction representation of %d/%d is: \n", numerator, denominator);
    printEgyptianFraction(numerator, denominator);

    return 0;
}
