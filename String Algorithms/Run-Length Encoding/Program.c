#include <stdio.h>
#include <string.h>

// Function to perform Run-Length Encoding
void runLengthEncoding(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        // Count the occurrences of the current character
        int count = 1;
        while (i < n - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
        // Print the character and its count
        printf("%c%d", str[i], count);
    }
}

int main() {
    char str[] = "AAABBBCCDAA";
    printf("Original string: %s\n", str);
    printf("Encoded string: ");
    runLengthEncoding(str);
    printf("\n");
    return 0;
}
