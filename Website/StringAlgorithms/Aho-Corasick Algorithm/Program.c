#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256
#define MAX_PATTERNS 100
#define MAX_PATTERN_LENGTH 100

// Trie node structure
typedef struct TrieNode {
    struct TrieNode *children[MAX_CHAR];
    struct TrieNode *failure;
    int *output;
    int output_size;
    int is_end;
} TrieNode;

// Queue structure for BFS
typedef struct Queue {
    TrieNode **array;
    int front, rear, size;
    unsigned capacity;
} Queue;

// Function to create a new trie node
TrieNode *createNode() {
    TrieNode *node = (TrieNode*)malloc(sizeof(TrieNode));
    for (int i = 0; i < MAX_CHAR; i++)
        node->children[i] = NULL;
    node->failure = NULL;
    node->output = NULL;
    node->output_size = 0;
    node->is_end = 0;
    return node;
}

// Function to insert a pattern into the trie
void insert(TrieNode *root, char *pattern, int pattern_index) {
    TrieNode *node = root;
    while (*pattern) {
        if (node->children[*pattern] == NULL)
            node->children[*pattern] = createNode();
        node = node->children[*pattern];
        pattern++;
    }
    node->is_end = 1;
    node->output = realloc(node->output, (node->output_size + 1) * sizeof(int));
    node->output[node->output_size++] = pattern_index;
}

// Function to create a queue
Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (TrieNode**)malloc(queue->capacity * sizeof(TrieNode*));
    return queue;
}

// Queue operations
int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, TrieNode* item) {
    if (isFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

TrieNode* dequeue(Queue* queue) {
    if (isEmpty(queue)) return NULL;
    TrieNode* item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to build failure and output links
void buildLinks(TrieNode *root) {
    Queue *q = createQueue(1000);
    root->failure = root;
    
    // Enqueue all nodes of depth 1
    for (int i = 0; i < MAX_CHAR; i++) {
        if (root->children[i]) {
            root->children[i]->failure = root;
            enqueue(q, root->children[i]);
        }
    }
    
    while (!isEmpty(q)) {
        TrieNode *current = dequeue(q);
        
        for (int i = 0; i < MAX_CHAR; i++) {
            TrieNode *child = current->children[i];
            if (child) {
                TrieNode *f = current->failure;
                while (f != root && f->children[i] == NULL)
                    f = f->failure;
                
                if (f->children[i])
                    f = f->children[i];
                else
                    f = root;
                
                child->failure = f;
                
                // Merge output
                child->output = realloc(child->output, (child->output_size + f->output_size) * sizeof(int));
                memcpy(child->output + child->output_size, f->output, f->output_size * sizeof(int));
                child->output_size += f->output_size;
                
                enqueue(q, child);
            }
        }
    }
    
    free(q->array);
    free(q);
}

// Function to search for patterns in the text
void search(TrieNode *root, char *text) {
    TrieNode *current = root;
    
    for (int i = 0; text[i]; i++) {
        while (current != root && current->children[text[i]] == NULL)
            current = current->failure;
        
        if (current->children[text[i]])
            current = current->children[text[i]];
        else
            current = root;
        
        if (current->output_size > 0) {
            for (int j = 0; j < current->output_size; j++)
                printf("Pattern %d found at index %d\n", current->output[j], i - strlen(text) + 1);
        }
    }
}

int main() {
    char *patterns[] = {"he", "she", "his", "hers"};
    int num_patterns = sizeof(patterns) / sizeof(patterns[0]);
    char text[] = "ahishers";
    
    TrieNode *root = createNode();
    
    // Insert patterns into the trie
    for (int i = 0; i < num_patterns; i++)
        insert(root, patterns[i], i);
    
    // Build failure and output links
    buildLinks(root);
    
    // Search for patterns in the text
    printf("Text: %s\n", text);
    printf("Patterns: ");
    for (int i = 0; i < num_patterns; i++)
        printf("%s ", patterns[i]);
    printf("\n\nMatches:\n");
    search(root, text);
    
    return 0;
}