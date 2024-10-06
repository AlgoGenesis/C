#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHAR 256

// Function to compute the bad character heuristic
void computeBadChar(char *pattern, int patLen, int badchar[MAX_CHAR]) {
    int i;

    // Initialize all occurrences as -1
    for (i = 0; i < MAX_CHAR; i++)
        badchar[i] = -1;

    // Fill the actual value of last occurrence of a character
    for (i = 0; i < patLen; i++)
        badchar[(int) pattern[i]] = i;
}

// The Boyer-Moore Algorithm for pattern searching
void boyerMoore(char *text, char *pattern) {
    int textLen = strlen(text);
    int patLen = strlen(pattern);
    int badchar[MAX_CHAR];

    // Preprocess the pattern
    computeBadChar(pattern, patLen, badchar);

    int shift = 0;  // Shift of the pattern with respect to text
    while (shift <= (textLen - patLen)) {
        int j = patLen - 1;

        // Reduce j while characters of pattern and text are matching
        while (j >= 0 && pattern[j] == text[shift + j])
            j--;

        if (j < 0) {
            // Pattern found
            printf("Pattern found at index %d\n", shift);
            // Move the pattern so that the next character in text aligns with the last occurrence of it in pattern
            shift += (shift + patLen < textLen) ? patLen - badchar[text[shift + patLen]] : 1;
        } else {
            // Shift the pattern so that the bad character in text aligns with the last occurrence of it in pattern
            shift += (j - badchar[text[shift + j]] > 1) ? j - badchar[text[shift + j]] : 1;
        }
    }
}

int main() {
    char text[] = "ABAAABCDABC";
    char pattern[] = "ABC";
    
    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);
    
    boyerMoore(text, pattern);
    
    return 0;
}