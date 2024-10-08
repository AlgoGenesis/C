# Genetic Algorithms

## About
Genetic Algorithms (GAs) are search heuristics inspired by the process of natural selection. They are used to find approximate solutions to optimization and search problems. GAs work by evolving a population of candidate solutions through selection, crossover, and mutation.

### Algorithm Overview:
1. **Initialization**: Generate an initial population of random candidate solutions.
2. **Evaluation**: Evaluate the fitness of each candidate solution.
3. **Selection**: Select pairs of candidates based on fitness (better candidates are more likely to be selected).
4. **Crossover**: Perform crossover (recombination) to create new candidate solutions (offspring).
5. **Mutation**: Randomly mutate some candidates to maintain diversity in the population.
6. **Replacement**: Replace some or all of the population with the new generation.
7. **Termination**: Repeat the process for a specified number of generations or until convergence.

### C Code
The Genetic Algorithm is implemented in C to solve a simple optimization problem. The code can be found in `genetic_algorithm.c`.
