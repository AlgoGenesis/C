The Edmonds-Karp algorithm solves the maximum flow problem for a directed graph. The flow comes from a source vertex and ends up in a sink vertex, and each edge in the graph allows a flow, limited by a capacity.The Edmonds-Karp algorithm uses Breadth First Search (BFS) to find augmented paths to increase flow.

The Edmonds-Karp Function:
Uses BFS repeatedly to find all augmenting paths. 
For each path,calculates the maximum flow possible and updates the residual graph.
Accumulates the total flow as the result.

Sample Input/Output:
Enter the number of vertices: 4 
Enter the number of edges: 5 
Enter each edge in the format 'u v capacity' (0-indexed): 
0 1 10 
0 2 5 
1 2 15 
1 3 10 
2 3 10 
Enter source vertex: 0 
Enter sink vertex: 3
The maximum possible flow is 15