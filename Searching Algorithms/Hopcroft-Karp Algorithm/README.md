### Hopcroft-Karp Algorithm (Maximum Bipartite Matching)
This C program demonstrates the implementation of the Hopcroft-Karp algorithm for finding the maximum matching in a bipartite graph. The algorithm operates efficiently with a time complexity of O(E * sqrt(V)), where E is the number of edges and V is the number of vertices in the graph.

The Hopcroft-Karp algorithm is a classical algorithm used in graph theory, particularly in matching problems, such as scheduling, resource allocation, and network flows. It works by finding augmenting paths to improve the current matching until no further improvements can be made.

### Key Operations:
- **BFS (Breadth-First Search):** Identifies augmenting paths in the bipartite graph to potentially increase the size of the matching.
- **DFS (Depth-First Search):** Attempts to extend the augmenting paths found by BFS, updating the matching if possible.
- **Matching:** The program builds and maintains a matching set where each element in one set of vertices (U) is paired with an element in the other set (V), ensuring no vertex is matched more than once.
### Sample Input and Output 
Consider a bipartite graph with 3 vertices on each side. The adjacency matrix defines edges between the two sets of vertices (U and V).

Sample adjacency matrix:
U1 -- V1 U1 -- V2 U2 -- V2 U2 -- V3 U3 -- V3


**Program Output:**


This output indicates that the algorithm found 3 matchings, covering all vertices.

## Example:
1. **Define edges in the bipartite graph:**
   - U1 is connected to V1 and V2.
   - U2 is connected to V2 and V3.
   - U3 is connected to V3.

2. **Algorithm Execution:**
   - The algorithm first uses BFS to find potential augmenting paths, then uses DFS to update the matchings based on the identified paths.
   - After processing, the algorithm reports the maximum possible matching.

## Time Complexity:
- **BFS (Augmenting Path Search):** Each BFS execution takes **O(E)** time, where **E** is the number of edges.
- **DFS (Path Augmentation):** DFS is called repeatedly for each vertex and takes **O(V)** time per call, where **V** is the number of vertices.
- **Overall Complexity:** The algorithm runs in **O(E * sqrt(V))**, making it efficient for large bipartite graphs.

## Key Features:
- **Efficient Matching:** The Hopcroft-Karp algorithm significantly improves upon brute-force methods for bipartite matching by combining BFS and DFS.
- **Graph Representation:** The graph is represented using an adjacency matrix, which is a simple yet effective way to handle graph data in this context.
- **Dynamic Matching:** The algorithm builds the matching dynamically, ensuring that each new matching is either an improvement or equivalent to the previous one.

## Applications:
- **Network Flow:** The algorithm is commonly used in network flow problems where resources need to be allocated between two distinct sets.
- **Scheduling:** Assigning tasks (U) to resources (V) where each task can only be matched with compatible resources.
- **Resource Allocation:** Efficiently matching users to available services or resources without overlap.




