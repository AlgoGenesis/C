#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct TreeNode {
    double splitValue;
    int splitFeature;
    struct TreeNode *left;
    struct TreeNode *right;
    int isLeaf;
    int count; // count of samples in the node
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(double splitValue, int splitFeature, int isLeaf, int count) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->splitValue = splitValue;
    node->splitFeature = splitFeature;
    node->left = NULL;
    node->right = NULL;
    node->isLeaf = isLeaf;
    node->count = count;
    return node;
}

// Function to build the Isolation Forest
TreeNode* buildIsolationTree(double **data, int n, int depth, int maxDepth) {
    if (depth >= maxDepth || n <= 1) {
        return createNode(0, 0, 1, n); // Leaf node
    }

    int splitFeature = rand() % 2; // Assuming 2 features for simplicity
    double splitValue = ((double)rand() / RAND_MAX) * (data[n - 1][splitFeature] - data[0][splitFeature]) + data[0][splitFeature];

    int leftCount = 0, rightCount = 0;
    double **leftData = (double**)malloc(n * sizeof(double*));
    double **rightData = (double**)malloc(n * sizeof(double*));

    for (int i = 0; i < n; i++) {
        if (data[i][splitFeature] < splitValue) {
            leftData[leftCount++] = data[i];
        } else {
            rightData[rightCount++] = data[i];
        }
    }

    TreeNode* node = createNode(splitValue, splitFeature, 0, n);
    node->left = buildIsolationTree(leftData, leftCount, depth + 1, maxDepth);
    node->right = buildIsolationTree(rightData, rightCount, depth + 1, maxDepth);

    free(leftData);
    free(rightData);
    
    return node;
}

// Function to calculate the path length for a sample
int pathLength(TreeNode* node, double* sample) {
    if (node->isLeaf) {
        return 0; // Leaf node, return path length as 0
    }
    
    if (sample[node->splitFeature] < node->splitValue) {
        return 1 + pathLength(node->left, sample);
    } else {
        return 1 + pathLength(node->right, sample);
    }
}

// Function to compute the anomaly score
double anomalyScore(TreeNode* forest[], int forestSize, double* sample) {
    double totalPathLength = 0.0;

    for (int i = 0; i < forestSize; i++) {
        totalPathLength += pathLength(forest[i], sample);
    }

    return pow(2, -totalPathLength / forestSize);
}

int main() {
    srand(time(NULL));
    int n = 10; // Number of samples
    int forestSize = 5; // Number of trees in the forest
    int maxDepth = 5; // Maximum depth of the tree

    // Sample data (10 samples with 2 features)
    double **data = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        data[i] = (double*)malloc(2 * sizeof(double));
        data[i][0] = (double)rand() / RAND_MAX * 10; // Feature 1
        data[i][1] = (double)rand() / RAND_MAX * 10; // Feature 2
    }

    // Build the Isolation Forest
    TreeNode* forest[forestSize];
    for (int i = 0; i < forestSize; i++) {
        forest[i] = buildIsolationTree(data, n, 0, maxDepth);
    }

    // Test with a sample point
    double sample[2] = {8.0, 8.0};
    double score = anomalyScore(forest, forestSize, sample);
    
    printf("Anomaly Score for sample (%lf, %lf): %lf\n", sample[0], sample[1], score);

    // Free memory
    for (int i = 0; i < n; i++) {
        free(data[i]);
    }
    free(data);
    
    for (int i = 0; i < forestSize; i++) {
        free(forest[i]);
    }

    return 0;
}
