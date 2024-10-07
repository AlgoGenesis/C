#include <stdio.h>
#include <string.h>

// Function to generate combinations
void generateCombinations(char* str, char* result, int start, int index, int length) {
    // Print the current combination
    if (index > 0) {
        result[index] = '\0'; // Null-terminate the current combination
        printf("%s\n", result);
    }

    // Generate combinations
    for (int i = start; i < length; i++) {
        result[index] = str[i]; // Add current character to the combination
        generateCombinations(str, result, i + 1, index + 1, length); // Recur for the next characters
    }
}

int main() {
    char str[100]; // Input string
    char result[100]; // Array to store combinations

    // Prompt the user to enter a string
    printf("Enter a string: ");
    scanf("%s", str);

    int length = strlen(str);
    printf("Combinations of the string:\n");
    generateCombinations(str, result, 0, 0, length); // Generate combinations

    return 0;
}
