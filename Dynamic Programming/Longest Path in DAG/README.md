# Longest Path in DAG
## Definition:
This program finds the longest path from a given source vertex in a Directed Acyclic Graph (DAG) with weighted edges. It accomplishes this by performing a topological sort on the vertices and then using dynamic programming to calculate the longest path distances. 

## Problem Statement:
Given a weighted directed acyclic graph (DAG) and a source vertex, find the cost of the longest path from the source vertex to all other vertices present in the graph. If the vertex can’t be reached from the given source vertex, print its distance as infinity.

## Algorithm to Find the Longest Path in a Directed Acyclic Graph (DAG)

1. **Topological Sort**  
   Perform a topological sort of the DAG. This will allow us to process each vertex in a linear order, ensuring that each vertex is processed after all its dependencies.

2. **Initialize Distances**  
   Create a distance array to store the longest path distances from the source. Set the distance of the source vertex to 0 and all other vertices to negative infinity (`-∞`), representing unvisited vertices.

3. **Process Vertices in Topological Order**  
   For each vertex in the topologically sorted order:
   - If the vertex has been visited (its distance is not `-∞`), update the distances of its adjacent vertices.
   - For each adjacent vertex, calculate the potential new distance, and if it's greater than the current distance, update it.

4. **Update Distances of Adjacent Vertices**  
   For each adjacent vertex of the current vertex, calculate the longest path distance from the source. If this new distance is greater than the current distance of the adjacent vertex, update it.

5. **Output the Longest Path Distances**  
   Print the longest distance to each vertex from the source. If a vertex's distance remains `-∞`, it means the vertex is unreachable from the source.

## Time Complexity:
- The time complexity of this program is `O(V + E)`, where `V` is the number of vertices and `E` is the number of edges. This is achieved by first performing a topological sort using Depth-First Search (DFS), which takes `O(V + E)` time, and then processing each vertex in topological order to update the distances of its adjacent vertices, also in `O(V + E)` time.

## Example

### Sample Input:
```
addEdge(adj, 0, 1, 3);                          
addEdge(adj, 0, 2, 10);                      
addEdge(adj, 0, 3, 14);                                     
addEdge(adj, 1, 3, 7);                      
addEdge(adj, 1, 4, 51);                                    
addEdge(adj, 2, 3, 5);                          
addEdge(adj, 3, 4, 11);                                                                                        
```
### Sample Output:
```
Longest distances from source vertex 0:                                 
Vertex 0 - Distance: 0                       
Vertex 1 - Distance: 3                                         
Vertex 2 - Distance: 10                  
Vertex 3 - Distance: 15                            
Vertex 4 - Distance: 54                          
```
### Explanation of Sample:
![DAG](https://github.com/user-attachments/assets/4e3f9cd9-e56a-461d-b824-5e8889b54eb7)

The maximum distance from the source node 0 to each node is as follows:

- **Node 0**: The maximum distance from node 0 to itself is 0.  
  _(The distance of a node from itself is always 0)._

- **Node 1**: The maximum distance from node 0 to node 1 is 3, achieved via the path `0 -> 1`.

- **Node 2**: The maximum distance from node 0 to node 2 is 10, achieved via the path `0 -> 2`.

- **Node 3**: The maximum distance from node 0 to node 3 is 15, achieved via the path `0 -> 2 -> 3`.

- **Node 4**: The maximum distance from node 0 to node 4 is 54, achieved via the path `0 -> 1 -> 4`.

Thus, we should print the distances in order as follows: **0 3 10 15 54**.
