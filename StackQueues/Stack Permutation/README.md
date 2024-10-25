### STACK PERMUTATION
---
### Problem Description:
Given two integer arrays, `input` and `output`, each containing unique elements and both of the same length `n`, determine if it is possible to achieve the output sequence using only stack operations on the input sequence. In other words, we start with the input array and can perform a series of stack operations: we may push elements from input onto a stack in their original order and pop them off the stack to match the output sequence. The task is to write a program that checks if the output sequence is a valid stack permutation of the input sequence. If it's possible to generate the output using these stack operations, print "Yes"; otherwise, print "No".

---
### Description

**1. Input Arrays:** The program receives two integer arrays, input and output, both of the same length and containing unique elements.

**2. Function `isStackPermutation`:** This function checks if output is a valid stack permutation of input.                        

*Step 2.1:* Initialize a stack (array) to simulate the stack operations and a variable top to track the top of the stack.                           
*Step 2.2:* Use a variable j to track the current index of the output array.                             

**3. Iterate through input:** For each element in input:

*Step 3.1:* Push the current element from input onto the stack.                                  
Step 3.2: While the stack’s top matches the next element in output, pop it from the stack and move to the next element in output.    

**4. Result Check:** After processing all elements in input, check if all elements in output have been matched. If j equals the length of output, return true; otherwise, return false.                                     

**5. Main Function:** Tests the isStackPermutation function with example arrays and prints "Yes" if output is achievable from input using stack operations, otherwise prints "No".                                   

---
### Input:
int input[] = {1, 2, 3};
int output[] = {2, 1, 3};

### Output: 
Yes, it is a stack permutation.

---
### Time Complexity:

The time complexity of this solution is `O(n)`, where `n` is the number of elements in the input (or output) array. This is because we iterate through each element in the input array once, pushing each onto the stack. Each element can only be popped from the stack once when it matches the next element in the output array, so the number of push and pop operations is limited to
`2n` (one push and one pop per element at most). Thus, the algorithm efficiently completes the check in linear time.
