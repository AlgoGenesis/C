## Description
The Max Consecutive Set Bits problem requires finding the longest contiguous sequence of 1s in the binary representation of a given integer. For instance, for the integer 29, whose binary representation is 11101, the longest sequence of consecutive 1s is 3.

### Input
An integer n.

### Output
An integer representing the length of the longest contiguous sequence of 1s in the binary representation of n.

### Constraints

0≤n≤10^9
 
### Time Complexity
The time complexity is **O(logn)**, which is efficient because we only need to examine each bit in the binary representation of n, which takes at most O(logn) time.
