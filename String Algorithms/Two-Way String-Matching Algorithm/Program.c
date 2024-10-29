#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PATTERN_LENGTH 1000

// Function to compute the critical factorization point
int computeCriticalPoint(const char* pattern, int length) {
    int i = 1, j = 0;
    int period = 1;
    
    while (i + j < length) {
        if (pattern[i + j] == pattern[j]) {
            j++;
        } else if (pattern[i + j] > pattern[j]) {
            j = 0;
            i += period;
            period = 1;
        } else {
            j = 0;
            i++;
            period = i;
        }
    }
    
    return i;
}

// Function to compute the pattern period
int computePeriod(const char* pattern, int length) {
    int period = 1;
    while (period <= length / 2) {
        int isValid = 1;
        for (int i = period; i < length; i++) {
            if (pattern[i] != pattern[i - period]) {
                isValid = 0;
                break;
            }
        }
        if (isValid) {
            return period;
        }
        period++;
    }
    return length;
}

// Function to perform backward matching
int backwardMatch(const char* text, const char* pattern, int start, int length) {
    int i = length - 1;
    while (i >= 0 && text[start + i] == pattern[i]) {
        i--;
    }
    return i;
}

// Main Two-Way String-Matching algorithm
void twoWayMatching(const char* text, int textLength, const char* pattern, int patternLength) {
    if (patternLength == 0) {
        printf("Pattern is empty\n");
        return;
    }
    
    // Compute critical factorization point
    int criticalPoint = computeCriticalPoint(pattern, patternLength);
    
    // Compute pattern period
    int period = computePeriod(pattern, patternLength);
    
    // Main search loop
    int pos = 0;
    while (pos <= textLength - patternLength) {
        // Forward scan until critical point
        int i = 0;
        while (i < criticalPoint && pattern[i] == text[pos + i]) {
            i++;
        }
        
        if (i == criticalPoint) {
            // Backward scan from the end
            int j = backwardMatch(text, pattern, pos, patternLength);
            
            if (j < 0) {
                // Pattern found
                printf("Pattern found at index %d\n", pos);
                pos += period;
            } else {
                // Mismatch in backward scan
                pos += j + 1;
            }
        } else {
            // Mismatch in forward scan
            pos += i + 1;
        }
    }
}

int main() {
    const char* text = "GCATCGCAGAGAGTATACAGTACG";
    const char* pattern = "GCAGAGAG";

    int textLength = strlen(text);
    int patternLength = strlen(pattern);

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);
    printf("Matches:\n");

    twoWayMatching(text, textLength, pattern, patternLength);

    return 0;
}