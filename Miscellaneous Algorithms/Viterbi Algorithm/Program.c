#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_STATES 3     // Number of states
#define NUM_OBSERVATIONS 5  // Number of observations

// Function to find the maximum of two values
double max(double a, double b) {
    return (a > b) ? a : b;
}

// Viterbi algorithm function
void viterbi(int observations[], int num_observations, double start_prob[], double trans_prob[NUM_STATES][NUM_STATES], double emit_prob[NUM_STATES][NUM_OBSERVATIONS], int *result_path) {
    double v[num_observations][NUM_STATES]; // DP table to store probabilities
    int path[num_observations][NUM_STATES]; // Path table to store backtracking

    // Initialization
    for (int i = 0; i < NUM_STATES; i++) {
        v[0][i] = log(start_prob[i]) + log(emit_prob[i][observations[0]]);
        path[0][i] = 0;
    }

    // Recursion
    for (int t = 1; t < num_observations; t++) {
        for (int j = 0; j < NUM_STATES; j++) {
            double max_prob = -INFINITY;
            int best_state = 0;

            for (int i = 0; i < NUM_STATES; i++) {
                double prob = v[t - 1][i] + log(trans_prob[i][j]) + log(emit_prob[j][observations[t]]);
                if (prob > max_prob) {
                    max_prob = prob;
                    best_state = i;
                }
            }
            v[t][j] = max_prob;
            path[t][j] = best_state;
        }
    }

    // Termination
    double max_prob = -INFINITY;
    int last_state = 0;
    for (int i = 0; i < NUM_STATES; i++) {
        if (v[num_observations - 1][i] > max_prob) {
            max_prob = v[num_observations - 1][i];
            last_state = i;
        }
    }

    // Backtracking
    result_path[num_observations - 1] = last_state;
    for (int t = num_observations - 2; t >= 0; t--) {
        result_path[t] = path[t + 1][result_path[t + 1]];
    }
}

// Main function to test the Viterbi algorithm
int main() {
    int observations[NUM_OBSERVATIONS] = {0, 1, 2, 1, 0}; // Sequence of observations
    double start_prob[NUM_STATES] = {0.6, 0.3, 0.1}; // Starting probabilities
    double trans_prob[NUM_STATES][NUM_STATES] = {
        {0.7, 0.2, 0.1},
        {0.3, 0.5, 0.2},
        {0.3, 0.3, 0.4}
    }; // Transition probabilities
    double emit_prob[NUM_STATES][NUM_OBSERVATIONS] = {
        {0.5, 0.4, 0.1, 0.2, 0.3},
        {0.1, 0.3, 0.6, 0.2, 0.5},
        {0.2, 0.2, 0.2, 0.5, 0.3}
    }; // Emission probabilities

    int result_path[NUM_OBSERVATIONS]; // Array to store the most probable path

    // Run the Viterbi algorithm
    viterbi(observations, NUM_OBSERVATIONS, start_prob, trans_prob, emit_prob, result_path);

    // Print the most probable path
    printf("Most probable path of states: ");
    for (int i = 0; i < NUM_OBSERVATIONS; i++) {
        printf("%d ", result_path[i]);
    }
    printf("\n");

    return 0;
}
