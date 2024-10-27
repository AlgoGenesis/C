# Palindrome Detection Using Stack

This repository contains a simple C program to detect if a given string is a palindrome using a stack data structure. A palindrome is a word or phrase that reads the same forwards as backwards (e.g., "madam" or "racecar").

## Program Overview

The program uses a stack to reverse the first half of the input string and then compares it with the second half. If all characters match, the string is a palindrome.

## Code Structure

- **Stack Operations**: The stack is implemented using an array with standard operations:
  - `push` - Adds an element to the stack.
  - `pop` - Removes the top element from the stack.
  
- **Palindrome Check**:
  - The `isPalindrome` function pushes the first half of the string onto the stack.
  - For odd-length strings, it skips the middle character.
  - The function then compares the remaining characters with those popped from the stack. If they match, the string is identified as a palindrome.

## Code

```c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100 // Define the maximum size of the stack

// Stack structure using array
char stack[MAX];
int top = -1;

// Function to push elements onto the stack
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}

// Function to pop elements from the stack
char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack[top--];
}

// Function to check if the given string is a palindrome
bool isPalindrome(char str[]) {
    int n = strlen(str);
    int i;

    // Push first half of the string onto the stack
    for (i = 0; i < n / 2; i++) {
        push(str[i]);
    }

    // If the string length is odd, skip the middle character
    if (n % 2 != 0) {
        i++;
    }

    // Compare the second half of the string with the stack
    for (; i < n; i++) {
        if (str[i] != pop()) {
            return false; // Mismatch found, not a palindrome
        }
    }

    return true; // If all characters match, it's a palindrome
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("%s is a palindrome\n", str);
    } else {
        printf("%s is not a palindrome\n", str);
    }

    return 0;
}
