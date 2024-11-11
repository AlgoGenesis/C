#include <stdio.h>

int longestIncreasingSubsequence(int arr[], int n)
{
    int lis[n];
    for (int i = 0; i < n; i++)
        lis[i] = 1; // Initialize LIS values for all indexes as 1

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
            }
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < lis[i])
            max = lis[i];
    }
    return max;
}

int main()
{
    int n;

    // Take the number of elements as input
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Take array elements as input
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Calculate and print the length of LIS
    printf("Length of LIS is %d\n", longestIncreasingSubsequence(arr, n));
    return 0;
}
