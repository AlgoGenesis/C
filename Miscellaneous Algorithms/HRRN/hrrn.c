#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A Huffman Tree node
struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
};

// A Min Heap: Collection of Huffman Tree nodes
struct MinHeap {
    int size;
    int capacity;
    struct Node **array;
};

// Create a new node
struct Node* createNode(char ch, int freq) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->ch = ch;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Create a Min Heap
struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct Node**)malloc(minHeap->capacity * sizeof(struct Node*));
    return minHeap;
}

// Swap two nodes in Min Heap
void swapNodes(struct Node** a, struct Node** b) {
    struct Node* t = *a;
    *a = *b;
    *b = t;
}

// Heapify function
void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapNodes(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Extract minimum value node from heap
struct Node* extractMin(struct MinHeap* minHeap) {
    struct Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}

// Insert a new node to Min Heap
void insertMinHeap(struct MinHeap* minHeap, struct Node* node) {
    minHeap->size++;
    int i = minHeap->size - 1;
    while (i && node->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

// Build the Min Heap from frequency array
void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; i--)
        minHeapify(minHeap, i);
}

// Create a min heap of capacity equal to size and insert all characters of data[]
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = createNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

// Build Huffman Tree
struct Node* buildHuffmanTree(char data[], int freq[], int size) {
    struct Node *left, *right, *top;

    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

    while (minHeap->size != 1) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = createNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

// Print Huffman Codes using the Huffman tree built
void printCodes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (!(root->left) && !(root->right)) {
        printf("%c: ", root->ch);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Function to start Huffman encoding process
void huffmanCodes(char data[], int freq[], int size) {
    struct Node* root = buildHuffmanTree(data, freq, size);
    int arr[100], top = 0;
    printCodes(root, arr, top);
}

int main() {
    int n;
    printf("Enter the number of characters: ");
    scanf("%d", &n);

    char *data = (char*)malloc(n * sizeof(char));
    int *freq = (int*)malloc(n * sizeof(int));

    printf("Enter characters and their frequencies:\n");
    for (int i = 0; i < n; i++) {
        printf("Character %d: ", i + 1);
        scanf(" %c", &data[i]);
        printf("Frequency of %c: ", data[i]);
        scanf("%d", &freq[i]);
    }

    printf("\nCharacter Huffman Codes:\n");
    huffmanCodes(data, freq, n);

    free(data);
    free(freq);

    return 0;
}
