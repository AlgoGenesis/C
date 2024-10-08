# Greedy Randomized Adaptive Search Procedure (GRASP)

## Overview
GRASP is a multi-start or iterative process for solving combinatorial optimization problems. It consists of two phases:

1. **Construction Phase**: Build a feasible solution using a greedy randomized method.
2. **Local Search Phase**: Improve the constructed solution using local search techniques.

This approach is particularly effective for solving NP-hard problems, such as the Traveling Salesman Problem (TSP).

## Algorithm

1. **Initialization**: 
   - Start with an empty tour and initialize the best tour length to infinity.

2. **Construct Greedy Randomized Solution**:
   - Select a random starting city.
   - While there are unvisited cities:
     - Identify candidates based on the minimum distance from the current city.
     - Randomly choose the next city from the candidate list.

3. **Calculate Tour Length**: 
   - Compute the total distance of the constructed tour.

4. **Iterate**:
   - Repeat the construction phase for a predefined number of iterations, updating the best tour and its length when a better solution is found.

5. **Output**: 
   - Display the best tour and its total length.
