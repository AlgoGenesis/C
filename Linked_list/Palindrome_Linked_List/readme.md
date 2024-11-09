# Given a singly linked list. The task is to check if the given linked list is palindrome or not.

Examples:

1. Input: head: 1->2->1->1->2->1
   Output: true
   Explanation: The given linked list is 1->2->1->1->2->1 , which is a palindrome and Hence, the output is true.

2. Input: head: 1->2->3->4
   Output: false
    Explanation: The given linked list is 1->2->3->4, which is not a palindrome and Hence, the output is false.






# Implementation 1 : Using Iterative Method

- O(n) Time and O(1) Space

The approach involves reversing the second half of the linked list starting from the middle. After reversing, traverse from the head of the list and the head of the reversed second half simultaneously, comparing the node values. If all corresponding nodes have equal values, the list is a palindrome.


Follow the steps below to solve the problem:

- Use two pointers say, fast and slow to find the middle of the list. fast will move two steps ahead and slow will move one step ahead at a time.
- if list is odd, when fast->next is NULL , slow will point to the middle node.
- if list is even, when fast->next->next is NULL slow will point to the middle node.
- Reverse the second half of the list starting from the middle.
- Check if the first half and the reversed second half are identical by comparing the node values.
- Restore the original list by reversing the second half again and attaching it back to the first half.

# Implementation 2 :Using Recursion

- O(n) Time and O(n) Space

The idea is to initialize an empty stack and start traversing from the head node. Push all the nodes into the stack while traversing till end. Again traverse the linked list and compare the popped node’s data with the currrent node data. If both the data are not equal return false, else when stack becomes empty, it means we reach to the end node. return true, as linked list is a palindrome.