#include <stdio.h>
#include <stdlib.h>

void findCombination(int ind, int target, int *arr, int arrSize, int ***ans, int *returnSize, int *ds, int dsSize) {
    if (ind == arrSize) {
        if (target == 0) {
            (*ans) = realloc(*ans, (*returnSize + 1) * sizeof(int *));
            (*ans)[*returnSize] = malloc(dsSize * sizeof(int));
            for (int i = 0; i < dsSize; i++) {
                (*ans)[*returnSize][i] = ds[i];
            }
            (*returnSize)++;
        }
        return;
    }

    // Pick up the element
    if (arr[ind] <= target) {
        ds[dsSize] = arr[ind];
        findCombination(ind, target - arr[ind], arr, arrSize, ans, returnSize, ds, dsSize + 1);
    }

    findCombination(ind + 1, target, arr, arrSize, ans, returnSize, ds, dsSize);
}

int **combinationSum(int *candidates, int candidatesSize, int target, int *returnSize) {
    int **ans = NULL;
    int *ds = malloc(target * sizeof(int)); // Allocate a temporary array for storing combinations
    *returnSize = 0;
    findCombination(0, target, candidates, candidatesSize, &ans, returnSize, ds, 0);
    free(ds); // Free the temporary array
    return ans;
}

int main() {
    int candidates[] = {2, 3, 6, 7};
    int target = 7;
    int returnSize = 0;

    int **ans = combinationSum(candidates, 4, target, &returnSize);

    printf("Combinations are:\n");
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < target; j++) {
            if (ans[i][j] != 0) { // Print only non-zero elements
                printf("%d ", ans[i][j]);
            }
        }
        printf("\n");
        free(ans[i]); // Free each combination array
    }

    free(ans); // Free the main combinations array
    return 0;
}
