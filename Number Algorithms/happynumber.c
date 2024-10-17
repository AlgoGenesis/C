#include<stdio.h>

int main() {
    int num, digit, sum = 0;
    
    // Prompt user for input
    printf("Enter any number: ");
    scanf("%d", &num);
    
    // While the number has more than one digit, calculate the sum of squares
    while(num > 0 || sum > 9) {
        if(num == 0){
            num = sum;
            sum = 0;
        }
        
        // Get the last digit of the number
        digit = num % 10;
        
        // Add the square of the digit to sum
        sum += digit * digit;
        
        // Remove the last digit from the number
        num /= 10;
    }
    
    // If the sum is 1, it's a happy number. Otherwise, it's not.
    (sum == 1)? printf("It is a happy number.\n"): printf("It is not a happy number.\n");

    return 0;
}