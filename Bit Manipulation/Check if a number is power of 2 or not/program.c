#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// Function to check if a number is a power of two
// int is_power_of_two(int num) {
//     // A number is a power of two if it is greater than 0
//     // and the expression (num & (num - 1)) is 0.
//     // This works because powers of two have only one bit set in binary representation.
//     return (num > 0) && ((num & (num - 1)) == 0);
// }


// Function to check if a number is a power of two
bool is_power_of_two(int n) {
    if (n <= 0) {
        return false;  // Negative numbers and zero are not powers of two
    }
    return (n & (n - 1)) == 0;  // Power of two check using bitwise AND
}



int main() {
    // int num; // Variable to store user input
    // // Prompt the user to enter a number
    // printf("Enter a number: ");
    
    // // Read user input and check if it was successful
    // if (scanf("%d", &num) != 1) {
    //     // If input is invalid, print an error message and exit
    //     printf("Invalid input. Please enter an integer.\n");
    //     return 1; // Return a non-zero value to indicate an error
    // }

    // // Check if the number is a power of two
    // if (is_power_of_two(num)) {
    //     // If true, print that it is a power of two
    //     printf("%d is a power of 2.\n", num);
    // } else {
    //     // If false, print that it is not a power of two
    //     printf("%d is not a power of 2.\n", num);
    // }

    // return 0; // Return 0 to indicate successful execution


    char input[100];
    int number;
    char choice;

    while (1) {
        // Prompt user for input
        printf("Enter a number to check if it's a power of two (or 'q' to quit): ");
        fgets(input, 100, stdin);  // Read input as a string

        // Check if the user wants to quit
        if (input[0] == 'q' || input[0] == 'Q') {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        // Convert input to an integer and validate
        number = atoi(input);  // Convert string to integer
        if (number == 0 && input[0] != '0') {
            printf("Invalid input: Please enter a valid integer.\n");
            continue;
        }
          // Check if the number is a power of two
        if (is_power_of_two(number)) {
            printf("%d is a power of two.\n", number);
        } else {
            printf("%d is not a power of two.\n", number);
        }

        // Ask if the user wants to check another number
        printf("Do you want to check another number? (y/n): ");
        scanf(" %c", &choice);  // Read the choice (single character)
        getchar();  // Clear the buffer (fflush(stdin) could be used but may be non-standard)

        if (choice != 'y' && choice != 'Y') {
            printf("Thank you for using the program. Goodbye!\n");
            break;
        }
    }

    return 0;
}