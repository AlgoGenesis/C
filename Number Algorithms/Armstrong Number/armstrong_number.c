#include <stdio.h>
#include <math.h>

int main() {
    int num, originalNum, remainder, numDigits = 0, sum = 0;

    // Input a positive integer
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    originalNum = num;

    // Determine the number of digits in the number
    while (originalNum != 0) {
        originalNum /= 10;
        numDigits++;
    }

    originalNum = num; // Reset originalNum for the calculation

    // Calculate the sum of each digit raised to the power of numDigits
    while (originalNum != 0) {
        remainder = originalNum % 10; // Get the last digit
        sum += pow(remainder, numDigits); // Raise to the power of numDigits and add to sum
        originalNum /= 10; // Remove the last digit
    }

    // Check if the number is an Armstrong number
    if (sum == num) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }

    return 0;
}
