#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        // Swap the characters at left and right pointers
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        // Move the pointers towards the center
        left++;
        right--;
    }
}

int main() {
    // Predefined string
    char str[] = "Hello, World!";

    // Reverse the string
    reverseString(str);

    // Output the reversed string
    printf("Reversed string: %s\n", str);

    return 0;
}
