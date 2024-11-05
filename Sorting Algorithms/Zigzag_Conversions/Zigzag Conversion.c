#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    if (numRows <= 1 || numRows >= strlen(s)) {
        return s;
    }

    // Allocate memory for rows
    char** rows = (char*)malloc(sizeof(char) * numRows);
    for (int i = 0; i < numRows; i++) {
        rows[i] = (char*)malloc(sizeof(char) * (strlen(s) + 1));
        rows[i][0] = '\0'; // Initialize each row as an empty string
    }

    int currentRow = 0;
    int goingDown = 0;

    for (int i = 0; i < strlen(s); i++) {
        // Append the current character to the current row
        strncat(rows[currentRow], &s[i], 1);

        // Change direction if we hit the top or bottom row
        if (currentRow == 0) {
            goingDown = 1; // Start going down
        } else if (currentRow == numRows - 1) {
            goingDown = 0; // Start going up
        }

        // Move to the next row
        currentRow += goingDown ? 1 : -1;
    }

    // Concatenate all rows into the result
    char* result = (char*)malloc(sizeof(char) * (strlen(s) + 1));
    result[0] = '\0'; // Initialize result as an empty string
    for (int i = 0; i < numRows; i++) {
        strcat(result, rows[i]);
        free(rows[i]); // Free each row after use
    }
    free(rows); // Free the rows array

    return result;
}

int main() {
    char* s = "PAYPALISHIRING";
    int numRows = 3;
    char* result = convert(s, numRows);
    printf("Zigzag conversion: %s\n", result);
    free(result); // Free the result after use
    return 0;
}