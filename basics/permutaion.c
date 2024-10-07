#include <stdio.h>
#include <string.h>

// Function to swap two characters
void swap(char* a, char* b) {
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Recursive function to generate permutations
void generatePermutations(char* str, int left, int right) {
    if (left == right) {
        printf("%s\n", str); // Print the current permutation
    } else {
        for (int i = left; i <= right; i++) {
            swap((str + left), (str + i)); // Swap the current index with the left index
            generatePermutations(str, left + 1, right); // Recur for the next index
            swap((str + left), (str + i)); // Backtrack to restore the original string
        }
    }
}

int main() {
    char str[100]; // Input string

    // Prompt the user to enter a string
    printf("Enter a string: ");
    scanf("%s", str);

    int length = strlen(str);
    printf("Permutations of the string:\n");
    generatePermutations(str, 0, length - 1); // Generate permutations

    return 0;
}