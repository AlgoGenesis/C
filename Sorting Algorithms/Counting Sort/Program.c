#include <stdio.h>

// counting sort function

void countsort(int arr[], int n, int k)
{
    int output[n];    // output array
    int count[k + 1]; // count array

    // initialize arr with 0
    for (int i = 0; i <= k; i++)
    {
        count[i] = 0;
    }
    // count occurence of each element in arr
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    // update count[i] to hold the position of this element in output
    for (int i = 1; i <= k; i++)
    {
        count[i] += count[i - 1];
    }
    // build the output array
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // copy output array to arr
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

// function to print array
void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {78, 650, 10, 21, 23, 12, 90, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 650; // max value in array
    printf("Original array:- \n");
    print_array(arr, n);

    countsort(arr, n, k);

    printf("Sorted array:- \n");
    print_array(arr, n);
    return 0;
}