#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Trie Node Structure
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE]; // Each node has 26 possible children (for each alphabet letter)
    int isEndOfWord;                          // 1 if this node marks the end of a word
};

// Function to create a new Trie node
struct TrieNode *createNode() {
    struct TrieNode *node = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL; // Initialize all children to NULL
    return node;
}

// Insert a word into the Trie
void insert(struct TrieNode *root, const char *word) {
    struct TrieNode *current = root;
    while (*word) {
        int index = *word - 'a'; // Calculate index for each character (0 for 'a', 1 for 'b', etc.)
        if (!current->children[index])
            current->children[index] = createNode(); // Create new node if it doesn't exist
        current = current->children[index];
        word++;
    }
    current->isEndOfWord = 1; // Mark the end of a valid word
}

// Depth-First Search (DFS) to collect words in lexicographical order
void dfs(struct TrieNode *root, char *currentWord, int level, int *k, char *result) {
    if (*k <= 0) return; // If we have found the k-th word, stop searching

    // If this node marks the end of a word, check if it's the k-th word
    if (root->isEndOfWord) {
        (*k)--; // Decrease k when a valid word is found
        if (*k == 0) {
            currentWord[level] = '\0'; // Null-terminate the word
            strcpy(result, currentWord); // Copy the word to result
            return;
        }
    }

    // Recursively search for children in alphabetical order
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            currentWord[level] = 'a' + i; // Add the current letter to the word
            dfs(root->children[i], currentWord, level + 1, k, result); // Go deeper in the Trie
        }
    }
}
// Function to find the k-th lexicographical string
void findKthWord(struct TrieNode *root, int k, char *result) {
    char currentWord[100]; // To store the current word during DFS
    dfs(root, currentWord, 0, &k, result); // Start DFS with level 0
}

int main() {
    struct TrieNode *root = createNode(); // Create the root of the Trie
    char *words[] = {"banana", "apple", "grape", "mango", "orange"};
    int n = 5, k = 3; // Example: 5 words and find the 3rd lexicographical word

    // Insert all words into the Trie
    for (int i = 0; i < n; i++)
        insert(root, words[i]);

    char result[100]; // To store the k-th lexicographical word
    findKthWord(root, k, result); // Find the k-th word

    printf("The %d-th lexicographical word is: %s\n", k, result);
    return 0;
}
// The 3-th lexicographical word is: grape
