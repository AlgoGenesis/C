#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int feature_index;
    double threshold;
    int label;
    struct Node *left, *right;
} Node;

// Create a new node
Node* create_node(int feature_index, double threshold, int label) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->feature_index = feature_index;
    node->threshold = threshold;
    node->label = label;
    node->left = node->right = NULL;
    return node;
}

// Recursive function to classify a data point using the decision tree
int classify(Node *node, double *features) {
    if (node->left == NULL && node->right == NULL) {
        return node->label;
    }

    if (features[node->feature_index] < node->threshold) {
        return classify(node->left, features);
    } else {
        return classify(node->right, features);
    }
}

int main() {
    int feature_count = 2;  // Let's assume we have 2 features for simplicity

    // Manually build the decision tree (simple example)
    Node *root = create_node(0, 2.5, -1);  // Root node decision on feature 0 (x < 2.5)
    root->left = create_node(-1, 0, 0);  // Leaf node with label 0
    root->right = create_node(1, 3.5, -1);  // Decision node on feature 1 (y < 3.5)
    root->right->left = create_node(-1, 0, 1);  // Leaf node with label 1
    root->right->right = create_node(-1, 0, 0);  // Leaf node with label 0

    // Input test data point (features)
    double *test_features = (double *)malloc(feature_count * sizeof(double));
    printf("Enter feature values for test point:\n");
    for (int i = 0; i < feature_count; i++) {
        printf("Feature %d: ", i + 1);
        scanf("%lf", &test_features[i]);
    }

    // Classify the test point using the decision tree
    int result = classify(root, test_features);
    printf("The predicted label is: %d\n", result);

    // Free memory
    free(test_features);
    free(root->left);
    free(root->right->left);
    free(root->right->right);
    free(root->right);
    free(root);

    return 0;
}
