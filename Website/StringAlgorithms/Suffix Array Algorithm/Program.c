#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store information of a suffix
typedef struct suffix {
    int index;
    char *suff;
} suffix;

// Comparison function to sort suffixes
int cmp(const void *a, const void *b) {
    return strcmp(((suffix *)a)->suff, ((suffix *)b)->suff);
}

// Function to build suffix array
int *buildSuffixArray(char *txt, int n) {
    // Create an array of suffixes
    suffix *suffixes = (suffix *)malloc(n * sizeof(suffix));

    // Store suffixes and their indexes in an array of structures
    for (int i = 0; i < n; i++) {
        suffixes[i].index = i;
        suffixes[i].suff = (txt + i);
    }

    // Sort the suffixes using the comparison function
    qsort(suffixes, n, sizeof(suffix), cmp);

    // Store indexes of sorted suffixes in the suffix array
    int *suffixArr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        suffixArr[i] = suffixes[i].index;

    // Free the dynamically allocated memory
    free(suffixes);

    return suffixArr;
}

// Function to print the suffix array
void printSuffixArray(int *suffixArr, char *txt, int n) {
    printf("Suffix Array for \"%s\":\n", txt);
    printf("Index\tSuffix\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\n", suffixArr[i], txt + suffixArr[i]);
    }
}

int main() {
    char txt[] = "banana";
    int n = strlen(txt);

    printf("Input string: %s\n\n", txt);

    int *suffixArr = buildSuffixArray(txt, n);

    printSuffixArray(suffixArr, txt, n);

    // Free the dynamically allocated memory
    free(suffixArr);

    return 0;
}