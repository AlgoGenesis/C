#include <stdio.h>
#include <ctype.h>

int isPalindrome(char *s) {
    int left = 0, right = strlen(s) - 1;
    while (left < right) {
        if (!isalnum(s[left])) {
            left++;
            continue;
        }
        if (!isalnum(s[right])) {
            right--;
            continue;
        }
        if (tolower(s[left]) != tolower(s[right])) {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }
    return 1; // Palindrome
}

int main() {
    char str[] = "A man, a plan, a canal, Panama";
    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    return 0;
} 
