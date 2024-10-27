# Queue Implementation using Array
 Queue is a linear data structure that follows a particular order in which the operations are performed for storing data. The order is First In First Out (FIFO).

 For implementing queue, we need to keep track of two indices, front and rear. We enqueue an item at the rear and dequeue an item from the front. If we simply increment front and rear indices, then there may be problems, the front may reach the end of the array. The solution to this problem is to increase front and rear in circular manner.

## Steps for enqueue:
- Check the queue is full or not
- If full, print overflow and exit
- If queue is not full, increment tail and add the element
  
## Steps for dequeue:
- Check queue is empty or not
- If empty, print underflow and exit
- If not empty, print element at the head and increment head

### Complexity Analysis:  
Time Complexity
 | Operations  |	Complexity |
 |-------------|--------------|
| Enqueue(insertion) |	O(1) |
| Deque(deletion)   |	O(1) |
| Front(Get front)  | 	O(1) |
| Rear(Get Rear)	| O(1) |
| IsFull(Check queue is full or not)	| O(1) |
| IsEmpty(Check queue is empty or not)	| O(1) | 

### Auxiliary Space: 
O(N) where N is the size of the array for storing elements.
