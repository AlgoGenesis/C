#include <stdio.h>

// Utility function to swap two elements
void swap(char* x, char* y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Function to generate all permutations of the string
void permute(char* str, int left, int right) {
    if (left == right) {
        printf("%s\n", str);
    } else {
        for (int i = left; i <= right; i++) {
            swap((str + left), (str + i));
            permute(str, left + 1, right);
            swap((str + left), (str + i)); // Backtrack
        }
    }
}

// Function to print all combinations
void combine(char* str, int n, int r, char* data, int index, int i) {
    if (index == r) {
        for (int j = 0; j < r; j++) {
            printf("%c", data[j]);
        }
        printf("\n");
        return;
    }

    if (i >= n) return;

    data[index] = str[i];
    combine(str, n, r, data, index + 1, i + 1);

    combine(str, n, r, data, index, i + 1);
}

int main() {
    char str[] = "ABC";
    int n = sizeof(str) / sizeof(str[0]) - 1;

    printf("Permutations:\n");
    permute(str, 0, n - 1);

    printf("\nCombinations (r = 2):\n");
    char data[2];
    combine(str, n, 2, data, 0, 0);

    return 0;
}
