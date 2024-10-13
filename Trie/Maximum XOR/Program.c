#include <stdio.h>
#include <stdlib.h>

#define BITS 31 // We consider 31 bits for non-negative integers

// Trie Node Structure for Binary Trie
struct TrieNode {
    struct TrieNode *children[2]; // Binary Trie has 2 children (for bit 0 and bit 1)
};

// Function to create a new Trie node
struct TrieNode *createBinaryNode() {
    struct TrieNode *node = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    node->children[0] = node->children[1] = NULL; // Initialize both children to NULL
    return node;
}

// Insert a number into the binary Trie
void insertBinaryTrie(struct TrieNode *root, int num) {
    struct TrieNode *current = root;
    for (int i = BITS; i >= 0; i--) {
        int bit = (num >> i) & 1; // Get the i-th bit of the number
        if (!current->children[bit])
            current->children[bit] = createBinaryNode(); // Create a new node for this bit
        current = current->children[bit]; // Move to the child corresponding to this bit
    }
}

// Find the maximum XOR with a given number in the Trie
int findMaxXOR(struct TrieNode *root, int num) {
    struct TrieNode *current = root;
    int maxXOR = 0;
    for (int i = BITS; i >= 0; i--) {
        int bit = (num >> i) & 1; // Get the i-th bit of the number
        int oppositeBit = 1 - bit; // We want to find the opposite bit to maximize XOR
        if (current->children[oppositeBit]) {
            maxXOR = (maxXOR << 1) | 1; // If opposite bit exists, add 1 to maxXOR
            current = current->children[oppositeBit]; // Move to the opposite bit node
        } else {
            maxXOR = (maxXOR << 1); // If opposite bit doesn't exist, add 0 to maxXOR
            current = current->children[bit]; // Move to the same bit node
        }
    }
    return maxXOR;
}

// Function to find the maximum XOR of two numbers in an array
int findMaximumXOR(int *nums, int n) {
    struct TrieNode *root = createBinaryNode(); // Create the root of the Trie
    insertBinaryTrie(root, nums[0]); // Insert the first number into the Trie

    int maxResult = 0; // Variable to store the maximum XOR result

    // Process the rest of the numbers
    for (int i = 1; i < n; i++) {
        // Find the maximum XOR for the current number and update maxResult
        maxResult = (maxResult > findMaxXOR(root, nums[i])) ? maxResult : findMaxXOR(root, nums[i]);
        insertBinaryTrie(root, nums[i]); // Insert the current number into the Trie
    }

    return maxResult; // Return the maximum XOR found
}

int main() {
    int nums[] = {3, 10, 5, 25, 2, 8};
    int n = sizeof(nums) / sizeof(nums[0]);

    int maxXOR = findMaximumXOR(nums, n); // Find the maximum XOR
    printf("Maximum XOR is: %d\n", maxXOR);

    return 0;
}
// Maximum XOR is: 28