//Program to reverse a string without using library function

#include <stdio.h>

int main() {
    char str[100];
    char rev[100];
    int i, length = 0;

    // Input string from user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    //Display the entered string
    printf("You entered: %s", str);

    // Calculate length of string
    for (i = 0; str[i] != '\0'; i++) {
        length++;
    }

    // Adjust length if newline character is present
    if (length > 0 && str[length - 1] == '\n') {
        length--;
    }

    // Reverse the string
    for (i = 0; i < length; i++) {
        rev[i] = str[length - 1 - i];
    }   

    //Display the reversed string
    rev[length] = '\0'; // Null-terminate the reversed string
    printf("Reversed string is: %s\n", rev);
    return 0;
}
