#include <stdio.h>
#include <string.h>

// Defined max value for number of strings and their length
#define MAX_STRINGS 100
#define MAX_LENGTH 100

// Function to find the longest common prefix among an array of strings
char* longestCommonPrefix(char arr[][MAX_LENGTH], int n) {
    static char prefix[MAX_LENGTH];
    strcpy(prefix, arr[0]); // Assume the first string as the prefix

    for (int i = 1; i < n; i++) {
        int j = 0;

        // Compare the current prefix with the next string character by character
        while (j < strlen(prefix) && j < strlen(arr[i]) && prefix[j] == arr[i][j]) {
            j++;
        }

        // Update the prefix to the common portion
        prefix[j] = '\0';

        // If the prefix becomes empty, return immediately
        if (prefix[0] == '\0') {
            return prefix;
        }
    }

    return prefix;
}

int main() {
    int n;

    printf("Enter the number of strings: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_STRINGS) {
        printf("Invalid number of strings! Please enter a value between 1 and %d.\n", MAX_STRINGS);
        return 1;
    }

    // 2D array with rows as strings and columns for string lenth for easy comparison
    char arr[MAX_STRINGS][MAX_LENGTH];

    printf("Enter the strings:\n");
    for (int i = 0; i < n; i++) {
        printf("String %d: ", i + 1);
        scanf("%s", arr[i]);
    }

    char* prefix = longestCommonPrefix(arr, n);

    if (strlen(prefix) > 0) {
        printf("The longest common prefix is: %s\n", prefix);
    } else {
        printf("There is no common prefix among the strings.\n");
    }

    return 0;
}
