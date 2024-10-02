// basic C header file
#include <stdio.h>

// function to merge two subarrays
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1; // length of left subarray
    int n2 = right - mid;    // length of right subarray

    // create temporary arrays
    int L[n1], R[n2];

    // copy data to temporary arrays
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    // merge the temporary array back into arr[left...right]
    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // copy remainig elements of L[]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    // copy remaining elements of R[] if any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; // find mid

        // recursively sort two halves of array
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
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
    int arr[] = {78, 650, 100, 21, 23, 12, 90, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:- \n");
    print_array(arr, n);

    merge_sort(arr, 0, n - 1);

    printf("Sorted array:- \n");
    print_array(arr, n);
    return 0;
}