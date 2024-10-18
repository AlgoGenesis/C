#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *b = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    int v = 0;
    int i = 0, j = 0;
    int *k = (int*)calloc(100000, sizeof(int)); // Assuming the max value in array `b` doesn't exceed 100000
    for (int m = 0; m < 100000; m++) k[m] = -1;

    while (i < n && j < n) {
        if (k[b[j]] == -1) {
            k[b[j]] = j;
            int l = j - i + 1;
            v = (v > l) ? v : l;
            j++;
        } else {
            int id = k[b[j]];
            while (i <= id) {
                k[b[i]] = -1;
                i++;
            }
            i = id + 1;
            k[b[j]] = j;
            j++;
        }
    }

    printf("%d\n", v);

    free(b);
    free(k);

    return 0;
}
