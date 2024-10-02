#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define NO_OF_CHARS 256

void badCharHeuristic(char *str, int size, int badchar[NO_OF_CHARS]) {
    int i;
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;
    for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}

void boyerMoore(char *txt, char *pat) {
    int m = strlen(pat);
    int n = strlen(txt);

    int badchar[NO_OF_CHARS];
    badCharHeuristic(pat, m, badchar);

    int i = 0;
    while (i <= (n - m)) {
        int j = m - 1;
        while (j >= 0 && pat[j] == txt[i + j])
            j--;

        if (j < 0) {
            printf("Pattern occurs at shift = %d\n", i);
            i += (i + m < n) ? m - badchar[txt[i + m]] : 1;
        } else
            i += (j - badchar[txt[i + j]] > 1) ? j - badchar[txt[i + j]] : 1;
    }
}

int main() {
    char txt[] = "ABAAABCD";
    char pat[] = "ABC";
    printf("Text: %s\n", txt);
    printf("Pattern: %s\n", pat);
    boyerMoore(txt, pat);
    return 0;
}