#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to construct the Z array
void constructZArray(char* str, int* Z) {
    int n = strlen(str);
    int L, R, k;
    
    // [L,R] make a window which matches with prefix of s
    L = R = 0;
    for (int i = 1; i < n; ++i) {
        // If i>R nothing matches so we will calculate.
        // Z[i] using naive way.
        if (i > R) {
            L = R = i;
            
            // R-L = 0 in starting, so it will start
            // checking from 0'th index. For example,
            // for "ababab" and i = 1, the value of R
            // remains 0 and Z[i] becomes 0. For string
            // "aaaaaa" and i = 1, Z[i] and R become 5
            while (R < n && str[R-L] == str[R])
                R++;
            Z[i] = R-L;
            R--;
        }
        else {
            // k = i-L so k corresponds to number which
            // matches in [L,R] interval.
            k = i-L;
            
            // If Z[k] is less than remaining interval
            // then Z[i] will be equal to Z[k].
            // For example, str = "ababab", i = 3, R = 5
            // and L = 2
            if (Z[k] < R-i+1)
                Z[i] = Z[k];
            
            // For example str = "aaaaaa" and i = 2, R is 5,
            // L is 0
            else {
                // else start from R and check manually
                L = i;
                while (R < n && str[R-L] == str[R])
                    R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}

// Function to search for pattern in text using Z algorithm
void search(char* text, char* pattern) {
    // Create concatenated string "pattern$text"
    char concat[strlen(text) + strlen(pattern) + 2];
    strcpy(concat, pattern);
    strcat(concat, "$");
    strcat(concat, text);
    int l = strlen(concat);
    
    // Construct Z array
    int Z[l];
    constructZArray(concat, Z);
    
    // Now looping through Z array for matching condition
    for (int i = 0; i < l; ++i) {
        // if Z[i] (matched region) is equal to pattern
        // length we got the pattern
        if (Z[i] == strlen(pattern))
            printf("Pattern found at index %d\n", i - strlen(pattern) - 1);
    }
}

int main() {
    char text[] = "GEEKS FOR GEEKS";
    char pattern[] = "GEEK";
    
    printf("Text: %s\n", text);
    printf("Pattern: %s\n\n", pattern);
    printf("Matches:\n");
    search(text, pattern);
    
    return 0;
}