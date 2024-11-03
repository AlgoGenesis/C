# Dynamic Weighted Graph Search Algorithm

## Description

This program implements a Dynamic Weighted Graph Search Algorithm designed to find the shortest path in a graph where edge weights can change dynamically during the search process. Unlike traditional algorithms (e.g., Dijkstra’s), this approach adapts to fluctuating conditions, such as increasing path costs due to congestion or other external factors.

### Problem Definition

Given:
- A graph represented by an adjacency matrix where each entry represents the weight (cost) of an edge between nodes.
- A set of nodes and edges, input by the user.
- Dynamic weight adjustments that increase edge weights based on usage.

#### Objective:

Find the shortest path between a start node and a goal node while adapting to weight changes in real time as the search progresses.
### Algorithm Overview

**1. Input the Graph:**
Prompt the user for the number of nodes and edges.
For each edge, input the two connected nodes and the initial weight.

**2. Initialize Search Data:**
Set up arrays to track distances from the start node, visited nodes, and previous nodes for path reconstruction.

**3. Dynamic Path Search:**
For each step, find the node with the minimum current distance that hasn't been visited.
Dynamically update the weights of edges connected to this node to simulate real-time changes.
Re-evaluate neighboring nodes to maintain the shortest path.

**4. Output the Shortest Path:**
Display the total path cost and the sequence of nodes forming the shortest path from start to goal.

### Time Complexity

The time complexity is approximately O(n^2), where n is the number of nodes. Each node and its neighbors are processed once, similar to Dijkstra's algorithm, but with additional updates to edge weights.

### Example Code
The complete code for the Dynamic Weighted Graph Search Algorithm is as below:
```c 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100
#define INF INT_MAX

int graph[MAX_NODES][MAX_NODES];   // Adjacency matrix
int distance[MAX_NODES];           // Stores shortest distance from start node
int visited[MAX_NODES];            // Tracks visited nodes
int previous[MAX_NODES];           // To reconstruct the path
int n;                             // Number of nodes in the graph

void update_weights_dynamically(int node) {
    for (int i = 0; i < n; i++) {
        if (graph[node][i] != INF) {
            graph[node][i] += 2;
        }
    }
}

int find_min_distance() {
    int min = INF, min_index = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && distance[i] < min) {
            min = distance[i];
            min_index = i;
        }
    }
    return min_index;
}

void dynamic_weighted_search(int start, int goal) {
    for (int i = 0; i < n; i++) {
        distance[i] = INF;
        visited[i] = 0;
        previous[i] = -1;
    }
    distance[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int current = find_min_distance();
        if (current == -1) break;

        visited[current] = 1;
        update_weights_dynamically(current);

        for (int i = 0; i < n; i++) {
            if (!visited[i] && graph[current][i] != INF && 
                distance[current] + graph[current][i] < distance[i]) {
                distance[i] = distance[current] + graph[current][i];
                previous[i] = current;
            }
        }
    }

    if (distance[goal] == INF) {
        printf("No path from %d to %d\n", start, goal);
    } else {
        printf("Shortest path cost from %d to %d: %d\n", start, goal, distance[goal]);
        printf("Path: ");
        int path[MAX_NODES], index = 0;
        for (int v = goal; v != -1; v = previous[v]) {
            path[index++] = v;
        }
        for (int i = index - 1; i >= 0; i--) {
            printf("%d ", path[i]);
        }
        printf("\n");
    }
}

int main() {
    int start, goal;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = (i == j) ? 0 : INF;
        }
    }

    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter edges (u v weight) format:\n");
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    printf("Enter the start node: ");
    scanf("%d", &start);
    printf("Enter the goal node: ");
    scanf("%d", &goal);

    dynamic_weighted_search(start, goal);

    return 0;
}
```

### Example 

Assume a graph with 4 nodes and edges defined as:
**Graph Edges:**
Edge (0, 1) with weight 5
Edge (1, 2) with weight 2
Edge (2, 3) with weight 1
Edge (0, 3) with weight 9

### Example Input

Enter the number of nodes: 4
Enter the number of edges: 4
Enter edges (u v weight) format:
0 1 5
1 2 2
2 3 1
0 3 9
Enter the start node: 0

Enter the goal node: 3

### Expected Output Recived 

Shortest path cost from 0 to 3: [Calculated Cost]
Path: 0 -> [Intermediate Nodes] -> 3

### Memory Management

The adjacency matrix is statically allocated for simplicity. For larger graphs, dynamic memory allocation could be used to reduce memory footprint.

### Key Points

- The algorithm is designed for dynamic environments, adapting path costs based on current node interactions.
- It efficiently recalculates shortest paths in real time, useful in applications like traffic-based navigation and adaptive routing in networks.
- Users can adjust the weight update function to model various real-world conditions.