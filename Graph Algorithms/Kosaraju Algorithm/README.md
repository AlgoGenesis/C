# Kosaraju's Algorithm for Strongly Connected Components (SCCs)

## Description:
Kosaraju's Algorithm is an efficient method for finding all **strongly connected components (SCCs)** in a **directed graph**. An SCC is a maximal subgraph where every pair of vertices is mutually reachable (i.e., there is a path between any two vertices in both directions).

This algorithm uses **two passes of depth-first search (DFS)** and runs in **O(V + E)** time, where `V` is the number of vertices and `E` is the number of edges in the graph.


## Applications of Kosaraju's algorithm
1. Computer science - Kosaraju's algorithm can be used to find a solution to the Strongly.

2. Connected Components Problem, also known as the Connected Components Problem.
Used to obtain the Dulmage–Mendelsohn decomposition, a bipartite graph edges classification method.

3. Used in social networks to discover groups of strongly connected people and make recommendations based on shared interests.

#### **Steps of Kosaraju's Algorithm:**

1. **Perform DFS on the original graph to determine the order of finishing times:**
   - Traverse the graph using DFS and store vertices in a stack according to their finishing times (i.e., when their DFS call is complete). Vertices that finish later will be processed first in the next step.
   
2. **Reverse the graph:**
   - Create a **transpose graph** (reverse the direction of all edges in the graph).
   
3. **Perform DFS on the transposed graph in the order defined by the stack:**
   - Pop vertices from the stack and perform DFS on the reversed graph. Each DFS call in this step will give you one SCC.

#### **Pseudocode:**

1. **First DFS pass (on original graph):**
   - Traverse the graph and push each vertex onto a stack after its DFS is complete.

2. **Transpose the graph:**
   - Reverse the edges of the graph.

3. **Second DFS pass (on transposed graph):**
   - Pop vertices from the stack one by one and run DFS again on the transposed graph. Each DFS traversal will output a strongly connected component.

