# Knapsack Problem Solver using Branch and Bound

## Description
The **Knapsack Problem Solver** is an algorithm that uses the Branch and Bound technique to solve the 0/1 Knapsack problem. The goal is to maximize the total value of items placed in a knapsack without exceeding its weight capacity. Each item has a specific weight and value, and we must decide whether to include or exclude each item while optimizing the total profit.

## Problem Definition
**Given**:
- A set of `n` items, each with a specific weight and value.
- A knapsack with a weight capacity `W`.

**Objective**:
Maximize the total value of items placed in the knapsack while ensuring that the total weight does not exceed the knapsack's capacity.

## Algorithm Overview
The **Branch and Bound** approach is used to systematically explore all possibilities (including or excluding each item) in a decision tree. Each node in the tree represents a decision, and an upper bound on the potential profit is calculated to prune branches that cannot produce a better solution than the current best.

### Steps:
1. **Sort items**: Sort the items based on their value-to-weight ratio in descending order for optimal selection.
2. **Decision Tree Exploration**:
   - Begin with a root node (no items selected).
   - For each level, branch into two paths: one including the current item and one excluding it.
   - For each node, calculate the total weight and profit, and compute the upper bound of profit for the subtree rooted at that node.
   - If the bound is less than the current maximum profit, prune the branch.
3. **Backtrack**: If a branch leads to an infeasible solution (weight exceeds capacity), backtrack and explore alternative branches.

## Functions:
- **`bound(Node u, int n, int W, Item arr[])`**: Computes the upper bound on the maximum profit for a given node using a greedy approach.
- **`knapsack(int W, Item arr[], int n)`**: Implements the Branch and Bound algorithm, exploring possible item selections and updating the maximum profit.
- **`cmp(const void *a, const void *b)`**: Sorts items by value-to-weight ratio.

## Time Complexity
The time complexity of solving the knapsack problem using the Branch and Bound method depends on the size of the decision tree, which can have a maximum of `2^n` nodes (since each item can either be included or excluded). However, pruning through bounds reduces the effective number of nodes, making it more efficient than a brute-force approach.

The upper bound calculation uses a greedy method that runs in **O(n)** for each node. Sorting the items initially takes **O(n log n)**, contributing to the overall complexity.
