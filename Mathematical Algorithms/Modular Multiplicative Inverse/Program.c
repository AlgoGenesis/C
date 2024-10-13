#include <stdio.h>

#define ll long long
const int M = 1000000007; // Large prime number for modulo operations

// Function to perform modular exponentiation
// Calculates (a^b) % M using binary exponentiation
ll binaryExpo(ll a, ll b) {
    if (b == 0) return 1; // Base case: a^0 = 1
    ll rec = binaryExpo(a, b / 2); // Recursive call to divide exponent by 2
    rec = (rec * rec) % M; // Combine results for even exponent

    // If b is odd, multiply one extra 'a' to the result
    if (b % 2 != 0) rec = (rec * a) % M;
    
    return rec;
}

int main() {
    ll a;
    
    // Prompt user for input
    printf("Enter a number to find its Modular Multiplicative Inverse under modulo %d: ", M);
    scanf("%lld", &a);
    
    // Calculate the Modular Multiplicative Inverse as (a^(M-2)) % M
    ll mmi = binaryExpo(a, M - 2);
    
    // Output the result
    printf("Modular Multiplicative Inverse of %lld under modulo %d is: %lld\n", a, M, mmi);
    
    return 0;
}
