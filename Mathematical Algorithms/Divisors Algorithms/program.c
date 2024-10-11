#include <stdio.h>
#include <math.h>

// Function to count the number of divisors
int count_divisors(int n) {
    int count = 1; // Start with 1 for the product of factors
    int exponent;

    for (int i = 2; i * i <= n; i++) {
        exponent = 0; // Reset exponent for the current prime factor
        while (n % i == 0) {
            n /= i; // Divide n by the prime factor
            exponent++;
        }
        if (exponent > 0) {
            count *= (exponent + 1); // Update count
        }
    }

    // If n is still greater than 1, then it is a prime number
    if (n > 1) {
        count *= 2; // This accounts for the prime factor n^1
    }

    return count;
}

// Function to calculate the sum of divisors
int sum_divisors(int n) {
    int sum = 1; // Start with 1 for the product of factors
    int exponent;

    for (int i = 2; i * i <= n; i++) {
        exponent = 0; // Reset exponent for the current prime factor
        int term_sum = 1; // Sum for the current prime factor

        while (n % i == 0) {
            n /= i; // Divide n by the prime factor
            exponent++;
            term_sum += (int)pow(i, exponent); // Calculate the sum of powers
        }
        if (exponent > 0) {
            sum *= term_sum; // Update total sum
        }
    }

    // If n is still greater than 1, then it is a prime number
    if (n > 1) {
        sum *= (1 + n); // Add the prime factor itself
    }

    return sum;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int num_divisors = count_divisors(n);
    int total_sum = sum_divisors(n);

    printf("Number of divisors: %d\n", num_divisors);
    printf("Sum of divisors: %d\n", total_sum);
    
    return 0;
}
