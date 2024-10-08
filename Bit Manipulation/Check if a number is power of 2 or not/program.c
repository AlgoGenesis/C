#include <stdio.h>

// Function to check if a number is a power of two
int is_power_of_two(int num) {
    // A number is a power of two if it is greater than 0
    // and the expression (num & (num - 1)) is 0.
    // This works because powers of two have only one bit set in binary representation.
    return (num > 0) && ((num & (num - 1)) == 0);
}

int main() {
    int num; // Variable to store user input

    // Prompt the user to enter a number
    printf("Enter a number: ");
    
    // Read user input and check if it was successful
    if (scanf("%d", &num) != 1) {
        // If input is invalid, print an error message and exit
        printf("Invalid input. Please enter an integer.\n");
        return 1; // Return a non-zero value to indicate an error
    }

    // Check if the number is a power of two
    if (is_power_of_two(num)) {
        // If true, print that it is a power of two
        printf("%d is a power of 2.\n", num);
    } else {
        // If false, print that it is not a power of two
        printf("%d is not a power of 2.\n", num);
    }

    return 0; // Return 0 to indicate successful execution
}