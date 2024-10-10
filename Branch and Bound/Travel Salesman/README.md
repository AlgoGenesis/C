
# Traveling Salesman Problem Solver Using Branch and Bound

## Description
The Traveling Salesman Problem (TSP) Solver is an implementation of the Branch and Bound algorithm used to find the minimum cost path for a salesman who must visit every city exactly once and return to the starting city. The algorithm efficiently explores all possible tours and prunes unnecessary paths to minimize computation, ensuring the best possible solution with optimal time complexity.

## Problem Definition
Given:
- A set of `N` cities and a distance matrix (adjacency matrix) where the cost to travel between any two cities is defined.

Objective:
- Find the minimum cost tour that visits every city exactly once and returns to the starting city.

## Algorithm Overview
The Branch and Bound approach is used to solve TSP by calculating a lower bound on the cost of completing a partial tour and using this information to prune unpromising paths. The algorithm proceeds by expanding paths recursively, only exploring promising routes while eliminating others based on cost bounds.

## Steps:
1. **Initialization**: Set the lower bound for the root node using the sum of the minimum and second minimum costs for each city.
2. **Recursive Exploration**:
   - Start with the first city and mark it as visited.
   - Recursively explore unvisited cities, adding their costs to the current tour.
   - After visiting all cities, check the cost of returning to the start city.
3. **Bounding**:
   - Calculate the lower bound of the current tour using minimum and second minimum edge costs.
   - Prune any branch if the cost of the current tour exceeds the known best solution.
4. **Backtracking**: If a better solution is found, update the optimal solution. Otherwise, backtrack by marking the current city as unvisited and try the next city.
5. **Termination**: When all cities have been explored, the algorithm returns the optimal path and the minimum cost.

## Functions:
- `firstMin(adj, i, N)`: Finds the minimum edge cost from city `i`.
- `secondMin(adj, i, N)`: Finds the second minimum edge cost from city `i`.
- `copyToFinal(curr_path, N)`: Copies the current valid path to the final solution.
- `TSPRec(adj, curr_bound, curr_weight, level, curr_path, N)`: Recursively explores possible paths while bounding and pruning unpromising routes.
- `TSP(adj, N)`: Initializes the necessary variables and starts the recursion.

#### Input:
- The program takes an input of the number of cities (`N`) and the adjacency matrix (cost matrix) where the distance between cities is specified.

## Time Complexity
The time complexity of the Branch and Bound solution for TSP is O(N!), where `N` is the number of cities. Although the worst-case complexity is factorial, the bounding technique significantly reduces the number of nodes explored, making it more efficient than brute force for moderate-sized inputs.

## Example:
For `N = 4` cities, and an adjacency matrix like:

```
  0  10  15  20
 10   0  35  25
 15  35   0  30
 20  25  30   0
```

The algorithm will find the optimal path and the minimum cost to visit all cities.
