#include <stdio.h>

int maxSumNonAdjacent(int* nums, int n) {
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    int include = nums[0];  
    int exclude = 0;       

    for (int i = 1; i < n; i++) {
 
        int new_exclude = (include > exclude) ? include : exclude;
        include = exclude + nums[i];
        exclude = new_exclude;
    }


    return (include > exclude) ? include : exclude;
}

int main() {
    int nums[] = {3, 2, 7, 10};
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("Maximum sum of non-adjacent elements: %d\n", maxSumNonAdjacent(nums, n));
    return 0;
}
