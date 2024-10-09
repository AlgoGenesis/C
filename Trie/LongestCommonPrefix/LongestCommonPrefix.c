/*
Problem Statement:
    Write a function to find the longest common prefix string amongst an array of strings.
    If there is no common prefix, return an empty string "". */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the structure for TrieNode
typedef struct TrieNode
{
    char ch;
    struct TrieNode *children[26];
    bool isTerminal;
    int childCount;
} TrieNode;

// Function to create a new TrieNode
TrieNode *createNode(char ch)
{
    TrieNode *newNode = (TrieNode *)malloc(sizeof(TrieNode));
    newNode->ch = ch;
    newNode->isTerminal = false;
    newNode->childCount = 0;
    for (int i = 0; i < 26; i++)
    {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Recursive function to insert a word into the Trie
void insert(TrieNode *root, char *word)
{
    if (strlen(word) == 0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child = NULL;

    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        child = createNode(ch);
        root->childCount++;
        root->children[index] = child;
    }

    // Recursive call to insert the rest of the word
    insert(child, word + 1);
}

// Function to find the longest common prefix among the words in the vector
char *longestCommonPrefix(char **strs, int strsSize)
{
    TrieNode *root = createNode('\0');

    // Insert all words into the Trie
    for (int i = 0; i < strsSize; i++)
    {
        insert(root, strs[i]);
    }

    if (root->isTerminal)
    {
        return "";
    }

    // Get the first word to begin checking the prefix
    char *firstWord = strs[0];
    char *result = (char *)malloc(sizeof(char) * (strlen(firstWord) + 1));
    int resultIndex = 0;

    // Traverse the Trie and build the common prefix
    for (int i = 0; firstWord[i] != '\0'; i++)
    {
        char ch = firstWord[i];
        int index = ch - 'a';

        if (root->childCount == 1 && root->children[index] != NULL)
        {
            result[resultIndex++] = ch;
            root = root->children[index];

            if (root->isTerminal)
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
    result[resultIndex] = '\0';
    return result;
}

// Example usage
int main()
{
    char *strs[] = {"flower", "flow", "flight"};
    int strsSize = sizeof(strs) / sizeof(strs[0]);

    char *prefix = longestCommonPrefix(strs, strsSize);
    printf("Longest Common Prefix: %s\n", prefix);

    return 0;
}
