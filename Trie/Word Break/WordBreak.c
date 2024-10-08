/*
Problem Statement:
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// TrieNode structure definition
struct TrieNode
{
    bool isWord;
    struct TrieNode *children[26];
};

// Function to create a new TrieNode
struct TrieNode *createNode()
{
    struct TrieNode *node = malloc(sizeof(struct TrieNode));
    node->isWord = false;
    for (int i = 0; i < 26; ++i)
    {
        node->children[i] = NULL;
    }
    return node;
}

// Function to check if a string can be segmented into words from the dictionary
bool wordBreak(char *s, char *wordDict[], int wordDictSize)
{
    // Create the root of the Trie
    struct TrieNode *root = createNode();

    // Insert each word in wordDict into the Trie
    for (int i = 0; i < wordDictSize; ++i)
    {
        char *word = wordDict[i];
        struct TrieNode *curr = root;
        for (int j = 0; word[j] != '\0'; j++)
        {
            char c = word[j];
            if (curr->children[c - 'a'] == NULL)
            {
                curr->children[c - 'a'] = createNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isWord = true;
    }

    // Length of the string `s`
    int strLength = strlen(s);

    // DP array to store whether we can segment the string up to index i
    bool dp[strLength + 1];
    memset(dp, false, sizeof(dp));
    dp[0] = true; // Base case, an empty string is a valid segment

    // Dynamic programming loop
    for (int i = 0; i < strLength; i++)
    {
        if (dp[i])
        { // Only proceed if dp[i] is true
            struct TrieNode *curr = root;
            for (int j = i; j < strLength; j++)
            {
                char c = s[j];
                if (curr->children[c - 'a'] == NULL)
                {
                    // No matching word found in the Trie
                    break;
                }
                curr = curr->children[c - 'a'];
                if (curr->isWord)
                {
                    dp[j + 1] = true; // If a word is found, mark dp[j+1] as true
                }
            }
        }
    }

    // Return whether the entire string can be segmented
    return dp[strLength];
}

// Main function
int main()
{
    // Input string
    char s[] = "leetcode";

    // Word dictionary
    char *wordDict[] = {"leet", "code"};
    int wordDictSize = sizeof(wordDict) / sizeof(wordDict[0]);

    // Check if the word can be segmented
    if (wordBreak(s, wordDict, wordDictSize))
    {
        printf("The string \"%s\" can be segmented into words from the dictionary.\n", s);
    }
    else
    {
        printf("The string \"%s\" cannot be segmented into words from the dictionary.\n", s);
    }

    return 0;
}
