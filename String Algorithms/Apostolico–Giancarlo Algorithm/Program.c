#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHAR 256

// Function to compute the bad character heuristic
void computeBadChar(char *pattern, int m, int badchar[MAX_CHAR]) {
    int i;

    for (i = 0; i < MAX_CHAR; i++)
        badchar[i] = -1;

    for (i = 0; i < m; i++)
        badchar[(int) pattern[i]] = i;
}

// Function to compute the good suffix heuristic
void computeGoodSuffix(char *pattern, int m, int goodsuffix[]) {
    int i, j, k;
    int *suff = (int *) malloc(m * sizeof(int));

    suff[m - 1] = m;
    for (i = m - 2; i >= 0; --i) {
        for (j = 0; j <= i && pattern[i - j] == pattern[m - 1 - j]; ++j);
        suff[i] = j;
    }

    for (i = 0; i < m; ++i)
        goodsuffix[i] = m;

    j = 0;
    for (i = m - 1; i >= -1; --i)
        if (i == -1 || suff[i] == i + 1)
            for (; j < m - 1 - i; ++j)
                if (goodsuffix[j] == m)
                    goodsuffix[j] = m - 1 - i;

    for (i = 0; i <= m - 2; ++i)
        goodsuffix[m - 1 - suff[i]] = m - 1 - i;

    free(suff);
}

// Function to compute the match skip array
void computeMatchSkip(char *pattern, int m, int matchskip[]) {
    int i, j;
    for (i = 0; i < m; i++)
        matchskip[i] = 0;

    for (i = 1; i < m; i++) {
        j = matchskip[i - 1];
        while (j > 0 && pattern[i] != pattern[j])
            j = matchskip[j - 1];
        if (pattern[i] == pattern[j])
            j++;
        matchskip[i] = j;
    }
}

// Function to implement the Apostolico-Giancarlo algorithm
void apostolicoGiancarlo(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);

    int badchar[MAX_CHAR];
    int *goodsuffix = (int *) malloc(m * sizeof(int));
    int *matchskip = (int *) malloc(m * sizeof(int));

    computeBadChar(pattern, m, badchar);
    computeGoodSuffix(pattern, m, goodsuffix);
    computeMatchSkip(pattern, m, matchskip);

    int i = 0, j;
    while (i <= n - m) {
        for (j = m - 1; j >= 0 && pattern[j] == text[i + j]; j--) {
            if (j > 0 && matchskip[j - 1] > 0) {
                j -= matchskip[j - 1];
                break;
            }
        }

        if (j < 0) {
            printf("Pattern found at index %d\n", i);
            i += goodsuffix[0];
        } else {
            int bc_shift = j - badchar[(int) text[i + j]];
            int gs_shift = goodsuffix[j];
            i += (bc_shift > gs_shift) ? bc_shift : gs_shift;
        }
    }

    free(goodsuffix);
    free(matchskip);
}

int main() {
    char text[] = "ABAAABCDABABABAABABABCD";
    char pattern[] = "ABABCD";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);
    printf("Matches:\n");

    apostolicoGiancarlo(text, pattern);

    return 0;
}