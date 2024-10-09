/*
Problem Statement:
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() : Initializes the trie object.
void insert(String word) : Inserts the string word into the trie.
boolean search(String word) : Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) : Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for TrieNode
typedef struct TrieNode
{
    char data;
    struct TrieNode *children[26];
    bool isTerminal;
} TrieNode;

// Function to create a new TrieNode
TrieNode *createNode(char ch)
{
    TrieNode *newNode = (TrieNode *)malloc(sizeof(TrieNode));
    newNode->data = ch;
    for (int i = 0; i < 26; i++)
    {
        newNode->children[i] = NULL;
    }
    newNode->isTerminal = false;
    return newNode;
}

// Define a structure for Trie
typedef struct Trie
{
    TrieNode *root;
} Trie;

// Function to initialize a Trie
Trie *createTrie()
{
    Trie *trie = (Trie *)malloc(sizeof(Trie));
    trie->root = createNode('\0'); // Root is initialized with a null character
    return trie;
}

// Function to insert a word into the Trie
void insert(Trie *trie, char *word)
{
    TrieNode *current = trie->root;
    for (int i = 0; word[i] != '\0'; i++)
    {
        int index = word[i] - 'a'; // Find the index for the character
        if (current->children[index] == NULL)
        {
            current->children[index] = createNode(word[i]);
        }
        current = current->children[index];
    }
    current->isTerminal = true; // Mark the end of the word
}

// Function to search for a word in the Trie
bool search(Trie *trie, char *word)
{
    TrieNode *current = trie->root;
    for (int i = 0; word[i] != '\0'; i++)
    {
        int index = word[i] - 'a';
        if (current->children[index] == NULL)
        {
            return false; // Word not found
        }
        current = current->children[index];
    }
    return current->isTerminal; // Return true if it's a terminal node
}

// Function to check if any word in the Trie starts with a given prefix
bool startsWith(Trie *trie, char *prefix)
{
    TrieNode *current = trie->root;
    for (int i = 0; prefix[i] != '\0'; i++)
    {
        int index = prefix[i] - 'a';
        if (current->children[index] == NULL)
        {
            return false; // Prefix not found
        }
        current = current->children[index];
    }
    return true;
}

// Example usage
int main()
{
    Trie *trie = createTrie();

    // Insert words into the Trie
    insert(trie, "apple");
    insert(trie, "app");

    // Search for words
    printf("Search 'apple': %s\n", search(trie, "apple") ? "true" : "false");
    printf("Search 'app': %s\n", search(trie, "app") ? "true" : "false");
    printf("Search 'apricot': %s\n", search(trie, "apricot") ? "true" : "false");

    // Check prefixes
    printf("Starts with 'app': %s\n", startsWith(trie, "app") ? "true" : "false");
    printf("Starts with 'apr': %s\n", startsWith(trie, "apr") ? "true" : "false");

    return 0;
}
