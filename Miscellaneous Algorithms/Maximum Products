int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int maxProduct(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    return (nums[numsSize - 2] - 1) * (nums[numsSize - 1] - 1);
}
