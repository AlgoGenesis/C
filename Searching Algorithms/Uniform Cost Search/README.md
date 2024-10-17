### Uniform Cost Search (UCS) Implementation in C

#### Description
This project implements the **Uniform Cost Search (UCS)** algorithm in C, which is a type of search algorithm used in pathfinding and graph traversal. UCS explores paths in increasing order of cost, ensuring that the first time a goal state is reached, it is through the least costly path. It is similar to Dijkstra's algorithm and is particularly useful when the cost of traveling between nodes is not uniform.

The algorithm uses a **priority queue** to always expand the least-cost node first, making it an optimal and complete algorithm for finding the minimum-cost path to a goal state. The graph is represented using **adjacency lists**, and each edge between nodes is associated with a specific cost.

The implementation allows you to specify multiple goal states, though it returns the cost of reaching any one of them from a given starting point.

#### Features
- Finds the minimum-cost path between the starting node and one or more goal nodes.
- Handles graphs represented as adjacency lists.
- Uses a binary heap-based priority queue to manage node expansion based on cumulative path cost.
- Supports multiple goal states.
- Efficiently handles edge weights and varying costs.

#### Complexity
- **Time complexity:** The time complexity of the UCS algorithm is \(O((V + E) \log V)\), where \(V\) is the number of vertices (nodes) and \(E\) is the number of edges in the graph. This comes from expanding each node (in the worst case, all nodes are expanded) and performing priority queue operations, which take logarithmic time.
  
- **Space complexity:** The space complexity is \(O(V)\), where \(V\) is the number of nodes. This is because we store the visited status, the adjacency list, and priority queue entries for each node.

#### Usage
1. **Compile the program:**
   ```bash
   gcc uniform_cost_search.c -o uniform_cost_search
   ```

2. **Run the program:**
   ```bash
   ./uniform_cost_search
   ```

3. **Input/Output:**
   - The program has a hardcoded graph, where nodes are connected by edges with specified costs.
   - It will print the minimum cost from the starting node (0) to the goal node (6).
   
   Example output:
   ```
   Minimum cost from 0 to 6 is = 3
   ```

#### Limitations
- The current implementation assumes a **static graph** structure. If the graph needs to be dynamically updated (i.e., adding or removing edges or nodes), additional functions would be required.
- The program assumes that node identifiers are integer values starting from 0 up to \(N-1\). It can be expanded to handle more flexible representations of nodes (e.g., strings).
- This implementation uses an adjacency list, which is efficient for sparse graphs. For dense graphs, other representations like adjacency matrices might be more suitable.

