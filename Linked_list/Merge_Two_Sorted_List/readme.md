# Merge Two Sorted Linked Lists

## Problem Statement

Given the heads of two sorted singly linked lists, `list1` and `list2`, merge the two lists into one sorted linked list. The list should be made by splicing together the nodes of the first two lists. Return the head of the merged linked list.

### Example

**Input:**
- `list1 = [1, 2, 4]`
- `list2 = [1, 3, 4]`

**Output:**
- `Merged List = [1, 1, 2, 3, 4, 4]`

### Constraints
- Both input linked lists are sorted in non-decreasing order.
- The input lists can be of different lengths, including cases where one list is empty.

## Approach

### Step-by-step Explanation

1. **Create a Dummy Node**:
   - To simplify the merging process, we create a dummy node. This node acts as a placeholder to make list manipulation easier.
   - A pointer (`current`) is initialized to point to this dummy node.

2. **Traverse Both Lists**:
   - We compare the values of the nodes in both lists. 
   - At each step, we append the smaller node to the `current` node and move the corresponding list pointer (either `list1` or `list2`) forward to the next node.
   
3. **Handle Remaining Nodes**:
   - After one list is exhausted, the other list may still have remaining nodes. We simply append the rest of the nodes from the non-empty list to the merged list.

4. **Return the Merged List**:
   - The `dummy` node is a placeholder, so we return the node next to `dummy`, which is the head of the merged list.

