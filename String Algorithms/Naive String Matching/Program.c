#include <stdio.h>
#include <string.h>

// Naive string matching algorithm
void naiveStringMatching(char *txt, char *pat) {
    int n = strlen(txt);
    int m = strlen(pat);

    // Loop through each position in the text
    for (int i = 0; i <= n - m; i++) {
        int j;

        // Check if the pattern matches the substring of the text
        for (j = 0; j < m; j++) {
            if (txt[i + j] != pat[j]) {
                break; // Mismatch found
            }
        }

        // If the pattern is found
        if (j == m) {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main() {
    char txt[] = "ABABCABABABCD";
    char pat[] = "ABAB";

    naiveStringMatching(txt, pat);
    return 0;
}
