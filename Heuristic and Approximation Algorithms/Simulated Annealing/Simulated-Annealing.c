#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Example objective function (minimization)
double objective_function(double x) {
    return (x - 3) * (x - 3) + 5; // (x-3)^2 + 5 (Example function)
}

// Generate a neighboring solution by adding a random perturbation
double neighbor_solution(double x) {
    double perturbation = ((double)rand() / RAND_MAX) * 2 - 1; // Random value between -1 and 1
    return x + perturbation;
}

// Simulated Annealing algorithm
double simulated_annealing(double initial_solution, double initial_temp, double cooling_rate, int iterations) {
    double current_solution = initial_solution;
    double best_solution = current_solution;
    double temperature = initial_temp;
    
    for (int i = 0; i < iterations; i++) {
        double new_solution = neighbor_solution(current_solution);
        double delta_cost = objective_function(new_solution) - objective_function(current_solution);

        // Accept new solution if it's better or based on the probability condition
        if (delta_cost < 0 || (exp(-delta_cost / temperature) > (double)rand() / RAND_MAX)) {
            current_solution = new_solution;
        }

        // Update best solution found so far
        if (objective_function(current_solution) < objective_function(best_solution)) {
            best_solution = current_solution;
        }

        // Cool down temperature
        temperature *= cooling_rate;
    }
    
    return best_solution;
}

int main() {
    srand(time(NULL));

    // Parameters for the algorithm
    double initial_solution = 10.0; // Starting point
    double initial_temp = 1000.0;   // Initial temperature
    double cooling_rate = 0.98;     // Cooling rate (α)
    int iterations = 1000;          // Number of iterations

    // Run simulated annealing
    double best_solution = simulated_annealing(initial_solution, initial_temp, cooling_rate, iterations);

    printf("Best solution found: %f\n", best_solution);
    printf("Objective value: %f\n", objective_function(best_solution));

    return 0;
}
