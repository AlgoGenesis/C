#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is a Duck Number
bool is_duck_number(char number[]) {
    // Check if the first digit is '0'
    if (number[0] == '0') {
        return false;  // Duck Number cannot start with '0'
    }

    // Check for the presence of '0' from the second character onward
    for (int i = 1; number[i] != '\0'; i++) {
        if (number[i] == '0') {
            return true;  // Duck Number found
        }
    }

    // Return false if no '0' was found after the first character
    return false;
}

int main() {
    char number[20];  // Array to store the number as a string

    // Input number from the user
    printf("Enter a number: ");
    scanf("%s", number);

    // Check if the number is a Duck Number
    if (is_duck_number(number)) {
        printf("%s is a Duck Number.\n", number);
    } else {
        printf("%s is not a Duck Number.\n", number);
    }

    return 0;
}
