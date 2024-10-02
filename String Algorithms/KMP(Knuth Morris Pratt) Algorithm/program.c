#include <stdio.h>
#include <string.h>

// Function to create the prefix table
void computePrefixTable(char *pattern, int *lps) {
    int m = strlen(pattern);
    int j = 0;  // length of the previous longest prefix suffix
    lps[0] = 0; // lps[0] is always 0

    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = lps[j - 1]; 
        }
        if (pattern[i] == pattern[j]) {
            j++; 
        }
        lps[i] = j; 
    }
}

// Function to implement the KMP algorithm
void KMPSearch(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int lps[m]; 

    computePrefixTable(pattern, lps);

    int i = 0; //text
    int j = 0; // pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1]; 
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1]; 
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

