# Representation

In a deque we maintain two pointers front and rear, that point to either end of the deque. The elements in a deque extend from the front end to the rear end and since it is circular, dequeue[n–1] is followed by dequeue[0].

# Insertion at Front in Deque in C

To insert an element at the front end of the deque first, check if the deque is full or not if deque is not full then follow the below approach:

Approach:

First, check the position of the front in our array.
If front < 1 , reinitialize front as the last index of the array i.e. front = N-1.
Then, add new element to array[front].

# Insertion at Rear in Deque in C

To insert an element at the rear end of the deque, follow the below approach:

Approach:

First, check if the deque is full or not.
If the deque is full , reinitialize rear with 0 (rear = 0) else increase rear by 1.
Then, add the element to array[rear].

# Deletion at Front in Deque in C

To delete an element at the front end of the deque first, follow the below approach:

Approach:

First, check if deque is empty or not.
If the deque is empty (front == -1), then we cannot perform deletion operation. In this condition, we will simply print undeflow.
If deque contains only 1 element (front = rear) , then only one deletion operation can be performed. set front = -1 and rear = -1.
Else if the front is at the last index ( front == n-1 ) , set front at starting index of deque (front = 0).
If none of the above case exists, just increment front by 1 (front = front + 1).

# Deletion at Rear in Deque in C

To delete an element at the rear end of the deque, follow the below approach:

First, check if the deque is empty or not.
If the deque is empty (front = -1), then deletion operation cannot be performed and we will print underflow.
If the deque has only 1 element( front==rear), we will set front = -1 and rear =-1.
If the rear is at the starting index of deque (rear == 0) , then set rear to last index (rear = n-1).
If none of the above case exists, just decrement rear by 1 (rear = rear-1).

# Check if Deque is Empty or Not Empty

To check if the deque is empty simply check the front if front = -1, then deque is empty else it is not empty.

# Check if Deque is Full or Not Full

To check if the deque is full simply check the below conditions:

If front == 0 and rear == n-1 , then deque is Full
If front == rear + 1 , then also deque is Full.
