# Hopcroft–Karp Algorithm for Maximum Bipartite Matching

This project implements the **Hopcroft–Karp Algorithm** in C to find the **maximum matching** in a bipartite graph. The Hopcroft–Karp algorithm is efficient and widely used in scenarios where two sets of elements need to be matched with each other, such as job assignments, network flows, and more.

## Overview

A **bipartite graph** is a graph whose vertices can be divided into two disjoint sets, \( U \) and \( V \), where all edges go between \( U \) and \( V \). A **matching** is a subset of edges where no two edges share a vertex. The goal of the Hopcroft–Karp algorithm is to find the **maximum matching** — the largest possible matching in the bipartite graph.

This algorithm is faster than simpler augmenting path methods and is efficient for large graphs due to its \( O(\sqrt{V} \cdot E) \) time complexity.

## Algorithm Steps

The Hopcroft–Karp algorithm operates in iterative phases of **Breadth-First Search (BFS)** and **Depth-First Search (DFS)**:
1. **BFS Phase**: Find all shortest augmenting paths from unmatched vertices in \( U \).
2. **DFS Phase**: For each unmatched vertex, attempt to find augmenting paths and update the matching.
3. **Repeat** the above steps until no more augmenting paths are found.

## Files

- `hopcroft_karp.c`: Contains the main implementation of the Hopcroft–Karp algorithm in C.
- `README.md`: Documentation file for the project.

## Code Structure

### Functions

- `bfs()`: Uses BFS to find the shortest augmenting paths and labels the distances of each vertex in \( U \).
- `dfs(int u)`: Uses DFS to attempt to find an augmenting path for a given vertex `u`.
- `hopcroftKarp()`: Main function that initializes the matching process and calls BFS and DFS iteratively to find the maximum matching.

### Data Structures

- `pairU` and `pairV`: Arrays representing the matching pairs. If `pairU[u] = v`, then vertex `u` in \( U \) is matched with vertex `v` in \( V \).
- `dist`: Array used for storing the BFS distances.
