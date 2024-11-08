#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of unique characters
#define MAX_CHARS 256

// A Huffman tree node
typedef struct HuffmanNode {
    char data;
    unsigned freq;
    struct HuffmanNode *left, *right;
} HuffmanNode;

// A Min Heap (Priority Queue) structure
typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    HuffmanNode** array;
} MinHeap;

// Function to create a new Huffman tree node
HuffmanNode* createNode(char data, unsigned freq) {
    HuffmanNode* node = (HuffmanNode*) malloc(sizeof(HuffmanNode));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Function to create a min heap of given capacity
MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = (MinHeap*) malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (HuffmanNode**) malloc(minHeap->capacity * sizeof(HuffmanNode*));
    return minHeap;
}

// Swap two min heap nodes
void swapNodes(HuffmanNode** a, HuffmanNode** b) {
    HuffmanNode* t = *a;
    *a = *b;
    *b = t;
}

// Heapify at given index
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < (int)minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < (int)minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapNodes(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Check if size is 1
int isSizeOne(MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// Extract the minimum value node from heap
HuffmanNode* extractMin(MinHeap* minHeap) {
    HuffmanNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}

// Insert a new node into the min heap
void insertMinHeap(MinHeap* minHeap, HuffmanNode* node) {
    minHeap->size++;
    int i = minHeap->size - 1;

    while (i && node->freq < minHeap->array[(i - 1)/2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1)/2];
        i = (i - 1)/2;
    }
    minHeap->array[i] = node;
}

// Build the min heap
void buildMinHeap(MinHeap* minHeap) {
    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1)/2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// Check if node is leaf
int isLeaf(HuffmanNode* node) {
    return !(node->left) && !(node->right);
}

// Create and build min heap from frequency array
MinHeap* createAndBuildMinHeap(unsigned freq[], char data[], int size) {
    MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = createNode(data[i], freq[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

// Build the Huffman tree and return its root
HuffmanNode* buildHuffmanTree(char data[], unsigned freq[], int size) {
    HuffmanNode *left, *right, *top;
    MinHeap* minHeap = createAndBuildMinHeap(freq, data, size);

    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = createNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

// Print Huffman codes by traversing the Huffman tree
void printCodes(HuffmanNode* root, int arr[], int top, char codes[][MAX_CHARS]) {
    // Assign 0 to left edge and recurse
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1, codes);
    }

    // Assign 1 to right edge and recurse
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1, codes);
    }

    // If this is a leaf node, then it contains one of the input characters
    if (isLeaf(root)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");

        // Convert binary array to string
        for(int i = 0; i < top; ++i)
            codes[root->data][i] = arr[i] + '0';
        codes[root->data][top] = '\0';
    }
}

// Build the Huffman codes
void buildCodes(HuffmanNode* root, char codes[][MAX_CHARS]) {
    int arr[MAX_CHARS], top = 0;
    printCodes(root, arr, top, codes);
}

// Encode the input string using the generated Huffman codes
void encode(char* input, char codes[][MAX_CHARS]) {
    printf("Encoded string: ");
    for (int i = 0; input[i] != '\0'; ++i)
        printf("%s", codes[(unsigned char)input[i]]);
    printf("\n");
}

int main() {
    char input[1000];
    printf("Enter the string to encode: ");
    fgets(input, sizeof(input), stdin);
    // Remove newline character if present
    size_t len = strlen(input);
    if (input[len - 1] == '\n')
        input[len - 1] = '\0';

    // Calculate frequency of each character
    unsigned freq[MAX_CHARS] = {0};
    for(int i = 0; input[i] != '\0'; ++i)
        freq[(unsigned char)input[i]]++;

    // Count number of unique characters
    char data[MAX_CHARS];
    int size = 0;
    for(int i = 0; i < MAX_CHARS; ++i)
        if(freq[i]) {
            data[size] = (char)i;
            size++;
        }

    // Build Huffman Tree
    HuffmanNode* root = buildHuffmanTree(data, freq, size);

    // Generate Huffman Codes
    char codes[MAX_CHARS][MAX_CHARS] = {0};
    buildCodes(root, codes);

    // Encode the input string
    encode(input, codes);

    return 0;
}
