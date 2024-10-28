# Traveling Salesman Problem (TSP)

## Description

The **Traveling Salesman Problem (TSP)** is a classic optimization problem in computer science and operations research. The objective of the problem is to find the shortest possible route that visits each city exactly once and returns to the origin city. This problem is NP-hard, meaning that there is no known polynomial-time algorithm to solve it efficiently for large instances.

### Problem Definition

Given:
- A set of `n` cities.
- A distance matrix `dist[][]` where `dist[i][j]` represents the distance between city `i` and city `j`.

Objective:
- Find a Hamiltonian cycle (a cycle that visits every city exactly once and returns to the start) with the minimum possible total distance.

### Example

Consider 4 cities with the following distance matrix:

dist = { {0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0} }


- The goal is to find the shortest path that visits all cities and returns to the starting city.
- A possible solution is the path `0 -> 1 -> 3 -> 2 -> 0`, with a total distance of 80 units.

### Algorithm Overview

#### Brute Force Approach:
The brute force approach generates all possible permutations of the cities and calculates the total distance for each permutation. This approach is inefficient, as it has a time complexity of `O(n!)`, where `n` is the number of cities.

#### Dynamic Programming with Bit Masking (Held-Karp Algorithm):
A more efficient approach is to use **dynamic programming** with **bit masking** to store intermediate results and avoid redundant calculations. The idea is to use a bitmask to represent the set of visited cities and compute the shortest path recursively.

Steps:
1. Use a recursive function `TSP(mask, pos)` where `mask` is the bitmask representing visited cities and `pos` is the current city.
2. At each step, move to an unvisited city and compute the shortest path recursively.
3. Use dynamic programming to store the intermediate results and avoid recomputation.
4. The base case is when all cities are visited, in which case the function returns the distance to the starting city.
5. The optimal solution is obtained by starting from any city (typically city 0) and visiting all other cities.

### Time Complexity

- **Brute Force**: `O(n!)`, where `n` is the number of cities.
- **Dynamic Programming with Bit Masking**: `O(n^2 * 2^n)`, which is much more efficient for large values of `n`.

### Applications

The Traveling Salesman Problem has applications in:
- **Logistics and transportation**: Optimizing delivery routes and minimizing travel costs.
- **Circuit design**: Minimizing the length of wiring in circuit board design.
- **DNA sequencing**: Reconstructing the shortest superstring in bioinformatics.
- **Tourism**: Planning optimal travel itineraries for tourists.

### Challenges

TSP is NP-hard, meaning that finding an exact solution for large instances is computationally infeasible. Approximation algorithms and heuristics, such as **genetic algorithms**, **simulated annealing**, and **ant colony optimization**, are often used to find near-optimal solutions for large instances of TSP.
