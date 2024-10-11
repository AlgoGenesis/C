#include <stdio.h>
#include <stdlib.h>

// Utility function to find maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// Returns LIS of subarray ending with index i.
int lisEndAtI(int arr[], int i)
{
    // Base case
    if (i == 0)
        return 1;

    // Consider all elements on left of i,
    // recursively compute LISs ending with 
    // them and consider the largest
    int mx = 1;
    for (int prev = 0; prev < i; prev++)
        if (arr[prev] < arr[i])
            mx = max(mx, lisEndAtI(arr, prev) + 1);
    return mx;
}

int lis(int arr[], int n)
{
    int res = 1;
    for (int i = 1; i < n; i++)
        res = max(res, lisEndAtI(arr, i));
    return res;
}

// Driver program to test above function
int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Length of lis is %d\n", lis(arr, n));
    return 0;
}
