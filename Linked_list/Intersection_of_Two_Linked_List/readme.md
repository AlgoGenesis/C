# Intersection of Two Linked Lists

## Problem Statement

Given the heads of two singly linked-lists, `headA` and `headB`, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return `NULL`.

### Example

**Input**:
- `listA = [4,1,8,4,5]`
- `listB = [5,6,1,8,4,5]`

**Output**:
- `Intersected at '8'`

**Explanation**:
- Both lists intersect at the node with value `8`.

### Constraints
- Each linked list is non-cyclical.
- The intersection, if it exists, is a reference to a node, not a new node with the same value.

## Approach

### Two-Pointer Technique

1. **Set up two pointers,** `ptrA` starting at the head of `listA` and `ptrB` starting at the head of `listB`.
2. **Traverse the lists**:
   - If a pointer reaches the end of one list, redirect it to the head of the other list.
   - Continue moving both pointers forward one node at a time until they meet.
3. **Why This Works**:
   - When the lists intersect, both pointers will meet at the intersection node after traversing the combined length of both lists.
   - If they don’t intersect, both pointers will eventually reach `NULL` at the same time.

This method is efficient with a time complexity of `O(m + n)`, where `m` and `n` are the lengths of `listA` and `listB`. It also has `O(1)` space complexity as it modifies the list in place without additional data structures.