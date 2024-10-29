Explanation:

The key bitwise operation here is num & 1.
If the least significant bit (LSB) is 1, the number is odd, otherwise it’s even.

For example:
5 in binary is 101, so 5 & 1 is 1 → Odd.
10 in binary is 1010, so 10 & 1 is 0 → Even.

This program efficiently checks the odd/even property in constant time (O(1)).