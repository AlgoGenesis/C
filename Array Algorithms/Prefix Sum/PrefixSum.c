#include <stdio.h>

// Function to create the prefix sum array
void computePrefixSum(int arr[], int n, int prefix[])
{
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }
}

// Function to find the sum of elements from index l to r
int rangeSum(int prefix[], int l, int r)
{
    if (l == 0)
    {
        return prefix[r];
    }
    return prefix[r] - prefix[l - 1];
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    int prefix[5]; // Array to store prefix sums
    computePrefixSum(arr, 5, prefix);

    // Example query: sum of elements from index 1 to 3
    int l = 1, r = 3;
    printf("Sum of elements from index %d to %d is: %d\n", l, r, rangeSum(prefix, l, r));

    return 0;
}
