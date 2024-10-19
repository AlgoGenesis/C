#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LEN 100
#define MAX_WORDS 10000

// Utility function to check if two words differ by exactly one character
bool isAdjacent(char* word1, char* word2) {
    int count = 0;
    int len = strlen(word1);
    for (int i = 0; i < len; i++) {
        if (word1[i] != word2[i])
            count++;
        if (count > 1)
            return false;
    }
    return count == 1;
}

// Function to find the length of the shortest chain
int shortestChainLen(char* start, char* target, char dictionary[MAX_WORDS][MAX_WORD_LEN], int dict_size) {
    // If the target word is not present in the dictionary
    bool target_found = false;
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(target, dictionary[i]) == 0) {
            target_found = true;
            break;
        }
    }
    if (!target_found)
        return 0;

    // Queue to store the words and their levels
    struct QueueNode {
        char word[MAX_WORD_LEN];
        int level;
    };

    struct QueueNode queue[MAX_WORDS];
    int front = 0, rear = 0;

    // Enqueue the start word
    strcpy(queue[rear].word, start);
    queue[rear].level = 1;
    rear++;

    // While the queue is not empty
    while (front < rear) {
        struct QueueNode current = queue[front++];
        char current_word[MAX_WORD_LEN];
        strcpy(current_word, current.word);
        int current_level = current.level;

        // If we have reached the target word
        if (strcmp(current_word, target) == 0)
            return current_level;

        // Check all words in the dictionary
        for (int i = 0; i < dict_size; i++) {
            if (dictionary[i][0] != '\0' && isAdjacent(current_word, dictionary[i])) {
                // If the word is adjacent, enqueue it and mark it as used
                struct QueueNode new_node;
                strcpy(new_node.word, dictionary[i]);
                new_node.level = current_level + 1;
                queue[rear++] = new_node;
                // Mark the word as used by clearing it
                dictionary[i][0] = '\0';
            }
        }
    }

    return 0;
}

// Driver program
int main() {
    char dictionary[MAX_WORDS][MAX_WORD_LEN] = {
        "poon", "plee", "same", "poie", "plie", "poin", "plea"
    };
    int dict_size = 7;
    char start[] = "toon";
    char target[] = "plea";
    printf("Length of shortest chain is: %d\n", shortestChainLen(start, target, dictionary, dict_size));
    return 0;
}
