#include <stdio.h>
#include <string.h>

void testInfixToPrefix();

int main() {
    testInfixToPrefix();
    return 0;
}

void testInfixToPrefix() {
    // Test case 1: Simple expression without parentheses
    char infix1[] = "A+B";
    char expectedPrefix1[] = "+AB";
    char actualPrefix1[MAX];
    infixToPrefix(infix1, actualPrefix1);
    printf("Test Case 1 - Expected: %s, Actual: %s\n", expectedPrefix1, actualPrefix1);
    if (strcmp(expectedPrefix1, actualPrefix1) == 0) {
        printf("Test Case 1 Passed!\n\n");
    } else {
        printf("Test Case 1 Failed!\n\n");
    }

    // Test case 2: Expression with parentheses
    char infix2[] = "(A+B)*C";
    char expectedPrefix2[] = "*+ABC";
    char actualPrefix2[MAX];
    infixToPrefix(infix2, actualPrefix2);
    printf("Test Case 2 - Expected: %s, Actual: %s\n", expectedPrefix2, actualPrefix2);
    if (strcmp(expectedPrefix2, actualPrefix2) == 0) {
        printf("Test Case 2 Passed!\n\n");
    } else {
        printf("Test Case 2 Failed!\n\n");
    }

    // Test case 3: Complex expression with all operators
    char infix3[] = "A+B*C/D^E";
    char expectedPrefix3[] = "+A/*BCD^E";
    char actualPrefix3[MAX];
    infixToPrefix(infix3, actualPrefix3);
    printf("Test Case 3 - Expected: %s, Actual: %s\n", expectedPrefix3, actualPrefix3);
    if (strcmp(expectedPrefix3, actualPrefix3) == 0) {
        printf("Test Case 3 Passed!\n\n");
    } else {
        printf("Test Case 3 Failed!\n\n");
    }

    // Test case 4: Invalid expression with unmatched parentheses
    char infix4[] = "(A+B";
    char actualPrefix4[MAX];
    printf("Test Case 4 - Expecting Error (Invalid parentheses)\n");
    infixToPrefix(infix4, actualPrefix4); // This should exit the program due to invalid parentheses

    // Test case 5: Expression with invalid characters
    char infix5[] = "A+B$C";
    char actualPrefix5[MAX];
    printf("Test Case 5 - Expecting Error (Invalid character '$')\n");
    infixToPrefix(infix5, actualPrefix5); // This should exit the program due to an invalid character
}
