#include <stdio.h>

// Function to check if the ith bit of a number is set (i.e., equals 1)
int is_ith_bit_set(unsigned int num, int i) {
    // Create a mask by shifting 1 left by i bits and check if the bitwise AND is non-zero
    return (num & (1 << i)) != 0;
}

int main() {
    unsigned int num; // Number whose bit we want to check
    int i;           // Bit position to check (0-indexed)

    // Prompt the user to enter a non-negative number
    printf("Enter a non-negative number: ");
    if (scanf("%u", &num) != 1) {
        // Validate the input; if invalid, notify the user
        printf("Invalid input. Please enter a valid number.\n");
        return 1; // Exit with an error code
    }
    
    // Prompt the user to enter the bit position to check
    printf("Enter the bit position to check (0-31): ");
    if (scanf("%d", &i) != 1 || i < 0 || i > 31) {
        // Validate the input for the bit position
        printf("Invalid input. Please enter a valid bit position (0-31).\n");
        return 1; // Exit with an error code
    }

    // Call the function to check if the ith bit is set and print the result
    if (is_ith_bit_set(num, i)) {
        printf("The %d-th bit is set.\n", i);
    } else {
        printf("The %d-th bit is not set.\n", i);
    }

    return 0; // Successful completion of the program
}

