# Ant Colony Optimization

## Overview

Ant Colony Optimization (ACO) is a probabilistic technique used for solving computational problems which can be reduced to finding good paths through graphs. It is based on the behavior of ants finding paths from their colony to food. ACO is particularly effective for combinatorial optimization problems, such as the Traveling Salesman Problem (TSP).

In ACO, artificial ants traverse the graph, depositing pheromones on paths they take. The amount of pheromone deposited is inversely proportional to the length of the path, encouraging subsequent ants to follow shorter paths. Over time, pheromone levels guide ants toward optimal solutions.

## Algorithm

1. **Initialization**: Set initial pheromone levels and distance matrix.
2. **Ant Movement**: Each ant starts from a random city and chooses the next city based on pheromone levels and distances, using a probability function that considers both factors.
3. **Tour Length Calculation**: After all ants complete their tours, the lengths of each tour are calculated.
4. **Pheromone Update**: Update pheromone levels on the paths based on the lengths of the tours:
   - Evaporate pheromones on all paths.
   - Deposit pheromones based on the quality of the solutions (shorter tours receive more pheromone).
5. **Iteration**: Repeat the process for a specified number of iterations to allow convergence towards an optimal solution.


The following C code implements the Ant Colony Optimization algorithm for solving the Traveling Salesman Problem

