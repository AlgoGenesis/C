# Dijkstra's Algorithm

Dijkstra's Algorithm is a popular algorithm used for finding the shortest paths between nodes in a graph, which may represent, for example, road networks. 

## Description

The algorithm works by maintaining a set of nodes whose shortest distance from the source is known, and repeatedly selecting the node with the smallest known distance, updating the distances of its neighbors. It is particularly efficient for sparse graphs.

## How It Works

1. **Initialization**: Set the distance to the source node to 0 and all other nodes to infinity. Mark all nodes as unvisited.
2. **Selection**: Select the unvisited node with the smallest known distance and mark it as visited.
3. **Update**: For the current node, update the distances of its neighbors. If the new calculated distance is less than the known distance, update it.
4. **Repeat**: Repeat steps 2 and 3 until all nodes have been visited.

## Time Complexity

- The time complexity of Dijkstra's Algorithm using a priority queue (min-heap) is **O((V + E) log V)**, where:
  - **V** is the number of vertices (nodes).
  - **E** is the number of edges.

## Space Complexity

- The space complexity is **O(V)**, which accounts for storing the distance of each vertex and the priority queue.

## Applications

Dijkstra's Algorithm is widely used in various applications, including:
- Navigation systems (GPS)
- Network routing protocols
- Flight scheduling
- Game development for pathfinding


