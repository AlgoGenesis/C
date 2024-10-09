#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to swap two characters
void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Function to reverse the digits after a given index
void reverse(char* num, int start, int end) {
    while (start < end) {
        swap(&num[start], &num[end]);
        start++;
        end--;
    }
}

// Function to find the next greater number
int findNextGreaterNumber(char num[], int n) {
    int i, j;
    
    // Step 1: Find the first digit that is smaller than the digit next to it
    for (i = n - 2; i >= 0; i--) {
        if (num[i] < num[i + 1]) {
            break;
        }
    }
    
    // If no such digit is found, return -1 (the number is in descending order)
    if (i == -1) {
        return -1;
    }
    
    // Step 2: Find the smallest digit on the right of 'i' that is greater than num[i]
    for (j = n - 1; j > i; j--) {
        if (num[j] > num[i]) {
            break;
        }
    }
    
    // Step 3: Swap the digits at indices 'i' and 'j'
    swap(&num[i], &num[j]);
    
    // Step 4: Reverse the digits after index 'i'
    reverse(num, i + 1, n - 1);
    
    return 1;
}

int main() {
    char num[100];
    
    // Get the number from the user
    printf("Enter a number: ");
    scanf("%s", num);
    
    int n = strlen(num);  // Get the length of the number
    
    // Call the function to find the next greater number
    if (findNextGreaterNumber(num, n) == -1) {
        printf("-1\n");  // No greater number exists
    } else {
        printf("Next greater number: %s\n", num);
    }
    
    return 0;
}
