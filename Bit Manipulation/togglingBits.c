#include <stdio.h>

int main() {
    // Program to toggle a bit at a given position in a number
    int n, pos, res;
    
    // Input the number
    printf("Enter a number: ");
    scanf("%d", &n);
    
    // Input the position to toggle
    printf("Enter a position to toggle: ");
    scanf("%d", &pos);
    
    // Toggle the bit at the specified position
    res = (1 << pos) ^ n;
    
    // Output the result
    printf("After toggling the bit at position %d, the result is: %d\n", pos, res);
    
    return 0;
}
