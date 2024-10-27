#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// str : Stores input string
// n : Length of str.
// curr : Stores current permutation
// index : Index in current permutation, curr
void permuteRec(char *str, int n, int index, char *curr) {
    // base case
    if (index == n) {
        return;
    }
    printf("%s\n", curr);
    for (int i = index + 1; i < n; i++) {
        int len = strlen(curr);
        curr[len] = str[i];
        curr[len + 1] = '\0';
        permuteRec(str, n, i, curr);

        // backtracking
        curr[len] = '\0';
    }
}

// Generates power set in lexicographic order
void powerSet(char *str) {
    int n = strlen(str);
    char *arr = (char *)malloc(n + 1);
    strcpy(arr, str);
    qsort(arr, n, sizeof(char), (int (*)(const void *, const void *))strcmp);
    char *curr = (char *)malloc(n + 1);
    curr[0] = '\0';
    permuteRec(arr, n, -1, curr);
    free(arr);
    free(curr);
}

// Driver code
int main() {
    char str[] = "cab";
    powerSet(str);
    return 0;
}

