#include <stdio.h>
#include <string.h>

// Helper function to get the character with the highest remaining count
char getMaxChar(int a, int b, int c) {
    if (a >= b && a >= c) return 'a';  // 'a' has the most occurrences
    if (b >= a && b >= c) return 'b';  // 'b' has the most occurrences
    return 'c';  // 'c' has the most occurrences
}

// Function to build the longest "happy" string
void generateLongestHappyString(int aCount, int bCount, int cCount) {
    char result[1000];  // Array to store the resulting string
    int index = 0;      // Index to build the result
    int consecutiveA = 0, consecutiveB = 0, consecutiveC = 0;  // Track consecutive characters
    
    // Keep generating characters until all counts are zero
    while (aCount > 0 || bCount > 0 || cCount > 0) {
        // Get the character with the most remaining count
        char currentChar = getMaxChar(aCount, bCount, cCount);
        
        // Add 'a' if it doesn't violate the "no more than two consecutive" rule
        if (currentChar == 'a') {
            if (consecutiveA < 2) {
                result[index++] = 'a';  // Add 'a' to the result
                aCount--;
                consecutiveA++;  // Increment consecutive 'a' count
                consecutiveB = 0;  // Reset 'b' and 'c' counts
                consecutiveC = 0;
            } else if (bCount >= cCount) {  // If 'a' can't be added, choose the next best option
                result[index++] = 'b';
                bCount--;
                consecutiveB++;
                consecutiveA = 0;
                consecutiveC = 0;
            } else {
                result[index++] = 'c';
                cCount--;
                consecutiveC++;
                consecutiveA = 0;
                consecutiveB = 0;
            }
        }
        // Add 'b' if it doesn't violate the rule
        else if (currentChar == 'b') {
            if (consecutiveB < 2) {
                result[index++] = 'b';
                bCount--;
                consecutiveB++;
                consecutiveA = 0;
                consecutiveC = 0;
            } else if (aCount >= cCount) {
                result[index++] = 'a';
                aCount--;
                consecutiveA++;
                consecutiveB = 0;
                consecutiveC = 0;
            } else {
                result[index++] = 'c';
                cCount--;
                consecutiveC++;
                consecutiveA = 0;
                consecutiveB = 0;
            }
        }
        // Add 'c' if it doesn't violate the rule
        else if (currentChar == 'c') {
            if (consecutiveC < 2) {
                result[index++] = 'c';
                cCount--;
                consecutiveC++;
                consecutiveA = 0;
                consecutiveB = 0;
            } else if (aCount >= bCount) {
                result[index++] = 'a';
                aCount--;
                consecutiveA++;
                consecutiveB = 0;
                consecutiveC = 0;
            } else {
                result[index++] = 'b';
                bCount--;
                consecutiveB++;
                consecutiveA = 0;
                consecutiveC = 0;
            }
        }
    }

    // Null-terminate the result string
    result[index] = '\0';

    // Print the result
    printf("Longest Happy String: %s\n", result);
}

int main() {
    int a, b, c;

    // Get the number of 'a's, 'b's, and 'c's from the user
    printf("Enter the count for 'a': ");
    scanf("%d", &a);
    printf("Enter the count for 'b': ");
    scanf("%d", &b);
    printf("Enter the count for 'c': ");
    scanf("%d", &c);

    // Generate and print the longest happy string
    generateLongestHappyString(a, b, c);

    return 0;
}
