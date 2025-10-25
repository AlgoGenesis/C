//Program to print all natural numbers between given two numbers and calculate their sum and average
#include <stdio.h>
int main() {
    long int x, y;
    long int sum = 0;
    long int count = 0;
    double avg;

    // Input lower and upper limits
    printf("Enter the lower limit: ");
    scanf("%ld", &x);
    printf("Enter the upper limit: ");
    scanf("%ld", &y);

    // Print natural numbers and calculate sum and count
    printf("Natural numbers between %ld and %ld are:\n", x, y);
    for (int i = x; i <= y; i++) {
        if (i > 0) { // Check for natural numbers
            printf("%ld ", i);
            sum += i;
            count++;
        }
    }

    // Calculate average
    avg = (double)sum / count ;

    // Print sum and average
    printf("\nSum: %ld\n", sum);
    printf("Average: %.2lf\n", avg);

    return 0;
}
