#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DICT_SIZE 4096 // Maximum size of the dictionary
#define MAX_STRING 256     // Maximum size of a string in the dictionary

typedef struct {
    char *string;
} DictionaryEntry;

// Function to initialize the dictionary with single character strings
void initDictionary(DictionaryEntry *dictionary) {
    for (int i = 0; i < 256; i++) {
        dictionary[i].string = (char *)malloc(2 * sizeof(char));
        dictionary[i].string[0] = (char)i;
        dictionary[i].string[1] = '\0';
    }
}

// Function to search for a string in the dictionary
int searchDictionary(DictionaryEntry *dictionary, int dictSize, char *str) {
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(dictionary[i].string, str) == 0) {
            return i;
        }
    }
    return -1;
}

// LZW compression function
void LZWCompress(char *input) {
    DictionaryEntry dictionary[MAX_DICT_SIZE];
    initDictionary(dictionary);

    int dictSize = 256;
    char currentString[MAX_STRING] = "";
    char newString[MAX_STRING] = "";

    int inputLength = strlen(input);

    printf("Compressed Output: ");
    for (int i = 0; i < inputLength; i++) {
        char currentChar = input[i];
        snprintf(newString, sizeof(newString), "%s%c", currentString, currentChar);

        if (searchDictionary(dictionary, dictSize, newString) != -1) {
            strcpy(currentString, newString);
        } else {
            int index = searchDictionary(dictionary, dictSize, currentString);
            printf("%d ", index);

            if (dictSize < MAX_DICT_SIZE) {
                dictionary[dictSize].string = strdup(newString);
                dictSize++;
            }

            strcpy(currentString, "");
            currentString[0] = currentChar;
            currentString[1] = '\0';
        }
    }

    // Output the code for the last string
    if (strlen(currentString) > 0) {
        int index = searchDictionary(dictionary, dictSize, currentString);
        printf("%d ", index);
    }

    printf("\n");
}

int main() {
    char input[MAX_STRING];
    printf("Enter the string to compress: ");
    scanf("%s", input);

    LZWCompress(input);

    return 0;
}
