#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000

int SA[MAX_N], tempSA[MAX_N];
int RA[MAX_N], tempRA[MAX_N];
int c[MAX_N];

void countingSort(int k, int n) {
    int i, sum, maxi = (k == 0 ? 256 : n);
    memset(c, 0, sizeof c);
    for (i = 0; i < n; i++)
        c[i + k < n ? RA[i + k] : 0]++;
    for (i = sum = 0; i < maxi; i++) {
        int t = c[i]; c[i] = sum; sum += t;
    }
    for (i = 0; i < n; i++)
        tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
    for (i = 0; i < n; i++)
        SA[i] = tempSA[i];
}

void constructSA(char *T, int n) {
    int i, k, r;
    for (i = 0; i < n; i++) SA[i] = i, RA[i] = T[i];
    for (k = 1; k < n; k <<= 1) {
        countingSort(k, n);
        countingSort(0, n);
        tempRA[SA[0]] = r = 0;
        for (i = 1; i < n; i++)
            tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
        for (i = 0; i < n; i++)
            RA[i] = tempRA[i];
        if (RA[SA[n-1]] == n-1) break;
    }
}

void printSA(char *T, int n) {
    for (int i = 0; i < n; i++)
        printf("%2d\t%s\n", SA[i], T + SA[i]);
}

int main() {
    char T[] = "banana$";
    int n = strlen(T);
    constructSA(T, n);
    printf("Suffix Array for %s:\n", T);
    printSA(T, n);
    return 0;
}