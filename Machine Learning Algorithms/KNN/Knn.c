#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// A structure to hold the data point and its label
typedef struct {
    double features[2]; // Example with 2 features
    int label;
} DataPoint;

// Function to calculate the Euclidean distance between two data points
double euclidean_distance(double point1[], double point2[], int length) {
    double sum = 0.0;
    for (int i = 0; i < length; i++) {
        sum += pow(point1[i] - point2[i], 2);
    }
    return sqrt(sum);
}

// Comparator function for qsort to sort distances
int compare(const void *a, const void *b) {
    return (*(double*)a > *(double*)b) - (*(double*)a < *(double*)b);
}

// Function to classify a data point using KNN
int knn_classify(DataPoint train_data[], int train_size, double test_point[], int k) {
    double distances[train_size];
    int labels[train_size];

    // Calculate distances between test point and all training data
    for (int i = 0; i < train_size; i++) {
        distances[i] = euclidean_distance(train_data[i].features, test_point, 2);
        labels[i] = train_data[i].label;
    }

    // Sort the distances
    qsort(distances, train_size, sizeof(double), compare);

    // Count votes for K nearest neighbors
    int count0 = 0, count1 = 0;
    for (int i = 0; i < k; i++) {
        if (labels[i] == 0) {
            count0++;
        } else {
            count1++;
        }
    }

    // Return the label with the most votes
    return (count0 > count1) ? 0 : 1;
}

int main() {
    // Example training data with 2 features and binary labels (0 or 1)
    DataPoint train_data[] = {
        {{1.0, 2.0}, 0},
        {{2.0, 3.0}, 0},
        {{3.0, 3.0}, 1},
        {{5.0, 4.0}, 1},
        {{1.5, 2.5}, 0}
    };
    int train_size = 5;
    int k = 3;

    // Test data point
    double test_point[] = {2.5, 3.5};

    // Classify the test point
    int label = knn_classify(train_data, train_size, test_point, k);
    printf("Predicted label: %d\n", label);

    return 0;
}
