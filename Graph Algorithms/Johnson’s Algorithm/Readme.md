# Johnson’s Algorithm

## Description

This program implements **Johnson's Algorithm** to find the shortest paths between all pairs of vertices in a weighted graph. It can handle graphs with negative weight edges, provided there are no negative weight cycles.

## Data Structures

1. **Edge**:
   - A structure to represent a directed edge in the graph.

   Members:
   - `int u`: The starting vertex of the edge.
   - `int v`: The ending vertex of the edge.
   - `int weight`: The weight of the edge.

## Functions

1. **void addEdge(Edge edges[], int *edgeCount, int u, int v, int weight)**:
   - Adds an edge to the graph.

2. **int bellmanFord(Edge edges[], int edgeCount, int V, int src)**:
   - Implements the Bellman-Ford algorithm to find the shortest paths from a source vertex.
   - Returns `1` if successful; `0` if a negative weight cycle is detected.

3. **void johnsonsAlgorithm(int V, Edge edges[], int edgeCount)**:
   - Implements Johnson's algorithm to compute shortest paths between all pairs of vertices.

## Main Function

### Details:

- Prompts the user to enter the number of vertices and the edges of the graph.
- Calls the `johnsonsAlgorithm` function to compute the shortest paths.
- Outputs the shortest path distances between all pairs of vertices.

## Time Complexity

- The algorithm runs in \(O(V^2 \log V + VE)\) time, where \(V\) is the number of vertices and \(E\) is the number of edges.

## Usage

1. Compile the program using a C compiler (e.g., `gcc johnsons_algorithm.c -o johnsons_algorithm`).
2. Run the program (`./johnsons_algorithm`).
3. Follow the prompts to enter the number of vertices and the edges of the graph.
4. The program will output the shortest path distances between all pairs of vertices.

## Example

### Input:

Enter number of vertices: 4
Enter the edges (u v weight), enter -1 -1 -1 to stop:
0 1 1
0 2 4
1 2 -3
1 3 2
2 3 1
-1 -1 -1

### Output:

Shortest path distances between all pairs of vertices:
0	1	-2	-1	
INF	0	-3	-2	
INF	INF	0	1	
INF	INF	INF	0	

