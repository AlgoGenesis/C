#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to preprocess the string by inserting delimiters
void preprocess(const char *s, char *t) {
    int n = strlen(s);
    t[0] = '#';
    for (int i = 0; i < n; i++) {
        t[2 * i + 1] = s[i];
        t[2 * i + 2] = '#';
    }
    t[2 * n + 1] = '\0';
}

// Function to find the longest palindromic substring using Manacher's Algorithm
void manacher(const char *s) {
    int n = strlen(s);
    if (n == 0) return;

    char *t = (char *)malloc((2 * n + 2) * sizeof(char)); // Transformed string with delimiters
    preprocess(s, t);

    int len = strlen(t);
    int p[len];   // Array to store the lengths of palindromes centered at each position
    int c = 0, r = 0;  // Current center and right boundary of the palindrome
    int maxLen = 0;     // Length of the longest palindrome
    int centerIndex = 0; // Index of the center of the longest palindrome

    for (int i = 0; i < len; i++) {
        int mirror = 2 * c - i;  // Mirror index of i with respect to center c
        if (i < r) {
            p[i] = (r - i < p[mirror]) ? r - i : p[mirror];
        } else {
            p[i] = 0;
        }

        // Try expanding the palindrome centered at i
        while (i + 1 + p[i] < len && i - 1 - p[i] >= 0 && t[i + 1 + p[i]] == t[i - 1 - p[i]]) {
            p[i]++;
        }

        // Update the center and right boundary if expanded beyond the current right boundary
        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }

        // Keep track of the longest palindrome
        if (p[i] > maxLen) {
            maxLen = p[i];
            centerIndex = i;
        }
    }

    // Extract the longest palindromic substring
    int start = (centerIndex - maxLen) / 2;
    printf("Longest Palindromic Substring: ");
    for (int i = start; i < start + maxLen; i++) {
        printf("%c", s[i]);
    }
    printf("\n");

    free(t); // Free allocated memory
}

int main() {
    char s[1000];
    printf("Enter a string: ");
    scanf("%s", s);  // Read user input (string)

    manacher(s);  // Call the Manacher's algorithm function

    return 0;
}
