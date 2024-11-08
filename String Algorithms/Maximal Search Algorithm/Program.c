#include <stdio.h>
#include <string.h>

// Function to compute the maximal shift array
void computeMaximalShiftArray(char* pattern, int m, int* shift) {
    int i = 1, j = 0;
    shift[0] = 0; // Shift[0] is always 0

    // Preprocess the pattern to create the maximal shift array
    while (i < m) {
        if (pattern[i] == pattern[j]) {
            j++;
            shift[i] = j;
            i++;
        } else {
            if (j != 0) {
                j = shift[j - 1];
            } else {
                shift[i] = 0;
                i++;
            }
        }
    }
}

// Function to implement the Maximal Shift Algorithm
void maximalShiftSearch(char* text, char* pattern) {
    int n = strlen(text);    // Length of text
    int m = strlen(pattern); // Length of pattern

    // Create the maximal shift array for the pattern
    int shift[m];
    computeMaximalShiftArray(pattern, m, shift);

    int i = 0; // Index for text
    int j = 0; // Index for pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            j = shift[j - 1]; // Get the next shift position
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = shift[j - 1]; // Move j back to a possible match position
            } else {
                i++; // Move to the next character in text
            }
        }
    }
}

int main() {
    char text[] = "maximalshiftalgorithmstringmatching";
    char pattern[] = "algorithm";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    maximalShiftSearch(text, pattern);

    return 0;
}