# Articulation Points 

## Description

This program implements an algorithm to find articulation points in an undirected graph. An articulation point is a vertex that, when removed, increases the number of connected components in the graph. This program utilizes Depth-First Search (DFS) to identify such points efficiently.

## Structures

1. **Graph**:
   - A structure to represent a graph using an adjacency matrix.
   - Members:
     - `int vertices`: The number of vertices in the graph.
     - `int adj[MAX][MAX]`: Adjacency matrix to represent edges between vertices.

## Functions

1. **Graph* createGraph(int vertices)**:
   - Creates and initializes a graph with a specified number of vertices.
   - Returns a pointer to the created graph.

2. **void addEdge(Graph* g, int u, int v)**:
   - Adds an undirected edge between vertices `u` and `v` in the graph.

3. **void articulationPointsUtil(Graph* g, int u, int visited[], int parent[], int low[], int disc[], int ap[])**:
   - A recursive utility function that performs DFS and identifies articulation points.
   - Updates the discovery time and low value for each vertex.

4. **void findArticulationPoints(Graph* g)**:
   - Initializes required arrays and invokes the DFS utility function to find articulation points.
   - Prints the identified articulation points.

## Main Function

- Prompts the user for the number of vertices and edges.
- Collects edge inputs from the user.
- Calls `findArticulationPoints` to determine and display the articulation points in the graph.

## Time Complexity

- The algorithm runs in \(O(V + E)\), where \(V\) is the number of vertices and \(E\) is the number of edges in the graph.

## Usage

1. Compile the program using a C compiler (e.g., `gcc articulation_points.c -o articulation_points`).
2. Run the program (`./articulation_points`).
3. Follow the prompts to enter the number of vertices and edges, and then enter the edges.
4. The program will output the articulation points.

## Example

### Input:
Enter the number of vertices: 5
Enter the number of edges: 5
Enter edges (u v) format:
0 1
0 2
1 2
1 3
3 4

### Output:

Articulation points in the graph are: 1 3 


