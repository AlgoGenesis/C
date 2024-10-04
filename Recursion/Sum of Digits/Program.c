#include <stdio.h>

int sumOfDigits(int n) {
    // Base case: if n is 0, return 0
    if (n == 0) {
        return 0;
    }
    // Recursive case: add the last digit to the sum of the remaining digits
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    printf("Sum of digits: %d\n", sumOfDigits(num));
    return 0;
}