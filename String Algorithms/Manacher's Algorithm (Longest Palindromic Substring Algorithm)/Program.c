#include <stdio.h>
#include <string.h>

void findLongestPalindrome(char* s) {
    int n = strlen(s);
    char t[2 * n + 3];
    int p[2 * n + 3], c = 0, r = 0, maxLen = 0, center = 0;
    
    t[0] = '^';
    for (int i = 0; i < n; i++) {
        t[2 * i + 1] = '#';
        t[2 * i + 2] = s[i];
    }
    t[2 * n + 1] = '#';
    t[2 * n + 2] = '$';

    for (int i = 1; i < 2 * n + 2; i++) {
        int mirror = 2 * c - i;
        p[i] = (r > i) ? (p[mirror] < r - i ? p[mirror] : r - i) : 0;
        
        while (t[i + 1 + p[i]] == t[i - 1 - p[i]])
            p[i]++;
        
        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }
        
        if (p[i] > maxLen) {
            maxLen = p[i];
            center = i;
        }
    }

    int start = (center - maxLen) / 2;
    printf("Longest Palindromic Substring: ");
    for (int i = start; i < start + maxLen; i++) {
        printf("%c", s[i]);
    }
    printf("\n");
}

int main() {
    char s[] = "babad"; //Example
    findLongestPalindrome(s);
    return 0;
}
