#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n == 0) return "";
    
    n = 2*n + 1;
    int L[n];
    L[0] = 0;
    L[1] = 1;
    int C = 1;
    int R = 2;
    int i = 0;
    int iMirror;
    int maxLPSLength = 0;
    int maxLPSCenterPosition = 0;
    int start = -1;
    int end = -1;
    int diff = -1;
    
    for (i = 2; i < n; i++) {
        iMirror = 2*C-i;
        L[i] = 0;
        diff = R - i;
        if(diff > 0)
            L[i] = (L[iMirror] < diff) ? L[iMirror] : diff;
        
        while (((i + L[i]) < n && (i - L[i]) > 0) && 
               (((i + L[i] + 1) % 2 == 0) || 
                (s[(i + L[i] + 1)/2] == s[(i - L[i] - 1)/2]))) {
            L[i]++;
        }
        
        if(L[i] > maxLPSLength) {
            maxLPSLength = L[i];
            maxLPSCenterPosition = i;
        }
        
        if (i + L[i] > R) {
            C = i;
            R = i + L[i];
        }
    }
    
    start = (maxLPSCenterPosition - maxLPSLength)/2;
    end = start + maxLPSLength - 1;
    
    char* result = (char*)malloc((end-start+2) * sizeof(char));
    strncpy(result, &s[start], end-start+1);
    result[end-start+1] = '\0';
    
    return result;
}

int main() {
    char s[] = "babad";
    printf("Input string: %s\n", s);
    char* result = longestPalindrome(s);
    printf("Longest palindromic substring: %s\n", result);
    free(result);
    return 0;
}