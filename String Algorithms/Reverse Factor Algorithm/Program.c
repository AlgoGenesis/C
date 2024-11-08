#include <stdio.h>
#include <string.h>

// Function to reverse a string
void reverseString(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to check if a substring is a factor of the main string
int isFactor(char* sub, char* str) {
    int subLen = strlen(sub);
    int strLen = strlen(str);
    
    for (int i = 0; i <= strLen - subLen; i++) {
        int j;
        for (j = 0; j < subLen; j++) {
            if (str[i + j] != sub[j])
                break;
        }
        if (j == subLen)
            return i;  // Substring found at index i
    }
    
    return -1; // Substring not found
}

// Function to implement the Reverse Factor Algorithm
void reverseFactor(char* pattern, char* text) {
    // Reverse the pattern
    reverseString(pattern);
    
    // Check if the reversed pattern is a factor of the text
    int index = isFactor(pattern, text);
    
    if (index != -1)
        printf("Reversed pattern found at index %d\n", index);
    else
        printf("Reversed pattern not found\n");
}

int main() {
    char text[] = "ABCDABCDABC";
    char pattern[] = "ABC";
    
    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);
    
    reverseFactor(pattern, text);
    
    return 0;
}