#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LEN 100

// Memoization table to store results
int memo[MAX_LEN][MAX_LEN][MAX_LEN];

// Helper function to check if two strings have the same characters
bool haveSameCharacters(const char *s1, const char *s2, int len) {
    int count[26] = {0};
    for (int i = 0; i < len; i++) {
        count[s1[i] - 'a']++;
        count[s2[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) return false;
    }
    return true;
}

// Recursive function with memoization to check if s2 is a scrambled version of s1
bool isScramble(const char *s1, const char *s2, int i1, int i2, int len) {
    if (memo[i1][i2][len] != -1) return memo[i1][i2][len];
    
    if (strncmp(s1 + i1, s2 + i2, len) == 0) return memo[i1][i2][len] = 1;

    if (!haveSameCharacters(s1 + i1, s2 + i2, len)) return memo[i1][i2][len] = 0;

    for (int i = 1; i < len; i++) {
        if ((isScramble(s1, s2, i1, i2, i) && isScramble(s1, s2, i1 + i, i2 + i, len - i)) ||
            (isScramble(s1, s2, i1, i2 + len - i, i) && isScramble(s1, s2, i1 + i, i2, len - i))) {
            return memo[i1][i2][len] = 1;
        }
    }

    return memo[i1][i2][len] = 0;
}

bool isScrambleWrapper(const char *s1, const char *s2) {
    int len = strlen(s1);
    if (len != strlen(s2)) return false;

    memset(memo, -1, sizeof(memo));
    return isScramble(s1, s2, 0, 0, len);
}

int main() {
    const char *s1 = "great";
    const char *s2 = "rgeat";

    if (isScrambleWrapper(s1, s2)) {
        printf("'%s' is a scrambled version of '%s'\n", s2, s1);
    } else {
        printf("'%s' is NOT a scrambled version of '%s'\n", s2, s1);
    }

    return 0;
}
