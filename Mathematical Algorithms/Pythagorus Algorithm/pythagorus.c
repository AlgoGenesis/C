#include <stdio.h>
#include <math.h>

int main() {
    double side1, side2, hypotenuse;

    // Input the lengths of the two sides of the triangle
    printf("Enter the length of the first side: ");
    scanf("%lf", &side1);
    
    printf("Enter the length of the second side: ");
    scanf("%lf", &side2);

    // Calculate the hypotenuse using Pythagoras theorem
    hypotenuse = sqrt((side1 * side1) + (side2 * side2));

    // Output the result
    printf("The length of the hypotenuse is: %.2lf\n", hypotenuse);

    return 0;
}
