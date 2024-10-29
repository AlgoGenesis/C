# Clone a Linked List with Random Pointers

## Problem Statement

Given a linked list where each node contains:
- An integer `val`.
- A `next` pointer to the next node in the list.
- A `random` pointer that points to any node in the list or is `NULL`.

The task is to **create a deep copy (clone) of this linked list**. The cloned list should have the same values, `next`, and `random` pointer connections as the original list but should not share any nodes with it.

## Example

Consider a linked list where:
- Node values: `[1, 2, 3, 4, 5]`
- Random pointers map as follows:
  - `1`'s random points to `3`
  - `2`'s random points to `5`
  - `3` has no random pointer (`NULL`)
  - `4`'s random points to `1`
  - `5`'s random points to `2`

The structure of both the original and cloned list should look like this:

Original list: 1 -> 2 -> 3 -> 4 -> 5 | | | ↓ ↓ ↓ 3 5 1

Cloned list: 1' -> 2' -> 3' -> 4' -> 5' | | | ↓ ↓ ↓ 3' 5' 1'

## Solution

This solution uses an array to map nodes from the original list to their corresponding cloned nodes. The approach involves two main passes through the list:

1. **Initialize a Mapping Array:** 
- Allocate an array of pointers nodeMap to store mappings of each node’s value in the original list to the cloned node with the same value.
- The array size is set to 100 for simplicity. This should be adjusted based on expected node values or made dynamically allocated for general use.
2. **First Pass - Clone All Nodes:** 
- Traverse the original list, and for each node, create a new node with the same val and store it in nodeMap at the index of the original node’s value. At this stage, only the val is copied, not the next or random pointers.

3. **Second Pass - Set next and random Pointers:**

- Traverse the original list again. For each node:
   - Use nodeMap to set the next pointer of the cloned node based on the next pointer of the original node.
   - Use nodeMap to set the random pointer of the cloned node based on the random pointer of the original node.

4. **Return the Head of the Cloned List:**
- Return the cloned head from nodeMap that corresponds to the head of the original list.

5. **Freeing Memory:**
- After cloning, both the original and cloned lists are freed to prevent memory leaks.

**Explanation of Complexity**
- Time Complexity: 
O(n), where n is the number of nodes in the list. We traverse the list twice.

- Space Complexity:
  O(n), due to the use of the hash map to store mappings from original to cloned nodes.

