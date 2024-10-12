#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *nums, int n)
{
    // Implementing a simple bubble sort for sorting
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(&nums[j], &nums[j + 1]);
            }
        }
    }
}

void fourSum(int nums[], int n, int target, int result[][4], int *quadrupletCount)
{
    sort(nums, n);
    *quadrupletCount = 0;

    // Calculate the quadruplets
    for (int i = 0; i < n; i++)
    {
        // Avoid duplicates for the first number
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n; j++)
        {
            // Avoid duplicates for the second number
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            // Two-pointer technique
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                if (sum == target)
                {
                    // Store the quadruplet
                    result[*quadrupletCount][0] = nums[i];
                    result[*quadrupletCount][1] = nums[j];
                    result[*quadrupletCount][2] = nums[k];
                    result[*quadrupletCount][3] = nums[l];
                    (*quadrupletCount)++;

                    k++;
                    l--;

                    // Skip duplicates for the third and fourth numbers
                    while (k < l && nums[k] == nums[k - 1])
                        k++;
                    while (k < l && nums[l] == nums[l + 1])
                        l--;
                }
                else if (sum < target)
                {
                    k++;
                }
                else
                {
                    l--;
                }
            }
        }
    }
}

int main()
{
    int nums[] = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    int n = sizeof(nums) / sizeof(nums[0]);

    // Assuming max possible quadruplets is n * (n-1) * (n-2) * (n-3) / 24
    int result[100][4];
    int quadrupletCount;

    fourSum(nums, n, target, result, &quadrupletCount);

    // Print the quadruplets
    printf("The quadruplets are:\n");
    for (int i = 0; i < quadrupletCount; i++)
    {
        printf("[");
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("] ");
    }
    printf("\n");

    return 0;
}
