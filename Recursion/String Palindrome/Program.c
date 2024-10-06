#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char str[], int start, int end) {
   
    if (start >= end) { // base case
        return true;
    }

    if (str[start] != str[end]) {
        return false; 
    }
    // Recursive call
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str); // Input from user

    int length = strlen(str);
    
    if (isPalindrome(str, 0, length - 1)) {
        printf("'%s' is a palindrome.\n", str);
    } else {
        printf("'%s' is not a palindrome.\n", str);
    }

    return 0;
}