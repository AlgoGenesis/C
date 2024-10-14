#include<stdio.h>

//Recursive function to calculate the power of a number
long long int power(int base, int exponent)
{
    //if the exponent is 0 the value will be one
    if(exponent==0)
        return 1;
    
    // Recursion occurs here till the exponent reaches 0
    else
        return base*(power(base,exponent-1));
}

void main()
{

    //using "long long int" data type to store a larger number
    long long int base;
    long long int exponent;
    long long int result;

    printf("Enter the base value: ");
    scanf("%lld",&base);

    printf("\nEnter the exponent value: ");
    scanf("%lld",&exponent);

    //calling the function to calculate power
    result = power(base, exponent);

    printf("\n %lld ^ %lld = %lld", base, exponent, result);
}