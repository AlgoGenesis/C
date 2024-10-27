#include <stdio.h>
#include <string.h>

// Function to determine minimum rotations to match A with B
int min_rotations_to_match(char *A, char *B) {
    int n = strlen(A);
    
    // Check if lengths are different
    if (n != strlen(B)) {
        return -1;
    }
    
    // Concatenate A with itself
    char A2[2 * n + 1];
    snprintf(A2, sizeof(A2), "%s%s", A, A);

    // Search for B in A2
    char *pos = strstr(A2, B);
    if (pos != NULL) {
        // Calculate rotation count
        return pos - A2;
    } else {
        return -1;  // No match found
    }
}

// Main function to demonstrate the algorithm
int main() {
    char A[] = "abcde";
    char B[] = "cdeab";
    
    int rotations = min_rotations_to_match(A, B);
    if (rotations != -1) {
        printf("Minimum rotations required: %d\n", rotations);
    } else {
        printf("No possible rotation makes the sequences identical.\n");
    }
    
    return 0;
}
