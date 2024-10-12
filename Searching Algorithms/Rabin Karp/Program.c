#include <stdio.h>
#include <string.h>

#define d 256 // Number of characters in the input alphabet (ASCII)
#define q 101 // A prime number for hashing

// Function to search pattern in a text using Rabin-Karp algorithm
void rabinKarpSearch(char pattern[], char text[], int patLen, int textLen) {
    int i, j;
    int pHash = 0; // Hash value for pattern
    int tHash = 0; // Hash value for text window
    int h = 1; // Value of h will be "pow(d, patLen-1) % q"

    // Precompute h = (d^(patLen-1)) % q
    for (i = 0; i < patLen - 1; i++) {
        h = (h * d) % q;
    }

    // Calculate the initial hash value for the pattern and first window of text
    for (i = 0; i < patLen; i++) {
        pHash = (d * pHash + pattern[i]) % q;
        tHash = (d * tHash + text[i]) % q;
    }

    // Slide the pattern over the text one by one
    for (i = 0; i <= textLen - patLen; i++) {
        // Check if the hash values of current window of text matches with pattern's hash
        if (pHash == tHash) {
            // Check characters one by one
            for (j = 0; j < patLen; j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }

            // If pattern matches
            if (j == patLen) {
                printf("Pattern found at index %d\n", i);
            }
        }

        // Calculate the hash value for the next window of text (remove the leading character and add the trailing character)
        if (i < textLen - patLen) {
            tHash = (d * (tHash - text[i] * h) + text[i + patLen]) % q;

            // If tHash becomes negative, make it positive
            if (tHash < 0) {
                tHash = (tHash + q);
            }
        }
    }
}

int main() {
    char text[100], pattern[100];
    printf("Enter the text: ");
    gets(text);
    printf("Enter the pattern to search: ");
    gets(pattern);

    int textLen = strlen(text);
    int patLen = strlen(pattern);

    rabinKarpSearch(pattern, text, patLen, textLen);

    return 0;
}
