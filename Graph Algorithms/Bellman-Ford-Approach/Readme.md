# Bellman-Ford Algorithm Implementation

## Description
This C program implements the Bellman-Ford algorithm, which is used for finding the shortest paths from a single source vertex to all other vertices in a weighted graph. The algorithm can handle graphs with negative weight edges and detects negative weight cycles.

## Approach
1. **Initialization**: The algorithm starts by initializing the distance to the source vertex as `0` and all other vertices as infinity.
2. **Relaxation**: For a total of |V| - 1 iterations (where |V| is the number of vertices), it relaxes all the edges. This means that if the current known distance to a vertex can be improved by taking a specific edge, it updates the distance.
3. **Cycle Detection**: After the relaxation process, the algorithm checks for negative weight cycles by performing one more iteration over all edges. If any distance can still be updated, it indicates a negative weight cycle in the graph.

## Time Complexity
The time complexity of the Bellman-Ford algorithm is O(V * E), where V is the number of vertices and E is the number of edges. This is because it performs a relaxation process for each edge |V| - 1 times.

## Space Complexity
The space complexity is O(V) due to the distance array that holds the shortest distance from the source to each vertex.

## Applications
- Finding the shortest path in graphs with negative weights.
- Detecting negative weight cycles.
- Used in network routing protocols like RIP (Routing Information Protocol).
- Useful in various applications like currency arbitrage detection in finance.

## Differences Between the Bellman-Ford Algorithm and Alternative Implementations

1. **Dynamic Memory Allocation**:
   - **Original Code**: Uses fixed-size arrays for the `distance` and `edges` structures.
   - **Alternative Code**: Utilizes dynamic memory allocation (`malloc`) for the `distance` array and the `edges` array, allowing for more flexibility.

2. **Modularity**:
   - **Original Code**: Directly uses global constants for the number of vertices.
   - **Alternative Code**: Introduces parameters for the number of vertices (`vertexCount`) and edges (`edgeCount`), enhancing modularity.

3. **Memory Management**:
   - **Original Code**: Does not free any allocated memory since it uses stack-allocated arrays.
   - **Alternative Code**: Includes memory management with `free()` to prevent memory leaks.

4. **Edge Initialization**:
   - **Original Code**: Edges are defined directly in an array.
   - **Alternative Code**: Uses dynamic allocation to create the `edges` array, allowing for easier modifications and scalability.

5. **Loop Constructs**:
   - **Original Code**: The for-loop for edge relaxation runs from 1 to |V| - 1.
   - **Alternative Code**: The loop runs from 1 to |V|, explicitly indicating that it iterates |V| - 1 times for relaxation.

These changes aim to improve code clarity, flexibility, and efficiency, making the alternative implementation more robust for varying applications.
