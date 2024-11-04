#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_NODES 2      // Number of input nodes
#define HIDDEN_NODES 2     // Number of hidden nodes
#define OUTPUT_NODES 1     // Number of output nodes
#define LEARNING_RATE 0.1  // Learning rate
#define EPOCHS 10000       // Number of training epochs

// Activation function: Sigmoid
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// Derivative of Sigmoid
double sigmoid_derivative(double x) {
    return x * (1.0 - x);
}

// Neural Network structure
typedef struct {
    double input[INPUT_NODES];          // Input layer
    double hidden[HIDDEN_NODES];        // Hidden layer
    double output[OUTPUT_NODES];        // Output layer
    double weights_input[INPUT_NODES][HIDDEN_NODES];  // Weights from input to hidden
    double weights_hidden[HIDDEN_NODES][OUTPUT_NODES]; // Weights from hidden to output
    double bias_hidden[HIDDEN_NODES];   // Biases for hidden layer
    double bias_output[OUTPUT_NODES];   // Biases for output layer
} NeuralNetwork;

// Initialize the neural network
void initialize_network(NeuralNetwork *nn) {
    // Randomly initialize weights and biases
    for (int i = 0; i < INPUT_NODES; i++) {
        for (int j = 0; j < HIDDEN_NODES; j++) {
            nn->weights_input[i][j] = ((double)rand() / RAND_MAX) * 2 - 1; // Range [-1, 1]
        }
    }

    for (int j = 0; j < HIDDEN_NODES; j++) {
        for (int k = 0; k < OUTPUT_NODES; k++) {
            nn->weights_hidden[j][k] = ((double)rand() / RAND_MAX) * 2 - 1; // Range [-1, 1]
        }
        nn->bias_hidden[j] = ((double)rand() / RAND_MAX) * 2 - 1; // Range [-1, 1]
    }

    for (int k = 0; k < OUTPUT_NODES; k++) {
        nn->bias_output[k] = ((double)rand() / RAND_MAX) * 2 - 1; // Range [-1, 1]
    }
}

// Forward pass through the network
void forward_pass(NeuralNetwork *nn) {
    // Calculate hidden layer activations
    for (int j = 0; j < HIDDEN_NODES; j++) {
        nn->hidden[j] = 0;
        for (int i = 0; i < INPUT_NODES; i++) {
            nn->hidden[j] += nn->input[i] * nn->weights_input[i][j];
        }
        nn->hidden[j] += nn->bias_hidden[j];
        nn->hidden[j] = sigmoid(nn->hidden[j]);
    }

    // Calculate output layer activations
    for (int k = 0; k < OUTPUT_NODES; k++) {
        nn->output[k] = 0;
        for (int j = 0; j < HIDDEN_NODES; j++) {
            nn->output[k] += nn->hidden[j] * nn->weights_hidden[j][k];
        }
        nn->output[k] += nn->bias_output[k];
        nn->output[k] = sigmoid(nn->output[k]);
    }
}

// Backpropagation algorithm
void backpropagation(NeuralNetwork *nn, double target[]) {
    double output_error[OUTPUT_NODES];
    double hidden_error[HIDDEN_NODES];

    // Calculate output error
    for (int k = 0; k < OUTPUT_NODES; k++) {
        output_error[k] = target[k] - nn->output[k];
    }

    // Calculate hidden layer error
    for (int j = 0; j < HIDDEN_NODES; j++) {
        hidden_error[j] = 0;
        for (int k = 0; k < OUTPUT_NODES; k++) {
            hidden_error[j] += output_error[k] * nn->weights_hidden[j][k] * sigmoid_derivative(nn->output[k]);
        }
    }

    // Update weights and biases from hidden to output
    for (int k = 0; k < OUTPUT_NODES; k++) {
        for (int j = 0; j < HIDDEN_NODES; j++) {
            nn->weights_hidden[j][k] += LEARNING_RATE * output_error[k] * sigmoid_derivative(nn->output[k]) * nn->hidden[j];
        }
        nn->bias_output[k] += LEARNING_RATE * output_error[k] * sigmoid_derivative(nn->output[k]);
    }

    // Update weights and biases from input to hidden
    for (int j = 0; j < HIDDEN_NODES; j++) {
        for (int i = 0; i < INPUT_NODES; i++) {
            nn->weights_input[i][j] += LEARNING_RATE * hidden_error[j] * sigmoid_derivative(nn->hidden[j]) * nn->input[i];
        }
        nn->bias_hidden[j] += LEARNING_RATE * hidden_error[j] * sigmoid_derivative(nn->hidden[j]);
    }
}

int main() {
    NeuralNetwork nn;
    initialize_network(&nn);

    // Sample dataset: XOR problem
    double inputs[4][INPUT_NODES] = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1}
    };
    double targets[4][OUTPUT_NODES] = {
        {0},
        {1},
        {1},
        {0}
    };

    // Train the neural network
    for (int epoch = 0; epoch < EPOCHS; epoch++) {
        for (int i = 0; i < 4; i++) {
            // Set input
            for (int j = 0; j < INPUT_NODES; j++) {
                nn.input[j] = inputs[i][j];
            }

            // Forward pass
            forward_pass(&nn);

            // Backpropagation
            backpropagation(&nn, targets[i]);
        }
    }

    // Test the trained network
    printf("Testing Neural Network (XOR):\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < INPUT_NODES; j++) {
            nn.input[j] = inputs[i][j];
        }
        forward_pass(&nn);
        printf("Input: [%f, %f] -> Output: %f\n", nn.input[0], nn.input[1], nn.output[0]);
    }

    return 0;
}
