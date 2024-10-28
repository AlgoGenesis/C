# Linked List Right Rotation in C

This program rotates a singly linked list to the right by a given number of positions `k`. The list is created dynamically based on user input, and the rotation is performed by adjusting node pointers rather than moving values, making it efficient for larger lists.

## Program Structure

The program consists of the following parts:

1. **Node Definition (`ListNode` Structure)**: Defines the structure of each node in the linked list.
2. **Functions**:
   - `createNode(int val)`: Creates a new node with a specified value.
   - `rotateRight(struct ListNode* head, int k)`: Rotates the linked list to the right by `k` positions.
   - `printList(struct ListNode* head)`: Prints the entire linked list.
3. **`main` Function**: Handles input/output and coordinates the list creation, rotation, and display.

## Code Explanation

### 1. `struct ListNode`

The `ListNode` structure represents each node in the linked list. Each node has:
- An `int` field `val` to store the node's value.
- A pointer `next` to point to the next node in the list.

### 2. `struct ListNode* createNode(int val)`

This function dynamically allocates memory for a new node with the given integer value `val` and returns a pointer to this node.
- **Parameters**: `int val` - value to assign to the node.
- **Returns**: A pointer to the newly created `ListNode`.

### 3. `struct ListNode* rotateRight(struct ListNode* head, int k)`

This function rotates the linked list to the right by `k` positions by:

1. **Initial Checks**: It checks if the list is empty and returns `NULL` if so.
2. **Calculate Length**: It traverses the list to find the last node and counts the total number of nodes (`len`).
3. **Effective Rotation Calculation**: It calculates the effective number of rotations using `k = k % len`.
4. **No Rotation Needed**: If the list has only one node or `k` is `0`, it returns the original `head`.
5. **Finding the New Tail**: It determines the new tail by moving `(len - k)` nodes from the start of the list.
6. **Adjusting Pointers**:
   - Sets the `next` pointer of the `end` node to the `head` to make the list circular.
   - Updates `head` to point to the new head (the node after the new tail).
   - Sets the `next` pointer of the new tail to `NULL` to break the circular connection.
7. **Return the New Head**: Finally, it returns the new head of the rotated list.
- **Parameters**:
  - `struct ListNode* head`: Pointer to the head of the list.
  - `int k`: Number of positions to rotate to the right.

- **Returns**: Pointer to the new head of the rotated list.

### 4. `void printList(struct ListNode* head)`

This function prints the values in the linked list from the head to the last node. It traverses each node, printing the value followed by `" -> "`, and ends with `"NULL"` to indicate the end of the list.
- **Parameters**: `struct ListNode* head` - Pointer to the head of the list.
- **Returns**: None (prints directly to the console).

### 5. `int main()`

The main function handles input and output:
1. **User Input**: Reads values for each node from the user until they enter `-1` to stop.
2. **Rotation Input**: Asks for `k`, the number of positions to rotate.
3. **Execution**: Calls `rotateRight` to perform the rotation and `printList` to display the original and rotated lists.

## Input and Output

### Input

1. **Node Values**: Enter node values one by one, pressing Enter after each. Enter `-1` to indicate the end of input.
2. **Rotation Value (`k`)**: Enter an integer `k` representing the number of positions to rotate the list.

Example:
```plaintext
Enter values for the nodes (enter -1 to stop):
1
2
3
4
5
-1
Enter the value of k (number of rotations): 
2
Original list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
Rotated list: 4 -> 5 -> 1 -> 2 -> 3 -> NULL
