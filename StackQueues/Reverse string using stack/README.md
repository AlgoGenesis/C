### Reverse String Using Stack

### Description

The program reverses a given string using the stack data structure. The program reads a string input from the user, pushes each character onto a stack, and then pops the characters from the stack to display the string in reverse order.

---
### Working Principle:

This C program uses a stack data structure to reverse a string, demonstrating fundamental stack operations like push and pop. The stack is implemented using a structure that holds an array for the items (characters of the string) and an integer top that tracks the position of the top element. Several helper functions manage the stack, including initialize to set up an empty stack,     

```isFull``` to check if the stack has reached its capacity,   

```isEmpty``` to check if the stack is empty, 

```push``` to add characters to the stack, and       

```pop``` to remove characters from it.                

The main logic of the program lies in the ```reverseString``` function.

The function first pushes each character of the input string onto the stack. Since a stack operates on a Last-In-First-Out (LIFO) principle, when the characters are popped back off the stack and placed into the string, they are inserted in reverse order. Thus, the string is reversed by the end of the process. The program reads the string from the user, uses the stack to reverse it, and then prints the reversed string.

---
### Features    

**Input:** A single string (up to 100 characters), which can contain spaces and special characters.                                     
**Output:** The reversed version of the input string.     

---
### Efficiency:                        
**Time Complexity:** O(n), where n is the length of the string.                     
**Space Complexity:** O(n), since the stack stores all the characters of the string.

---
### Sample Input and Output:
Enter a string (max 100 characters): Hello World                   
Reversed string: dlroW olleH
