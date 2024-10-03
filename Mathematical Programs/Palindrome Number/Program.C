// C Program to check if a number is a palindrome by reversing the number
#include <stdio.h>

int reverseNum(int N) {
  
      // Function to store the reversed number
    int rev = 0;
    while (N > 0) {

        // Extract the last digit
        int dig = N % 10;

        // Append the digit to the reversed number
        rev = rev * 10 + dig;

        // Remove the last digit
        N /= 10;
    }
    return rev;
}

int isPalindrome(int N) {
  
    // Negative numbers are not palindromes
    if (N < 0)
        return 0;
    return N == reverseNum(N);
}

int main() {
    int N;
    scanf("%d",&N); 
    if (isPalindrome(N)) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }
    return 0;
}
