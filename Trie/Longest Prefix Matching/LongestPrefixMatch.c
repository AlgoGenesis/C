/*
Problem Statement: You are tasked with designing a system that efficiently finds the longest matching prefix of a given query string from a set of predefined words. Your solution should be able to handle multiple query strings efficiently.

Steps:
1 - Build a Trie where each node represents a character.
2 - When searching for the longest prefix, traverse the Trie from the root, and at each step, check if the current character of the query string exists in the Trie.
3 - Keep track of the last node where a valid prefix ends.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



// Define the Trie Node structure
#define ALPHABET_SIZE 26

// A Trie Node
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;  // True if the node represents the end of a word
};

// Create a new Trie node
struct TrieNode* createNode() {
    struct TrieNode *node = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

// Insert a word into the Trie
void insert(struct TrieNode *root, const char *word) {
    struct TrieNode *node = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';  // Assuming only lowercase letters
        if (!node->children[index]) {
            node->children[index] = createNode();
        }
        node = node->children[index];
    }
    node->isEndOfWord = true;
}

// Function to perform longest prefix matching
char* longestPrefixMatch(struct TrieNode *root, const char *query) {
    struct TrieNode *node = root;
    char *longestPrefix = (char *)malloc(strlen(query) + 1); // Allocate space for prefix
    strcpy(longestPrefix, "");  // Start with an empty prefix
    char currentPrefix[100] = "";  // Buffer for building current prefix

    for (int i = 0; i < strlen(query); i++) {
        int index = query[i] - 'a';
        if (node->children[index]) {
            node = node->children[index];
            strncat(currentPrefix, &query[i], 1);  // Append character to current prefix
            if (node->isEndOfWord) {
                strcpy(longestPrefix, currentPrefix);  // Update longest prefix
            }
        } else {
            break;
        }
    }

    return longestPrefix;
}

// Free the allocated Trie nodes
void freeTrie(struct TrieNode *root) {
    if (root == NULL) return;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        freeTrie(root->children[i]);
    }
    free(root);
}

// Main function to demonstrate the Trie and Longest Prefix Matching
int main() {
    struct TrieNode *root = createNode();
    
    // Insert words into the Trie
    insert(root, "apple");
    insert(root, "app");
    insert(root, "banana");
    insert(root, "bat");
    insert(root, "batch");
    
    // Queries to test Longest Prefix Matching
    const char *queries[] = {"application", "applet", "batman", "batching", "bats", "ban"};
    
    for (int i = 0; i < 6; i++) {
        char *result = longestPrefixMatch(root, queries[i]);
        printf("Query: %s, Longest Prefix: %s\n", queries[i], result);
        free(result);  // Free the result after use
    }

    // Free the Trie memory
    freeTrie(root);
    
    return 0;
}
