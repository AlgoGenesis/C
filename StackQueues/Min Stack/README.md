## Problem Statement
Design a Data Structure MinStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the MinStack. All these operations of MinStack must have a time complexity of O(1)

## Definition:
A MinStack is a specialized stack data structure that supports standard stack operations (push, pop, top) while also providing the ability to retrieve the minimum element in constant time O(1). It achieves this by maintaining an additional mechanism that tracks the minimum value, ensuring efficient access to both the stack's top element and the minimum element at any point.

## Algorithm :

1. **Dynamic Stack Management**:
   - Use a dynamically allocated array `mainStack` to hold elements in the `MinStack` structure. The stack has a fixed initial capacity but can be adjusted if needed.

2. **Minimum Element Tracking**:
   - Track the minimum element in constant time using the variable `minElement`. Adjust values stored in `mainStack` when a new minimum is encountered.

3. **Pushing New Elements**:
   - When adding a new element, check if it is less than the current minimum (`minElement`). If it is, store a modified value in `mainStack` to represent this relationship, and update `minElement` to the new minimum.

4. **Popping Elements**:
   - When removing the top element, determine if it represents the current minimum. If so, use a recalculated value to restore `minElement` to the previous minimum.


## Detailed Description

### 1. MinStack Structure

   - **Variables**:                  
     - `int* mainStack`: Pointer to an array that holds stack elements dynamically.
     - `int top`: Tracks the index of the top element in the stack.
     - `int capacity`: The maximum capacity of the stack.
     - `int minElement`: Tracks the minimum value in the stack.

### 2. Functions

- **`isEmpty()`**:
  - Checks if the stack is empty by verifying if `top` is -1.

- **`isFull()`**:
  - Checks if the stack is full by comparing `top` with `capacity - 1`.

- **`getMin()`**:
  - Prints the minimum element by accessing `minElement` directly. If the stack is empty, it prints an appropriate message.

- **`peek()`**:
  - Shows the top element of the stack. If the top element is less than `minElement` (indicating a modified value is stored), it prints `minElement` as the actual top element.

- **`pop()`**:
  - Removes the top element from `mainStack`. If the popped element is less than `minElement`, it recalculates `minElement` based on the modified value stored, thus restoring the previous minimum.

- **`push(int val)`**:
  - Adds an element to `mainStack`. If the new element is less than the current `minElement`, it pushes a modified value and updates `minElement` to the new value; otherwise, it pushes the element directly.

## Example

### Sample Input:

    push(s, 8);
    push(s, 16);
    getMin(s);
    push(s, 1);
    getMin(s);
    pop(s);
    getMin(s);
    push(s, 5);
    getMin(s);
    pop(s);
    peek(s);

### Sample Output:

    Element Pushed: 8
    Element Pushed: 16
    Minimum Element in the stack is: 8
    Element Pushed: 1
    Minimum Element in the stack is: 1
    Element popped: 1
    Minimum Element in the stack is: 8
    Element Pushed: 5
    Minimum Element in the stack is: 5
    Element popped: 5
    Top Most Element is: 16

## Time and Space Complexity:

### Time Complexity:
- The time complexity of the `MinStack` implementation is as follows: `push()`, `pop()`, and `getmin()` operations all run in `O(1)` time, as they perform a constant number of operations regardless of the stack size. The `peek()` operation also executes in `O(1)` time since it only accesses the top element of the stack. The `isEmpty()` and `isFull()` functions similarly operate in `O(1)` time by checking the state of the stack. Overall, all operations in this stack implementation are efficient, with a consistent time complexity of `O(1)` for each operation.

### Space Complexity:
- The space complexity of the MinStack implementation is `O(n)`, where `n` is the number of elements stored in the stack. This is due to the need to store each element in the underlying stack data structure, while only a few additional variables (like minElement) are used, which do not contribute significantly to the space usage.







