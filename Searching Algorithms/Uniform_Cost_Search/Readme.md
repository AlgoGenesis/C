Overview
Uniform Cost Search (UCS) is a search algorithm used to find the path with the lowest cumulative cost in a weighted graph. UCS is an optimal search technique, meaning it guarantees finding the least costly path to a target node if one exists. It is widely used in pathfinding applications where various costs are associated with different paths or edges, making it ideal for scenarios that require efficient and cost-sensitive decision-making.
UCS operates by expanding the least costly node at each step, ensuring that paths with lower cumulative costs are always explored before more expensive paths. This makes it particularly useful for applications like network routing, AI pathfinding, and resource management, where minimizing cost is critical.
The Uniform Cost Search (UCS) algorithm is a classic pathfinding algorithm used in graph theory and computer science to determine the least-cost path between nodes in a weighted graph. Unlike basic search algorithms like Depth-First or Breadth-First Search, UCS accounts for different costs on edges, making it ideal for situations where the goal is to minimize some form of expense, like distance, time, or resource usage. UCS works by exploring paths incrementally, always expanding the path with the smallest cumulative cost. This is achieved using a priority queue (often a min-heap), which orders nodes by their path cost. Starting from a source node, UCS initially assigns a cost of zero to the start and infinity (or a large number) to all other nodes, marking them as unreachable at first. At each step, the algorithm dequeues the node with the lowest cost from the priority queue, checks if it is the target, and if so, halts—since the minimum-cost path to the goal has been found. If it’s not the goal, UCS proceeds to explore all adjacent nodes, updating their path costs as needed. If a new, lower cost is found to reach a neighboring node, the algorithm updates the node’s cost and pushes it back into the queue for further exploration. This iterative process continues until UCS finds the least-cost path to the target or exhausts all possible nodes. Uniform Cost Search is both optimal and complete in graphs with non-negative weights, meaning it will find the most cost-effective path if one exists. Due to this, UCS is widely used in various applications, such as route planning, network routing, robotics, and decision-making problems in artificial intelligence. It’s particularly effective for scenarios where various costs are associated with different paths, enabling systems to make intelligent, cost-sensitive decisions. Although UCS shares similarities with Dijkstra's algorithm, as both prioritize paths based on cumulative costs, UCS is specifically goal-oriented and can terminate as soon as the least-cost path to the target is identified, making it efficient for single-source, single-destination searches.
How UCS Works
UCS starts from a designated source node and explores paths incrementally, using a priority queue to always expand the path with the least cumulative cost. This priority-based approach ensures that UCS evaluates paths in order of increasing cost, leading to optimal solutions.
Key points about the Uniform Cost Search (UCS) Algorithm:

Purpose: UCS is used to find the least-cost path from a start node to a goal node in a weighted graph.

Optimality: UCS is optimal, meaning it guarantees finding the path with the minimum cumulative cost to the goal if one exists.

Completeness: UCS is complete, ensuring it will find a solution in a finite graph with non-negative weights if a path exists.

Priority-Based Expansion: UCS uses a priority queue (often implemented as a min-heap) to expand nodes in order of their cumulative path cost, always choosing the least-cost path first.

Cost Calculation: At each step, UCS updates the cost of reaching each neighboring node. If a cheaper path is found, the cost is updated, and the node is re-enqueued with the new cost.

Goal-Oriented: UCS can terminate as soon as it finds the minimum-cost path to the specified goal, making it efficient for single-source, single-target searches.

Comparison with Dijkstra’s Algorithm: While similar to Dijkstra’s algorithm, UCS specifically aims to find the shortest path to a single goal node rather than all nodes.

Applications: Commonly used in pathfinding, network routing, robotics, and AI decision-making where minimizing cost (e.g., time, distance) is crucial.

Non-Negative Edge Requirement: UCS requires all edge weights to be non-negative, as negative weights would interfere with accurate cost-based path expansion.

Performance: UCS can be computationally intensive on large graphs, especially when the priority queue operations are not optimized. Its efficiency largely depends on the priority queue implementation.
This C code implements the Uniform Cost Search (UCS) algorithm to find the minimum-cost path between two nodes in a weighted graph using an adjacency matrix to represent graph edges, where each entry indicates the cost (or weight) of the edge between two nodes and a cost of zero represents no direct connection. The UCS algorithm operates by maintaining a priority queue, implemented here with a simple array ordered by cumulative path cost, to ensure the least-costly node is processed next at each step. The code defines a custom priority queue structure and provides functions for initializing, pushing nodes with their costs, popping nodes in ascending order of cost, and checking if the queue is empty. The graph is represented as a matrix, where `graph[i][j]` holds the cost of moving from node `i` to node `j`. The main UCS function initializes all nodes' path costs to infinity (representing unreached nodes) and sets the start node cost to zero. It then continuously pops nodes from the priority queue, examining and updating the path costs to each unvisited neighboring node if a less costly path is found. When the target node is reached, the algorithm prints the minimum-cost path or, if no path is available, informs the user accordingly. The main program prompts for the number of nodes, edges, and details of each edge, including start node, end node, and cost; it also asks for start and goal nodes, then runs the UCS function to find the minimum-cost path. This code illustrates how UCS can efficiently identify the least-costly path in a graph, useful in applications like network routing, logistics, and AI pathfinding where minimizing some form of cost—such as distance or time—is crucial.







