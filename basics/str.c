#include <stdio.h>
#include <string.h>

int main() {
    char str[100]; // Array to hold the input string
    int length = 0; // Variable to store the length of the string

    // Prompt the user to enter a string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // Read a line of text

    // Remove the newline character if present
    str[strcspn(str, "\n")] = '\0';

    // Method 1: Using strlen function from string.h
    length = strlen(str);
    printf("Length of the string using strlen: %d\n", length);

    // Method 2: Manual calculation of string length
    length = 0; // Reset length for manual calculation
    while (str[length] != '\0') {
        length++; // Increment length until the null terminator is found
    }
    printf("Length of the string using manual method: %d\n", length);

    return 0;
}