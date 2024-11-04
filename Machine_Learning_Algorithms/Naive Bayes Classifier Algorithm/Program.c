#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CLASSES 2 // Spam and Not Spam
#define NUM_FEATURES 5 // Number of features (words)
#define NUM_SAMPLES 6 // Number of training samples

// Sample data: Each row represents a document with features indicating presence of words (1) or absence (0)
int data[NUM_SAMPLES][NUM_FEATURES] = {
    {1, 1, 0, 1, 0}, // Spam
    {1, 0, 1, 1, 1}, // Spam
    {0, 1, 1, 0, 0}, // Not Spam
    {1, 1, 1, 0, 0}, // Not Spam
    {0, 0, 1, 1, 1}, // Not Spam
    {1, 0, 0, 0, 1}  // Spam
};

// Labels for the training data (0 = Not Spam, 1 = Spam)
int labels[NUM_SAMPLES] = {1, 1, 0, 0, 0, 1};

// Function to calculate prior probabilities
void calculate_prior(double *prior) {
    for (int i = 0; i < NUM_CLASSES; i++) {
        prior[i] = 0;
    }
    
    for (int i = 0; i < NUM_SAMPLES; i++) {
        prior[labels[i]]++;
    }

    for (int i = 0; i < NUM_CLASSES; i++) {
        prior[i] /= NUM_SAMPLES; // Normalize
    }
}

// Function to calculate likelihoods
void calculate_likelihood(double likelihood[NUM_CLASSES][NUM_FEATURES]) {
    for (int i = 0; i < NUM_CLASSES; i++) {
        for (int j = 0; j < NUM_FEATURES; j++) {
            likelihood[i][j] = 1; // Use Laplace smoothing
        }
    }

    for (int i = 0; i < NUM_SAMPLES; i++) {
        for (int j = 0; j < NUM_FEATURES; j++) {
            likelihood[labels[i]][j] += data[i][j];
        }
    }

    for (int i = 0; i < NUM_CLASSES; i++) {
        for (int j = 0; j < NUM_FEATURES; j++) {
            likelihood[i][j] /= (prior[i] * NUM_SAMPLES + 2); // Smooth with total features
        }
    }
}

// Function to predict the class for a given instance
int predict(int instance[NUM_FEATURES], double prior[NUM_CLASSES], double likelihood[NUM_CLASSES][NUM_FEATURES]) {
    double posteriors[NUM_CLASSES] = {0};
    
    for (int i = 0; i < NUM_CLASSES; i++) {
        posteriors[i] = prior[i];
        for (int j = 0; j < NUM_FEATURES; j++) {
            posteriors[i] *= likelihood[i][j] * instance[j];
        }
    }

    return (posteriors[1] > posteriors[0]) ? 1 : 0; // Return class with higher probability
}

int main() {
    double prior[NUM_CLASSES];
    double likelihood[NUM_CLASSES][NUM_FEATURES];

    // Calculate prior probabilities and likelihoods
    calculate_prior(prior);
    calculate_likelihood(likelihood);

    // Test instance (example: a new document)
    int test_instance[NUM_FEATURES] = {1, 0, 1, 1, 0}; // New document to classify

    // Predict class for the test instance
    int predicted_class = predict(test_instance, prior, likelihood);

    // Output the result
    printf("Predicted class: %s\n", (predicted_class == 1) ? "Spam" : "Not Spam");

    return 0;
}
