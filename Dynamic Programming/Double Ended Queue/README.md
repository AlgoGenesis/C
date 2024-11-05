# Double Ended Queue (Deque) Implementation in C

## Overview

A Double Ended Queue (Deque) is a versatile data structure that allows insertion and deletion of elements from both the front and the rear. This flexibility makes it suitable for various applications such as task scheduling, palindrome checking, and more. The provided implementation uses a circular array to efficiently manage the elements while ensuring constant time complexity for insertion and deletion operations.

## Approach

This implementation of the Deque uses a **circular array** approach. By utilizing a circular array, we can effectively manage the front and rear pointers without wasting space. When the rear pointer reaches the end of the array, it wraps around to the beginning, allowing for efficient use of the allocated space. This approach ensures that both insertion and deletion operations are performed in O(1) time complexity.

Key features of this implementation include:
- Insertion and deletion from both ends (front and rear).
- Checking if the deque is empty or full.
- Displaying the current elements in the deque.

## Complexity

The time complexity for the various operations in this Deque implementation is as follows:

- **Insertion at Front**: O(1)
- **Insertion at Rear**: O(1)
- **Deletion from Front**: O(1)
- **Deletion from Rear**: O(1)
- **Check if Empty**: O(1)
- **Check if Full**: O(1)
- **Display Elements**: O(n) (where n is the number of elements in the deque)

## Example

Below is an example demonstrating the basic operations of the deque:

```c
#include <stdio.h>
#include "deque.h" // Include the header file for the deque functions

int main() {
    Deque deque;
    initialize(&deque);

    // Inserting elements
    insertRear(&deque, 10);
    insertRear(&deque, 20);
    insertFront(&deque, 5);
    insertFront(&deque, 1);
    
    // Display current elements in the deque
    printf("Current Deque: ");
    display(&deque); // Output: 1 5 10 20

    // Deleting elements
    deleteFront(&deque); // Deletes 1
    printf("After deleting from front: ");
    display(&deque); // Output: 5 10 20

    deleteRear(&deque); // Deletes 20
    printf("After deleting from rear: ");
    display(&deque); // Output: 5 10

    // Inserting more elements
    insertRear(&deque, 30);
    printf("After inserting 30 at rear: ");
    display(&deque); // Output: 5 10 30

    return 0;
}