#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to compute the sigmoid of z
double sigmoid(double z) {
    return 1.0 / (1.0 + exp(-z));
}

// Function to compute the dot product of two vectors
double dot_product(double* a, double* b, int size) {
    double result = 0.0;
    for (int i = 0; i < size; i++) {
        result += a[i] * b[i];
    }
    return result;
}

// Function to predict the probability of the positive class
double predict(double* weights, double* features, int num_features) {
    double z = dot_product(weights, features, num_features);
    return sigmoid(z);
}

// Function to train logistic regression using gradient descent
void train_logistic_regression(double** X, double* y, double* weights, int num_samples, int num_features, double learning_rate, int num_iterations) {
    for (int iteration = 0; iteration < num_iterations; iteration++) {
        // Create an array to store gradient updates
        double* gradients = (double*)calloc(num_features, sizeof(double));
        for (int i = 0; i < num_samples; i++) {
            double* features = X[i];
            double predicted = predict(weights, features, num_features);
            double error = predicted - y[i];
            for (int j = 0; j < num_features; j++) {
                gradients[j] += error * features[j];
            }
        }

        for (int j = 0; j < num_features; j++) {
            weights[j] -= learning_rate * gradients[j] / num_samples;
        }
        free(gradients);
    }
}

// Function that evaluates the model on test data
double evaluate(double** X_test, double* y_test, double* weights, int num_test_samples, int num_features) {
    int correct_predictions = 0;

    for (int i = 0; i < num_test_samples; i++) {
        double* features = X_test[i];
        double predicted_prob = predict(weights, features, num_features);
        int predicted_label = (predicted_prob >= 0.5) ? 1 : 0;

        if (predicted_label == (int)y_test[i]) {
            correct_predictions++;
        }
    }

    return (double)correct_predictions / num_test_samples;
}

int main() {
    int num_samples = 4;
    int num_features = 3; // Including bias term (intercept)

    // Input data (X): 4 samples with 2 features and a bias term
    double X[4][3] = {
        {1.0, 0.0, 0.0},
        {1.0, 0.0, 1.0},
        {1.0, 1.0, 0.0},
        {1.0, 1.0, 1.0}
    };

    // Output labels (y): Corresponding binary outputs
    double y[4] = {0, 0, 0, 1};

    // Convert X to a pointer to pointers (to simulate dynamic allocation)
    double** X_ptr = (double**)malloc(num_samples * sizeof(double*));
    for (int i = 0; i < num_samples; i++) {
        X_ptr[i] = (double*)malloc(num_features * sizeof(double));
        for (int j = 0; j < num_features; j++) {
            X_ptr[i][j] = X[i][j];
        }
    }

    double weights[3] = {0.0, 0.0, 0.0};

    double learning_rate = 0.231;
    int num_iterations = 1000;

    train_logistic_regression(X_ptr, y, weights, num_samples, num_features, learning_rate, num_iterations);

    double accuracy = evaluate(X_ptr, y, weights, num_samples, num_features);
    printf("Accuracy: %.2f%%\n", accuracy * 100);

    // Free allocated memory
    for (int i = 0; i < num_samples; i++) {
        free(X_ptr[i]);
    }
    free(X_ptr);

    return 0;
}
