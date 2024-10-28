#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define CHAR_SIZE 256
#define WORD_SIZE 64

// Function to preprocess the pattern and create bit masks
void preprocess(const char* pattern, int patternLength, uint64_t* bitMask) {
    for (int i = 0; i < CHAR_SIZE; i++) {
        bitMask[i] = ~0ULL;
    }
    
    for (int i = 0; i < patternLength; i++) {
        bitMask[(unsigned char)pattern[i]] &= ~(1ULL << i);
    }
}

// Function to implement the Bitap algorithm
void bitap(const char* text, int textLength, const char* pattern, int patternLength) {
    if (patternLength > WORD_SIZE) {
        printf("Pattern is too long for this implementation. Max length is %d.\n", WORD_SIZE);
        return;
    }

    uint64_t bitMask[CHAR_SIZE];
    preprocess(pattern, patternLength, bitMask);

    uint64_t R = ~0ULL;
    uint64_t patternMask = 1ULL << (patternLength - 1);

    for (int i = 0; i < textLength; i++) {
        R = (R << 1) | bitMask[(unsigned char)text[i]];
        
        if (!(R & patternMask)) {
            printf("Pattern found at index %d\n", i - patternLength + 1);
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

    bitap(text, textLength, pattern, patternLength);

    return 0;
}