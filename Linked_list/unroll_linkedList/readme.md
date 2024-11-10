# **UNROLLED LINKED LIST**
An **Unrolled Linked List** is a variation of a linked list where each node contains an array of elements rather than a single element. This setup reduces the number of nodes and can improve cache performance, especially for applications with high memory allocation or traversal requirements.

Here’s how an **Unrolled Linked List** is typically structured:
- Each node has an array of elements.
- Each node maintains the count of elements it currently holds.
- When an array (node) is full, it splits into two nodes, maintaining balance.

This structure is especially useful in memory-intensive applications or those that frequently iterate over list elements, like graphics rendering.

### Explanation of Code:

1. **Node Structure (`UnrolledNode`)**: Each node has a fixed-size array (`elements`) to hold multiple elements and a `count` to keep track of the number of elements in that node.
  
2. **Insertion Logic**:
   - Traverse to the last node in the list with available space.
   - If the node is full, create a new node and split the current node's elements between the old and new nodes.
   - Insert the new element in the appropriate node based on its value relative to the split elements.

3. **Printing**:
   - Each node's elements are printed to verify the structure and content of the list.

### Notes:
- **NODE_CAPACITY**: This is set to 4 for simplicity, but in practice, it can be larger (often 16 or 32).
- **Performance**: Unrolled linked lists have better cache performance and lower memory overhead than standard linked lists due to fewer nodes.
  
Unrolled linked lists are helpful in applications that benefit from reduced node traversal times, like text editors or data structures that require frequent insertions, deletions, and searches.
