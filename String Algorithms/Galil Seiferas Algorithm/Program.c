#include <stdio.h>
#include <string.h>

// Function to compute the longest prefix-suffix (LPS) array
void computeLPSArray(char* pattern, int m, int* lps) {
    int length = 0;
    lps[0] = 0; // lps[0] is always 0

    // Loop to fill the lps array
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1]; // Move back in the LPS array
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Function to implement the Galil-Seiferas string matching algorithm
void galilSeiferasSearch(char* text, char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);

    // Create the LPS array for the pattern
    int lps[m];
    computeLPSArray(pattern, m, lps);

    int i = 0; // Index for text
    int j = 0; // Index for pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1]; // Get the next match from the LPS array
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1]; // Move j back in the LPS array
            } else {
                i++; // Move to the next character in the text
            }
        }
    }
}

int main() {
    char text[] = "galilseiferasalgorithmstringmatching";
    char pattern[] = "matching";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    galilSeiferasSearch(text, pattern);

    return 0;
}