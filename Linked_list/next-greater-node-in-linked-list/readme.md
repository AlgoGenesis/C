# Next Greater Node in Linked List

## Problem Statement

Given the head of a linked list with `n` nodes, find the value of the next node that is strictly greater for each node in the list. If no such node exists, return `0` for that position.

Return an integer array `answer` where `answer[i]` is the value of the next greater node of the `i`th node (1-indexed). 

### Example

**Input:**
head = `[2,1,5]`

**Output:**
`[5,5,0]`


### Constraints
- The linked list can have up to `10^4` nodes.
- Each node contains a non-negative integer value.

## Approach

To solve this problem:
1. **Convert the Linked List to an Array**: Traverse the linked list and store each node’s value in an array. This allows easy access by index.
2. **Use a Stack to Track Indices of Nodes Waiting for a "Next Greater"**:
   - Traverse the `values` array and maintain a stack of indices for which we haven't yet found a next greater value.
   - For each element in `values`, check if it is greater than the elements at indices stored in the stack:
     - If so, pop indices from the stack and set the `result` array for each index to this value.
   - Push the current index to the stack if it doesn't have a greater element in the remainder of the array.
3. **Return the Result Array**: After processing all elements, the `result` array contains the next greater values or `0` for nodes that have no greater value ahead.

### Complexity
- **Time Complexity**: `O(n)`, where `n` is the number of nodes, as each node is processed once.
- **Space Complexity**: `O(n)`, for storing values in the array and using the stack.

## Code Explanation

### Functions

1. **createNode**: Creates a new linked list node.
2. **addNode**: Appends a node to the end of the linked list.
3. **linkedListToArray**: Converts the linked list to an array of values.
4. **nextLargerNodes**: The core function that computes the next greater node values.
   - Initializes a result array `result` filled with `0`s.
   - Uses a stack to keep track of indices where the next greater node has not been found.
   - For each node value, checks if it’s greater than the values at indices stored in the stack. If so, it updates the result array for each index.
5. **printArray**: Prints the result array.
