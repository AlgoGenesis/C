## Reverse Integer

## Problem Statement: 

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

## Approch:
However, if the number is large such that the reverse overflows, the output is some garbage value. If we run the code above with input as any large number say 1000000045, then the output is some garbage value like 1105032705 or any other garbage value. See this for the output.
How to handle overflow? 
The idea is to store the previous value of the sum can be stored in a variable that can be checked every time to see if the reverse overflowed or not.

## Example:

Input: x = 123
Output: 321

## Time and Space Complexity:

Time Complexity: O(log(num))
Space Complexity: O(1)

