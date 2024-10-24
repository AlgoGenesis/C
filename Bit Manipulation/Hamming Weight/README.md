# Counting the Number of 1 Bits (Hamming Weight)

- Given a integer n,Count the number of 1 Bits.


```
Example 
Let's say a user inputs 29. The binary representation of 29 is 11101, which has 4 ones. Here's how the function works step by step:

Initial Value of n: 29 (11101)

Count: 0
29 & 1 → 1 (Count becomes 1)
Right shift n → 14 (01110)
Next Value of n: 14 (01110)

Count: 1
14 & 1 → 0 (Count remains 1)
Right shift n → 7 (000111)
Next Value of n: 7 (000111)

Count: 1
7 & 1 → 1 (Count becomes 2)
Right shift n → 3 (00011)
Next Value of n: 3 (00011)

Count: 2
3 & 1 → 1 (Count becomes 3)
Right shift n → 1 (00001)
Next Value of n: 1 (00001)

Count: 3
1 & 1 → 1 (Count becomes 4)
Right shift n → 0 (00000)
Final Value of n: 0

The loop exits and returns 4.
```
**Time complexity**:O(logn)
**Space complexity**:O(1)