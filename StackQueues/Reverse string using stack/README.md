### Reverse String Using Stack in C
This repository contains a C program that reverses a given string using the stack data structure. The program reads a string input from the user, pushes each character onto a stack, and then pops the characters from the stack to display the string in reverse order.

---
### Features    

**Input:**      
A single string (up to 100 characters), which can contain spaces and special characters.                                     
**Output:**            
The reversed version of the input string.     

---
### Efficiency:                        
**Time Complexity:** O(n), where n is the length of the string.                     
**Space Complexity:** O(n), since the stack stores all the characters of the string.

---
### How It Works
The program uses the stack data structure, which follows the LIFO (Last In, First Out) principle:                           

1. Each character from the input string is pushed onto a stack.                 
2. The characters are then popped off the stack in reverse order to form the reversed string.                 

---
### Sample Input and Output:
Enter a string (max 100 characters): Hello World                   
Reversed string: dlroW olleH
