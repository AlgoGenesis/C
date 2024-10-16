/*
Problem statement: You are given a dictionary of words and a query prefix. Your task is to implement an autocomplete system that finds all the words in the dictionary that start with the given prefix.

Approach: A Trie (Prefix Tree) is perfect for solving the autocomplete or prefix matching problem due to its hierarchical structure that groups words by common prefixes.

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

// Trie node structure
typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

// Function to create a new Trie node
TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Function to insert a word into the Trie
void insert(TrieNode* root, const char* word) {
    TrieNode* current = root;
    while (*word) {
        int index = *word - 'a';
        if (!current->children[index]) {
            current->children[index] = createNode();
        }
        current = current->children[index];
        word++;
    }
    current->isEndOfWord = true;
}

// Function to search for a prefix in the Trie
TrieNode* searchPrefix(TrieNode* root, const char* prefix) {
    TrieNode* current = root;
    while (*prefix) {
        int index = *prefix - 'a';
        if (!current->children[index]) {
            return NULL; // Prefix not found
        }
        current = current->children[index];
        prefix++;
    }
    return current; // Return the node where the prefix ends
}

// Recursive function to collect all words from a given Trie node
void collectWords(TrieNode* node, char* prefix, int level) {
    if (node->isEndOfWord) {
        prefix[level] = '\0';
        printf("%s\n", prefix);
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            prefix[level] = 'a' + i;
            collectWords(node->children[i], prefix, level + 1);
        }
    }
}

// Function to find all words that match the given prefix
void findWordsWithPrefix(TrieNode* root, const char* prefix) {
    TrieNode* prefixNode = searchPrefix(root, prefix);
    if (!prefixNode) {
        printf("No words found with the prefix \"%s\"\n", prefix);
        return;
    }

    // Prepare a buffer to store the current prefix and all possible completions
    char buffer[100];
    strcpy(buffer, prefix);
    collectWords(prefixNode, buffer, strlen(prefix));
}

int main() {
    TrieNode* root = createNode();
    
    // Insert dictionary words
    insert(root, "cat");
    insert(root, "car");
    insert(root, "cart");
    insert(root, "dog");
    insert(root, "dot");

    // Find words with prefix "ca"
    printf("Words with prefix \"ca\":\n");
    findWordsWithPrefix(root, "ca");

    // Find words with prefix "do"
    printf("\nWords with prefix \"do\":\n");
    findWordsWithPrefix(root, "do");

    // Find words with a non-existing prefix
    printf("\nWords with prefix \"fi\":\n");
    findWordsWithPrefix(root, "fi");

    return 0;
}
