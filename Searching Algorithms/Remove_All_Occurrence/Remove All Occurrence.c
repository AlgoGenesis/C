#include <stdio.h>
#include <string.h>

void removeAllOccurrences(char *str, char charToRemove) {
    int i, j = 0;
    int length = strlen(str);
    char result[length + 1]; // +1 for the null terminator

    for (i = 0; i < length; i++) {
        if (str[i] != charToRemove) {
            result[j++] = str[i]; // Copy the character if it is not the target
        }
    }
    result[j] = '\0'; // Null terminate the new string

    // Copy the result back to the original string
    strcpy(str, result);
}

int main() {
    char str[100];
    char charToRemove;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove the trailing newline character

    printf("Enter the character to remove: ");
    scanf(" %c", &charToRemove);

    removeAllOccurrences(str, charToRemove);
    printf("Resulting string: %s\n", str);

    return 0;
}