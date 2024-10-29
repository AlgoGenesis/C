#include <stdio.h>
#include <string.h>

#define MAX_PATTERN_LENGTH 100

// Function to compute the prefix function for the pattern
void computePrefixFunction(char* pattern, int m, int* pi) {
    int i = 1, j = 0;
    pi[0] = 0;

    while (i < m) {
        if (pattern[i] == pattern[j]) {
            pi[i] = j + 1;
            i++;
            j++;
        }
        else if (j > 0) {
            j = pi[j - 1];
        }
        else {
            pi[i] = 0;
            i++;
        }
    }
}

// Function to perform string matching using Colussi algorithm
void colussi(char* text, char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int pi[MAX_PATTERN_LENGTH];

    // Compute the prefix function for the pattern
    computePrefixFunction(pattern, m, pi);

    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
            if (j == m) {
                printf("Pattern found at index %d\n", i - j);
                j = pi[j - 1];
            }
        }
        else {
            if (j > 0) {
                j = pi[j - 1];
            }
            else {
                i++;
            }
        }
    }
}

int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n\n", pattern);

    printf("Matches:\n");
    colussi(text, pattern);

    return 0;
}