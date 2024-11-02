#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define M_PI if not available in the math library
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Function to calculate the probability density of the target distribution (normal distribution)
double target_distribution(double x) {
    double mean = 0.0;
    double std_dev = 1.0;
    double exponent = - (x - mean) * (x - mean) / (2 * std_dev * std_dev);
    return exp(exponent) / (std_dev * sqrt(2 * M_PI));
}

// Function to propose a new sample, adds a random value within a step range around the current sample
double proposal(double x) {
    double step_size = 0.5;  // Step size for proposal distribution
    return x + ((rand() / (double)RAND_MAX) - 0.5) * step_size * 2.0;
}

// Metropolis-Hastings algorithm for MCMC
void metropolis_hastings(int samples, double *chain) {
    chain[0] = 0.0;  // Initial starting point
    
    for (int i = 1; i < samples; i++) {
        double current = chain[i - 1];
        double proposed = proposal(current);
        
        // Calculate acceptance ratio
        double acceptance_ratio = target_distribution(proposed) / target_distribution(current);
        
        // Accept or reject the proposal based on the acceptance ratio
        if (acceptance_ratio >= 1.0 || ((double)rand() / RAND_MAX) < acceptance_ratio) {
            chain[i] = proposed;  // Accept proposal
        } else {
            chain[i] = current;  // Reject proposal, stay at current sample
        }
    }
}

// Main function to initialize, run MCMC, and print samples
int main() {
    srand(time(NULL));  // Seed for random number generation

    int samples = 10000;  // Number of samples
    double *chain = malloc(samples * sizeof(double));
    if (chain == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    metropolis_hastings(samples, chain);
    
    // Output every 100th sample to avoid too much output and for easier verification
    printf("MCMC Samples (every 100th sample):\n");
    for (int i = 0; i < samples; i += 100) {
        printf("%f\n", chain[i]);
    }
    
    free(chain);
    return 0;
}