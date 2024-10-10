
# Job Assignment Problem

## Description  
The Job Assignment Problem aims to assign a set of jobs to a set of workers in such a way that the total cost of the assignments is minimized. Each worker can perform each job at a specific cost, and the goal is to assign exactly one job to each worker while minimizing the overall cost.

## Problem Definition  
**Given:**

- A cost matrix representing the cost for each worker to perform each job, where the element at the ith row and jth column represents the cost for worker i to complete job j.

**Objective:**

- Assign jobs to workers such that each worker is assigned exactly one job, and each job is assigned to exactly one worker, minimizing the total assignment cost.

## Algorithm Overview  
The Branch and Bound approach is utilized to solve the Job Assignment Problem. This method systematically explores the solution space by creating a tree of all possible assignments and calculating the lower bound cost for each node. Nodes that cannot yield a better solution than the current best are pruned, reducing the search space.

## Steps:
1. Create a root node representing no jobs assigned and no costs incurred.
2. For each worker, explore the unassigned jobs and create child nodes for each assignment.
3. Calculate the total path cost and the estimated cost for each child node.
4. Use a priority queue to select the node with the least cost for further exploration.
5. If a node represents a complete assignment (all workers assigned), check if it's better than the current best solution and update accordingly.
6. Continue exploring until all nodes are processed.

## Functions:
- **createNode()**: Creates a new node representing a specific job assignment state.
- **calculateCost()**: Computes the minimum cost for remaining unassigned jobs.
- **printAssignments()**: Displays the final assignments of workers to jobs.
- **findMinCost()**: Executes the Branch and Bound algorithm to determine the optimal assignment.

## Time Complexity  
The time complexity of the Branch and Bound algorithm for the Job Assignment Problem can vary based on the specific implementation and problem instance. In the worst case, it can be exponential, O(N!), due to the permutations of assignments. However, pruning non-promising branches significantly reduces the average case complexity, making it feasible for reasonably sized problems (e.g., N up to 10 or 12).

---
