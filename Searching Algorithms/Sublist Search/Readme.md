# Sublist Search

## Description

Sublist Search is an algorithm used to determine whether a given linked list (pattern) appears as a sublist in another larger linked list (main list). This problem is useful in various applications, including data structures and pattern matching within linked data structures.

### Problem Definition

Given:
- A **main list** (larger linked list).
- A **pattern list** (smaller linked list to be searched within the main list).

Objective:
- Determine if the **pattern list** appears as a contiguous sublist in the **main list**. If found, return the starting node of the sublist in the main list; otherwise, return `null`.

### Algorithm Overview

1. **Initialization**:
   - Traverse the **main list** with a pointer.
   - At each node of the **main list**, attempt to match the **pattern list**.

2. **Matching Process**:
   - For each node in the **main list**:
     - Compare the current node and its next nodes with the nodes of the **pattern list**.
     - If all nodes of the **pattern list** match consecutively with nodes in the **main list**, return the starting node of the sublist.

3. **Continue** until the **main list** is fully traversed, or a match is found.

4. **Return**:
   - If the pattern list is found, return the starting node of the sublist.
   - If no match is found, return `null`.

### Time Complexity

The time complexity of Sublist Search is 𝑂(𝑛⋅𝑚), where:
- 𝑛 is the number of nodes in the **main list**.
- 𝑚 is the number of nodes in the **pattern list**.

In the worst case, we have to compare the **pattern list** with every possible starting node in the **main list**, leading to this time complexity.
