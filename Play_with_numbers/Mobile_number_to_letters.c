#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* keypad[] = {
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};

void generateCombinations(char* digits, int index, char* current, int length) {
    if (index == length) {
        printf("%s\n", current); 
        return;
    }


    const char* letters = keypad[digits[index] - '0'];
    for (int i = 0; i < strlen(letters); i++) {
        current[index] = letters[i];
        generateCombinations(digits, index + 1, current, length);
    }
}

void letterCombinations(char* digits) {
    int length = strlen(digits);
    if (length == 0) {
        printf("No combinations possible\n");
        return;
    }


    char* current = (char*)malloc((length + 1) * sizeof(char));
    current[length] = '\0';  
    generateCombinations(digits, 0, current, length);
    free(current);  
}

int main() {
    char digits[100];
    printf("Enter the digits: ");
    scanf("%s", digits);  

    printf("Possible letter combinations are:\n");
    letterCombinations(digits);

    return 0;
}
