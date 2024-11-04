#include <stdio.h>
#include <stdlib.h>

#define LEARNING_RATE 0.01
#define EPOCHS 1000
#define LAMBDA 0.01 // Regularization parameter

// Sample data structure for a data point
typedef struct {
    double x1;
    double x2;
    int label;
} DataPoint;

// Function to initialize weights
void initializeWeights(double *weights, int size) {
    for (int i = 0; i < size; i++) {
        weights[i] = 0.0;
    }
}

// Function to calculate dot product
double dotProduct(double *weights, DataPoint point) {
    return weights[0] * point.x1 + weights[1] * point.x2;
}

// SVM training function using Stochastic Gradient Descent
void trainSVM(DataPoint *data, int dataSize, double *weights) {
    for (int epoch = 0; epoch < EPOCHS; epoch++) {
        for (int i = 0; i < dataSize; i++) {
            DataPoint point = data[i];
            double y = point.label;
            double prediction = dotProduct(weights, point);

            // Update rule for SVM
            if (y * prediction < 1) {
                weights[0] += LEARNING_RATE * ((y * point.x1) - (2 * LAMBDA * weights[0]));
                weights[1] += LEARNING_RATE * ((y * point.x2) - (2 * LAMBDA * weights[1]));
            } else {
                weights[0] += LEARNING_RATE * (-2 * LAMBDA * weights[0]);
                weights[1] += LEARNING_RATE * (-2 * LAMBDA * weights[1]);
            }
        }
    }
}

// Function to make predictions
int predict(double *weights, DataPoint point) {
    double prediction = dotProduct(weights, point);
    return (prediction >= 0) ? 1 : -1;
}

int main() {
    // Training data (XOR dataset)
    DataPoint data[] = {
        {2, 3, 1},
        {1, 1, -1},
        {2, 1, -1},
        {3, 2, 1},
        {3, 3, 1},
        {1, 2, -1}
    };
    int dataSize = sizeof(data) / sizeof(data[0]);
    
    double weights[2];
    initializeWeights(weights, 2);

    // Train the SVM model
    trainSVM(data, dataSize, weights);

    // Test the SVM model
    DataPoint testPoint = {3, 3, 1};
    int prediction = predict(weights, testPoint);
    printf("Prediction for test point (3, 3): %d\n", prediction);

    return 0;
}
