#include <stdio.h>
#include <string.h>

// Function to create the prefix table
void computePrefixTable(char *pattern, int *lps) {
    int m = strlen(pattern);
    int j = 0;  // length of the previous longest prefix suffix
    lps[0] = 0; // lps[0] is always 0

    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = lps[j - 1]; // backtrack
        }
        if (pattern[i] == pattern[j]) {
            j++; // found a match
        }
        lps[i] = j; // set lps value
    }
}

// Function to implement the KMP algorithm
void KMPSearch(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int lps[m]; // Longest Prefix Suffix table

    // Compute the prefix table
    computePrefixTable(pattern, lps);

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1]; // Continue searching
        } else if (i < n && pattern[j] != text[i]) {
            // mismatch after j matches
            if (j != 0) {
                j = lps[j - 1]; // Use the prefix table to avoid unnecessary comparisons
            } else {
                i++;
            }
        }
    }
}

int main() {
    char text[] = "ABABDABACDABABCABABCABAB";
    char pattern[] = "ABABCABAB";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);
    
    KMPSearch(text, pattern);

    return 0;
}

