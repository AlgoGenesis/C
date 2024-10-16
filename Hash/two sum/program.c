#include <stdio.h>

void twoSum(int n, int arr[], int target, int result[])
{
    int mpp[1000] = {0}; // for storing indices
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp[moreNeeded] != 0)
        {
            result[0] = mpp[moreNeeded] - 1;
            result[1] = i;
            return;
        }
        mpp[num] = i + 1; // Store 1-based index to differentiate between 0 index and unset value
    }
    result[0] = -1;
    result[1] = -1;
}

int main()
{
    int n = 5;
    int arr[] = {2, 6, 5, 8, 11};
    int target = 14;
    int ans[2];

    twoSum(n, arr, target, ans);
    printf("This is the answer for variant 2: [%d, %d]\n", ans[0], ans[1]);

    return 0;
}
