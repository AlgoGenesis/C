#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHAR 256
#define MAX_PATTERNS 100
#define MAX_PATTERN_LENGTH 100

// Trie node structure
typedef struct TrieNode {
    struct TrieNode *children[MAX_CHAR];
    int is_end;
    int pattern_index;
} TrieNode;

// Function to create a new Trie node
TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    for (int i = 0; i < MAX_CHAR; i++) {
        node->children[i] = NULL;
    }
    node->is_end = 0;
    node->pattern_index = -1;
    return node;
}

// Function to insert a reversed pattern into the Trie
void insert(TrieNode* root, char* pattern, int pattern_index) {
    int length = strlen(pattern);
    TrieNode* node = root;
    
    for (int i = length - 1; i >= 0; i--) {
        int index = (unsigned char)pattern[i];
        if (!node->children[index]) {
            node->children[index] = createNode();
        }
        node = node->children[index];
    }
    
    node->is_end = 1;
    node->pattern_index = pattern_index;
}

// Function to compute the shift values (simplified bad character rule)
void computeShift(char** patterns, int num_patterns, int shift[MAX_CHAR]) {
    int max_length = 0;
    
    for (int i = 0; i < num_patterns; i++) {
        int length = strlen(patterns[i]);
        if (length > max_length) {
            max_length = length;
        }
    }
    
    for (int i = 0; i < MAX_CHAR; i++) {
        shift[i] = max_length;
    }
    
    for (int i = 0; i < num_patterns; i++) {
        int length = strlen(patterns[i]);
        for (int j = 0; j < length - 1; j++) {
            int c = (unsigned char)patterns[i][j];
            shift[c] = (length - 1 - j < shift[c]) ? length - 1 - j : shift[c];
        }
    }
}

// Function to search for patterns using Commentz-Walter algorithm
void commentzWalter(char* text, char** patterns, int num_patterns) {
    TrieNode* root = createNode();
    int shift[MAX_CHAR];
    
    // Build Trie of reversed patterns
    for (int i = 0; i < num_patterns; i++) {
        insert(root, patterns[i], i);
    }
    
    // Compute shift values
    computeShift(patterns, num_patterns, shift);
    
    int text_length = strlen(text);
    int max_pattern_length = 0;
    
    for (int i = 0; i < num_patterns; i++) {
        int length = strlen(patterns[i]);
        if (length > max_pattern_length) {
            max_pattern_length = length;
        }
    }
    
    int i = max_pattern_length - 1;
    while (i < text_length) {
        TrieNode* node = root;
        int j = 0;
        
        while (i - j >= 0 && node->children[(unsigned char)text[i - j]]) {
            node = node->children[(unsigned char)text[i - j]];
            j++;
            
            if (node->is_end) {
                printf("Pattern '%s' found at index %d\n", patterns[node->pattern_index], i - j + 1);
            }
        }
        
        i += (j > 1) ? j : shift[(unsigned char)text[i]];
    }
}

int main() {
    char* text = "GCATCGCAGAGAGTATACAGTACG";
    char* patterns[] = {"GCAGAGAG", "TATAC", "CAT"};
    int num_patterns = sizeof(patterns) / sizeof(patterns[0]);

    printf("Text: %s\n", text);
    printf("Patterns: ");
    for (int i = 0; i < num_patterns; i++) {
        printf("%s ", patterns[i]);
    }
    printf("\n\nMatches:\n");

    commentzWalter(text, patterns, num_patterns);

    return 0;
}