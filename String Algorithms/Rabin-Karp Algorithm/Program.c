#include <stdio.h>
#include <string.h>

#define d 256 // Number of characters in the input alphabet
#define q 101 // A prime number for hash calculation

// Function to implement the Rabin-Karp algorithm
void rabinKarp(char* pattern, char* text) {
    int M = strlen(pattern);
    int N = strlen(text);
    int i, j;
    int p = 0; // Hash value for pattern
    int t = 0; // Hash value for text
    int h = 1;

    // Calculate h = d^(M-1) % q
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // Calculate hash value for pattern and first window of text
    for (i = 0; i < M; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++) {
        // Check if hash values of current window and pattern match
        if (p == t) {
            // Check for characters one by one
            for (j = 0; j < M; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == M)
                printf("Pattern found at index %d\n", i);
        }

        // Calculate hash value for next window
        if (i < N - M) {
            t = (d * (t - text[i] * h) + text[i + M]) % q;
            if (t < 0)
                t = t + q;
        }
    }
}

int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";
    
    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);
    
    rabinKarp(pattern, text);
    
    return 0;
}