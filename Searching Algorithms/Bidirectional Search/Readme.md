# Bidirectional Search Algorithm in C

## Overview

This repository contains an implementation of the **Bidirectional Search** algorithm in C. Bidirectional Search is a graph traversal technique used to find the shortest path between a source node and a target node. Instead of searching from the source to the target directly, it simultaneously searches from both the source and target and stops when the two searches meet, significantly reducing the time complexity.

## Algorithm

The **Bidirectional Search** algorithm works as follows:
1. It performs two simultaneous **Breadth-First Searches (BFS)**:
   - One search starts from the **source node** and explores outward.
   - The other search starts from the **destination node** and explores inward.
2. The search continues until a node is visited by both BFS trees, indicating an intersection.
3. The shortest path is then constructed from the source to the destination via the intersecting node.

### Features:
- **Efficient pathfinding**: Bidirectional Search significantly reduces the number of explored nodes compared to regular BFS.
- **Simultaneous search**: Expands nodes from both the source and the destination.
- **Intersection-based termination**: The algorithm stops as soon as the searches meet, allowing for early termination in large graphs.

## Code

The code is written in C and makes use of an adjacency matrix to represent the graph. Here is a portion of the code:

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

void initializeGraph(int graph[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
}

void addEdge(int graph[MAX][MAX], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void bidirectionalSearch(int graph[MAX][MAX], int src, int dest, int n) {
    // ... (complete code in repository)
}
