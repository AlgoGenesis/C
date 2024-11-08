## Description
Given an integer N, write a recursive program to print the binary equivalent of N. A decimal integer can be converted to binary by dividing it by 2. Take the quotient, and keep dividing it by 2, until you reach zero. Each time you perform this division, take note of the remainder. Now reverse the remainders list, and you get the number in binary form.

### Input Format

A single line consisting of N.

### Constraints

1 <= N <= 10^3

### Output Format

Output a line with an expected answer.

### Sample Input 

10
### Sample Output

1010
### Time Complexity
Binary Conversion Loop,Printing Loop run in O(logN) time, the overall time complexity of the program is,
𝑂(log⁡𝑁)
