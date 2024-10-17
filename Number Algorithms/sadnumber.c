#include <stdio.h>

int main() {
    int num, digit, sum = 0;
    int seen[1000] = {0}; // Array to track previously seen sums
    int index = 0; // Index for seen array

    // Prompt user for input
    printf("Enter any number: ");
    scanf("%d", &num);
    
    // While the number has not become 1 and the current sum hasn't been seen before
    while (num != 1 && !seen[num]) {
        // Mark the current number as seen
        seen[num] = 1;

        // Reset sum for the next iteration
        sum = 0;

        // Calculate the sum of squares of the digits
        while (num > 0) {
            digit = num % 10;
            sum += digit * digit;
            num /= 10;
        }

        // Update num to the new sum
        num = sum;
    }

    // If the sum is 1, it's not a sad number. Otherwise, it is.
    if (num == 1) {
        printf("It is not a sad number.\n");
    } else {
        printf("It is a sad number.\n");
    }

    return 0;
}
