Stack: Key Concepts
 Definition:

 A stack is a linear data structure that follows the Last In First Out (LIFO) principle, meaning the last element added is the first to be removed.

 Implementation:

 Can be implemented using arrays or linked lists.
 Array-based stacks have a fixed size, while linked-list stacks can grow dynamically.
 Applications:

 Function call management (call stack).
 Expression evaluation (infix, postfix, prefix).
 Backtracking algorithms (e.g., maze solving).
 Undo mechanisms in applications (text editors, browsers).
 Advantages:

 Easy to implement and use.
 Provides efficient access to the last inserted element.
 Disadvantages:

 Limited size in array-based implementations (risk of overflow).
 Requires extra memory for pointers in linked-list implementations.
 Cannot access elements in the middle or bottom without popping.
 Complexity:

 Time Complexity:
 Push: O(1)
Pop: O(1)
 Peek: O(1)
 Space Complexity: O(n) for n elements in the stack.
