#include <stdio.h>
#include <string.h>

void searchPattern(char *pattern, char *text) {
    int patternLength = strlen(pattern);
    int textLength = strlen(text);
    int i, j;
    
    // Loop through the text
    for (i = 0; i <= textLength - patternLength; i++) {
        // Check the pattern at each position in the text
        for (j = 0; j < patternLength; j++) {
            if (text[i + j] != pattern[j]) {
                break;  // Mismatch, move to the next position
            }
        }
        // If the loop completed, we found a match
        if (j == patternLength) {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main() {
    char text[] = "deterministicmatchingisfun";
    char pattern[] = "matching";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    searchPattern(pattern, text);

    return 0;
}