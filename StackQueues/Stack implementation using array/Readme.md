Stack is a linear data structure that follows the LIFO (Last In First Out) principle, where it performs all operations. It performs insertion and deletion operations on the stack from only one end from the top of the stack. Inserting a new element on the top of the stack is known as push operation, and deleting a data element from the top of the stack is known as pop operation. You can perform the implementation of the stack in memory using two data structures: stack implementation using array and stack implementation using linked-list.

Stack Implementation Using Array:
In Stack implementation using arrays, it forms the stack using the arrays. All the operations regarding the stack implementation using arrays.

Procedure for Stack Implementation Using Array:
Now, you will see how to do a stack implementation using an array:

Push Operation:
Adding an element on the top of the stack is termed a push operation. Push operation has the following two steps:
Increment the top variable of the stack so that it can refer to the next memory location.
Add a data element at the increment top position.
Stack data structure states an overflow condition when you try to insert an element into the stack when complete.

Pop Operation:
Removing a data element from the stack data structure is called a pop operation. The pop operation has two following steps:
The value of the top variable will be incremented by one whenever you delete an item from the stack.
The topmost variable of the stack is stored in another variable, and then the value of the top variable will be decremented by one.
The pop operation returns the deleted element that was stored in another variable as a result.
Stack data structure states an underflow condition when you try to delete a data element when the stack is already empty.

Pros and Cons of Stack Implementation Using Array: 
There are various pros and cons of a stack implementation using an array, they are:

Pros: 
It requires no extra memory to store the pointers in stack implementation using an array.
More efficient in terms of time, compared to stack implementation using linked-list.
Cons: 
The size of the stack is fixed, so it cannot increase and decrease stack implementation using an array.
Insertion and deletion in an array are quite difficult as it stores the elements in consecutive memory locations.
With this, we have reached the end of the stack implementation using an array tutorial.