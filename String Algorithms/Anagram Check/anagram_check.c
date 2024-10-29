#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>  //Imported library for tolower() and toupper() function

#define CHAR_SET 256  // Assuming ASCII characters

bool areAnagrams(char str1[], char str2[]) {
    int count[CHAR_SET] = {0};

    // Check if lengths match
    if (strlen(str1) != strlen(str2)) {
        return false;
    }

    // Count each character in both strings
    for (int i = 0; str1[i] && str2[i]; i++) {
        count[(int)str1[i]]++;
        count[(int)str2[i]]--;
    }

    // Check if all counts are zero
    for (int i = 0; i < CHAR_SET; i++) {
        if (count[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    char str1[100], str2[100];
    char lower_str1[100];      // To store the lowercase of the first string
    char lower_str2[100];      // To store the lowercase of the second string

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';  // Remove newline character from str1

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';  // Remove newline character from str2

    int i;
    // Convert str1 to lowercase and store in lower_str1
    for (i = 0; str1[i]; i++) {
        lower_str1[i] = tolower(str1[i]);
    }
    lower_str1[i] = '\0';  // Null-terminate lower_str1

    // Convert str2 to lowercase and store in lower_str2
    for (i = 0; str2[i]; i++) {
        lower_str2[i] = tolower(str2[i]);
    }
    lower_str2[i] = '\0';  // Null-terminate lower_str2

    // Pass the lowercase versions to areAnagrams
    if (areAnagrams(lower_str1, lower_str2)) {
        printf("The strings are anagrams.\n");
    } else {
        printf("The strings are not anagrams.\n");
    }

    return 0;
}
