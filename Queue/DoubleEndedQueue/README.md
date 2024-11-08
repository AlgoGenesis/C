# Operations on a Double Ended Queue

Below is the circular array implementation of Double Ended Queue. In a circular array, if the array is full, we start from the beginning.

But in a linear array implementation, if the array is full, no more elements can be inserted. In each of the operations below, if the array is full, "overflow message" is thrown.

Before performing the following operations, these steps are followed.

Take an array (Double Ended Queue) of size n.
Set two pointers front = -1 and rear = 0.

# Types of Double Ended Queue

Input Restricted Double Ended Queue
In this Double Ended Queue, input is restricted at a single end but allows deletion at both the ends.
Output Restricted Double Ended Queue
In this Double Ended Queue, output is restricted at a single end but allows insertion at both the ends.

# Insertion at Front in Double Ended Queue in C

To insert an element at the front end of the Double Ended Queue first, check if the Double Ended Queue is full or not if Double Ended Queue is not full then follow the below approach:

Insert At Front in Double Ended Queue-(1)
Insert at front in Double Ended Queue
Approach:

First, check the position of the front in our array.
If front < 1 , reinitialize front as the last index of the array i.e. front = N-1.
Then, add new element to array[front].

# Insertion at Rear in Double Ended Queue in C

Insert At Rear in Double Ended Queue-(1)
Insert at Rear in Double Ended Queue
To insert an element at the rear end of the Double Ended Queue, follow the below approach:

Approach:

First, check if the Double Ended Queue is full or not.
If the Double Ended Queue is full , reinitialize rear with 0 (rear = 0) else increase rear by 1.
Then, add the element to array[rear].

# Deletion at Front in Double Ended Queue in C

To delete an element at the front end of Double Ended Queue the first, follow the below approach:

Approach:

First, check if Double Ended Queue is empty or not.
If the Double Ended Queue is empty (front == -1), then we cannot perform deletion operation. In this condition, we will simply print underflow.
If contains only 1 element (front = rear) , then only one deletion operation can be performed. set front = -1 and rear = -1.
Else if the front is at the last index ( front == n-1 ) , set front at starting index of Double Ended Queue (front = 0).
If none of the above case exists, just increment front by 1 (front = front + 1).

# Deletion at Rear in Double Ended Queue in C

DeletionAtRear
Delete at Rear in Double Ended Queue
To delete an element at the rear end of the Double Ended Queue, follow the below approach:

First, check if the Double Ended Queue is empty or not.
If the Double Ended Queue is empty (front = -1), then deletion operation cannot be performed and we will print underflow.
If the Double Ended Queue has only 1 element( front==rear), we will set front = -1 and rear =-1.
If the rear is at the starting index of Double Ended Queue (rear == 0) , then set rear to last index (rear = n-1).
If none of the above case exists, just decrement rear by 1 (rear = rear-1).
