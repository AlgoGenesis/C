#include <stdio.h>
#include <string.h>

#define d 256 // Number of characters in the input alphabet

// Rabin-Karp algorithm for pattern searching
void rabinKarp(char *txt, char *pat, int q) {
    int m = strlen(pat);
    int n = strlen(txt);
    int i, j;
    int p = 0; // Hash value for the pattern
    int t = 0; // Hash value for the text
    int h = 1;

    // Value of h would be "pow(d, m-1)%q"
    for (i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < m; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // Slide the pattern over the text
    for (i = 0; i <= n - m; i++) {
        // Check if the current window of text and pattern hash values match
        if (p == t) {
            // If hash values match, check the characters one by one
            for (j = 0; j < m; j++) {
                if (txt[i + j] != pat[j]) {
                    break;
                }
            }

            // If the characters match, it's a valid occurrence
            if (j == m) {
                printf("Pattern found at index %d\n", i);
            }
        }

        // Calculate the hash value for the next window
        if (i < n - m) {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;

            // We might get a negative value of t, convert it to positive
            if (t < 0) {
                t = (t + q);
            }
        }
    }
}

int main() {
    char txt[] = "ABCCDABCD";
    char pat[] = "ABCD";
    int q = 101; // A prime number to reduce collisions

    rabinKarp(txt, pat, q);
    return 0;
}
