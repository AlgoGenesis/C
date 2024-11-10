#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for queue elements
typedef struct QueueNode {
    char* word;
    int steps;
    struct QueueNode* next;
} QueueNode;

// Function to create a new queue node
QueueNode* createNode(char* word, int steps) {
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->word = strdup(word); // Duplicate word
    node->steps = steps;
    node->next = NULL;
    return node;
}

// Function to push to the queue
void enqueue(QueueNode** front, QueueNode** rear, char* word, int steps) {
    QueueNode* node = createNode(word, steps);
    if (*rear) {
        (*rear)->next = node;
    } else {
        *front = node;
    }
    *rear = node;
}

// Function to pop from the queue
QueueNode* dequeue(QueueNode** front, QueueNode** rear) {
    if (!*front) return NULL;
    QueueNode* temp = *front;
    *front = (*front)->next;
    if (!*front) {
        *rear = NULL;
    }
    return temp;
}

// Helper function to check if two words differ by exactly one character
int oneLetterDifference(const char* word1, const char* word2) {
    int diffCount = 0;
    for (int i = 0; word1[i] != '\0'; i++) {
        if (word1[i] != word2[i]) {
            diffCount++;
            if (diffCount > 1) return 0;
        }
    }
    return diffCount == 1;
}

// Function to find the word in the wordList and mark it as visited
int findAndRemoveWord(char** wordList, int wordListSize, const char* word) {
    for (int i = 0; i < wordListSize; i++) {
        if (wordList[i] && strcmp(wordList[i], word) == 0) {
            free(wordList[i]);
            wordList[i] = NULL; // Mark as visited by setting to NULL
            return 1;
        }
    }
    return 0;
}

// Main function for Word Ladder problem
int ladderLength(char* beginWord, char* endWord, char** wordList, int wordListSize) {
    // Check if endWord is in the wordList
    int foundEndWord = 0;
    for (int i = 0; i < wordListSize; i++) {
        if (strcmp(wordList[i], endWord) == 0) {
            foundEndWord = 1;
            break;
        }
    }
    if (!foundEndWord) return 0;

    // Initialize BFS
    QueueNode *front = NULL, *rear = NULL;
    enqueue(&front, &rear, beginWord, 1);

    while (front) {
        QueueNode* currentNode = dequeue(&front, &rear);
        char* currentWord = currentNode->word;
        int currentSteps = currentNode->steps;

        // Check if we reached the endWord
        if (strcmp(currentWord, endWord) == 0) {
            free(currentNode->word);
            free(currentNode);
            return currentSteps;
        }

        // Try all words in the wordList that differ by one letter
        for (int i = 0; i < wordListSize; i++) {
            if (wordList[i] && oneLetterDifference(currentWord, wordList[i])) {
                enqueue(&front, &rear, wordList[i], currentSteps + 1);
                free(wordList[i]);  // Mark the word as visited
                wordList[i] = NULL;
            }
        }

        free(currentNode->word);
        free(currentNode);
    }

    return 0; // If there's no valid transformation sequence
}

int main() {
    char* beginWord = "hit";
    char* endWord = "cog";
    char* wordList[] = {"hot", "dot", "dog", "lot", "log", "cog"};
    int wordListSize = sizeof(wordList) / sizeof(wordList[0]);

    int result = ladderLength(beginWord, endWord, wordList, wordListSize);
    printf("Shortest transformation sequence length: %d\n", result);

    return 0;
}
