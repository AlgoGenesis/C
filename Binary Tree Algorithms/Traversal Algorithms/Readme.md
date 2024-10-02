# Binary Tree Traversal Algorithms

This project demonstrates four common ways to traverse a binary tree: **In-order**, **Pre-order**, **Post-order**, and **Level-order**. Each traversal method visits the nodes of the tree in a different order, which can be useful for various operations like searching, sorting, or processing tree structures.

## What is a Binary Tree?

A **binary tree** is a tree data structure where each node has at most two children: a left child and a right child. Traversal means visiting every node in the tree exactly once.

## Tree Traversal Methods

### 1. In-order Traversal (Left -> Root -> Right)
**How it works**:
- Visit the left subtree first.
- Visit the root (current node).
- Visit the right subtree.

**Use case**: This is useful in **Binary Search Trees (BSTs)** to get nodes in ascending order.

**Example**:


<pre>  2 
 / \ 
1   3 </pre>
In-order traversal of this tree will print: `1, 2, 3`.

---

### 2. Pre-order Traversal (Root -> Left -> Right)
**How it works**:
- Visit the root (current node) first.
- Visit the left subtree.
- Visit the right subtree.

**Use case**: Pre-order is useful for copying the tree or evaluating prefix expressions.

**Example**:


<pre>  2 
 / \ 
1   3 </pre>
Pre-order traversal will print: `2, 1, 3`.

---

### 3. Post-order Traversal (Left -> Right -> Root)
**How it works**:
- Visit the left subtree.
- Visit the right subtree.
- Visit the root (current node) last.

**Use case**: Post-order is used to delete the tree or evaluate postfix expressions.

**Example**:


<pre>  2 
 / \ 
1   3 </pre>
Post-order traversal will print: `1, 3, 2`.

---

### 4. Level-order Traversal (Breadth-First Search)
**How it works**:
- Visit all nodes level by level from left to right.

**Use case**: Level-order traversal is useful for finding the shortest path or processing nodes level by level.

**Example**:


<pre>  2 
 / \ 
1   3 </pre>
Level-order traversal will print: `2, 1, 3`.

---

## Applications

- **In-order Traversal**: Used to retrieve data in sorted order from a binary search tree.
- **Pre-order Traversal**: Useful for creating a copy of a tree or converting a tree into a prefix notation expression.
- **Post-order Traversal**: Often used for deleting nodes in a tree.
- **Level-order Traversal**: Used in algorithms like breadth-first search (BFS), finding the shortest path in a tree, or implementing algorithms that require processing nodes level by level.

---

You can modify the tree structure in the code to see how different traversals work with different trees.
