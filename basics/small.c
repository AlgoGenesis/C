#include <stdio.h>

int main() {
    int n, i, number;
    int smallest;

    // Prompt the user to enter the number of elements in the series
    printf("Enter the number of elements in the series: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer greater than 0.\n");
        return 1; // Exit the program with an error code
    }

    // Prompt the user to enter the first number
    printf("Enter number 1: ");
    scanf("%d", &number);
    smallest = number; // Initialize smallest with the first number

    // Loop to read the remaining numbers and find the smallest
    for (i = 2; i <= n; i++) {
        printf("Enter number %d: ", i);
        scanf("%d", &number);

        // Update smallest if the current number is smaller
        if (number < smallest) {
            smallest = number;
        }
    }

    // Print the smallest number found
    printf("The smallest number in the series is: %d\n", smallest);

    return 0;
}