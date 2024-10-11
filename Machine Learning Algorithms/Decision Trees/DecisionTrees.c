#include <stdio.h>
#include <stdlib.h>

// Structure for a decision tree node
struct Node {
    int feature;
    double threshold;
    int label; // -1 for internal nodes
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* create_node(int feature, double threshold, int label) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->feature = feature;
    node->threshold = threshold;
    node->label = label;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Manually construct a simple decision tree
struct Node* build_tree() {
    struct Node* root = create_node(0, 2.5, -1); // Feature 0, threshold 2.5
    root->left = create_node(-1, 0, 0); // Leaf node with label 0
    root->right = create_node(-1, 0, 1); // Leaf node with label 1
    return root;
}

// Function to predict the label for a new data point
int predict(struct Node* node, double features[]) {
    if (node->label != -1) {
        return node->label;
    }
    
    if (features[node->feature] <= node->threshold) {
        return predict(node->left, features);
    } else {
        return predict(node->right, features);
    }
}

int main() {
    // Build the decision tree
    struct Node* tree = build_tree();
    
    // Test data point
    double test_data[1] = {3.0};
    
    // Predict the label
    int predicted_label = predict(tree, test_data);
    printf("Predicted label: %d\n", predicted_label);
    
    return 0;
}
