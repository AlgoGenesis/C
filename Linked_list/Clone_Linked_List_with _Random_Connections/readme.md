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

We can solve this problem using an `unordered_map` to map nodes in the original list to nodes in the cloned list. This approach involves two main steps:
1. **Clone Each Node** (without setting `next` and `random` pointers yet).
2. **Assign `next` and `random` Pointers** to cloned nodes based on the structure of the original list.

### Steps of the Solution

1. **Create a HashMap (`unordered_map`)**:
   - Use a `unordered_map` to map each original node to its clone. This way, we can easily find the corresponding cloned node for any original node.

2. **First Pass** - Clone All Nodes:
   - Traverse the original list and, for each node, create a clone with only the `val` attribute copied (without setting `next` or `random` pointers yet). Store each cloned node in the map with the original node as the key.

3. **Second Pass** - Set `next` and `random` Pointers:
   - Traverse the original list again. For each original node, use the map to set the `next` and `random` pointers of the corresponding cloned node.

4. **Return the Head of the Cloned List**:
   - The head of the cloned list is the cloned node mapped to the head of the original list.


**Explanation of Complexity**
- Time Complexity: 
O(n), where n is the number of nodes in the list. We traverse the list twice.

- Space Complexity:
  O(n), due to the use of the hash map to store mappings from original to cloned nodes.

