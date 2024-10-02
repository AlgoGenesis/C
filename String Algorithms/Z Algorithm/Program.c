#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void calculateZArray(char* str, int* Z) {
    int n = strlen(str);
    int L, R, k;
    L = R = 0;
    for (int i = 1; i < n; ++i) {
        if (i > R) {
            L = R = i;
            while (R < n && str[R-L] == str[R])
                R++;
            Z[i] = R-L;
            R--;
        } else {
            k = i-L;
            if (Z[k] < R-i+1)
                Z[i] = Z[k];
            else {
                L = i;
                while (R < n && str[R-L] == str[R])
                    R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}

void zAlgorithm(char* text, char* pattern) {
    char* concat = malloc(strlen(text) + strlen(pattern) + 2);
    strcpy(concat, pattern);
    strcat(concat, "$");
    strcat(concat, text);
    int len = strlen(concat);
    int* Z = calloc(len, sizeof(int));

    calculateZArray(concat, Z);

    for (int i = 0; i < len; ++i) {
        if (Z[i] == strlen(pattern))
            printf("Pattern found at index %d\n", i - strlen(pattern) - 1);
    }

    free(concat);
    free(Z);
}

int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";
    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);
    zAlgorithm(text, pattern);
    return 0;
}