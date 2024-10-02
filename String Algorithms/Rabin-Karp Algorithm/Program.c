#include <stdio.h>
#include <string.h>

#define d 256 // Number of characters in the input alphabet

void rabinKarp(char pattern[], char text[], int q) {
    int M = strlen(pattern);
    int N = strlen(text);
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for text
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < M; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++) {
        // Check the hash values of current window of text and pattern
        if (p == t) {
            // Check for characters one by one
            for (j = 0; j < M; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == M)
                printf("Pattern found at index %d\n", i);
        }

        // Calculate hash value for next window of text
        if (i < N - M) {
            t = (d * (t - text[i] * h) + text[i + M]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}

int main() {
    char text[] = "GEEKS FOR GEEKS";
    char pattern[] = "GEEK";
    int q = 101; // A prime number

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);
    rabinKarp(pattern, text, q);
    return 0;
}