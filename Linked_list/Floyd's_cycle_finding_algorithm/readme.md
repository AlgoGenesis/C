# Floyd's Cycle Finding Algorithm or Hare-Tortoise Algorithm
It is a pointer algorithm that uses only two pointers.one pointer moves twice as fast as the other one.The faster one is called fast pointer and the other one is called slow pointer.

While traversing the linked list one of these things will occur-
1. The Fast pointer may reach the end (NULL) which shows that there is no loop in the linked list.
2. The Fast pointer again catches the slow pointer at some time therefore a loop exists in the linked list.

## why does Floyd’s Algorithm works?
1. After each iteration where the slow pointer moves one step forward and the fast pointer moves two steps forward, the distance between the two pointers increases.
2. Initially, if the slow pointer is at a distance k from a certain point in the cycle, then after one iteration, the distance between the slow and fast pointers becomes k+1.After two iterations, this distance becomes k+2 and so on.
3. As they continue to move within the cycle, this distance will eventually equal the cycle length n.
4. At this point, since the distance wraps around the cycle and both pointers are moving within the same cycle, they will meet.

## Time Complexity
O(n): The algorithm traverses the linked list at most twice. The first traversal is to determine if a loop exists Therefore, the time complexity is linear with respect to the number of nodes in the linked list.
## Space Complexity
O(1): The algorithm uses only two pointers (slow and fast), regardless of the size of the linked list. This means the space complexity is constant.

## Example
10 -> 20 -> 30 ->40 -> 50 -> 60->30
here we can see the link part of data of 60 is connected to data of 30.therefore there is a loop.and this algorithm will detect it and prints loop detected.

10 -> 20 -> 30 ->40->NULL
here there is no loop and last node is connected to null which means the end of linked list.Therefore it prints no loop dected.



