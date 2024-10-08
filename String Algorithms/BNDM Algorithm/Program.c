#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define CHAR_SIZE 256
#define WORD_SIZE 32

// Function to preprocess the pattern and create bit masks
void preprocess(const char* pattern, int patternLength, uint32_t* bitMask) {
    for (int i = 0; i < CHAR_SIZE; i++) {
        bitMask[i] = 0;
    }
    
    uint32_t j = 1;
    for (int i = patternLength - 1; i >= 0; i--) {
        bitMask[(unsigned char)pattern[i]] |= j;
        j <<= 1;
    }
}

// Function to implement the BNDM algorithm
void bndm(const char* text, int textLength, const char* pattern, int patternLength) {
    if (patternLength > WORD_SIZE) {
        printf("Pattern is too long for this implementation. Max length is %d.\n", WORD_SIZE);
        return;
    }

    uint32_t bitMask[CHAR_SIZE];
    preprocess(pattern, patternLength, bitMask);

    int i = patternLength - 1;
    while (i < textLength) {
        int j = patternLength - 1;
        uint32_t d = ~0;
        int last = i;

        while (d != 0 && j >= 0) {
            d &= bitMask[(unsigned char)text[i]];
            i--;
            j--;
            if (d != 0) {
                if (j < 0) {
                    printf("Pattern found at index %d\n", i + 1);
                    i = last + 1;
                    break;
                }
                last = i;
            }
            d <<= 1;
        }

        if (d == 0) {
            i = last + patternLength;
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

    bndm(text, textLength, pattern, patternLength);

    return 0;
}