#include <stdio.h>

// Function to get the maximum value in the array
int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// Counting sort function

void countingsort(int arr[], int n, int idx)
{
    int output[n];       // Output array
    int count[10] = {0}; // Count array for digits (0 to 9)

    // Store the count of occurrences of each digit in count array
    for (int i = 0; i < n; i++)
    {
        int index = (arr[i] / idx) % 10;
        count[index]++;
    }

    // Change count[i]

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--)
    {
        int index = (arr[i] / idx) % 10; // Get digit at idx
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    // Copy output array to arr
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radixsort(int arr[], int n)
{
    // Get maximum number to know number of digits
    int max = getMax(arr, n);

    // Applying counting sort to sort elements based on each digit
    for (int i = 1; max / i > 0; i *= 10)
    {
        countingsort(arr, n, i);
    }
}

// Function to print array
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

    printf("Original array:- \n");
    print_array(arr, n);

    radixsort(arr, n);

    printf("Sorted array:- \n");
    print_array(arr, n);
    return 0;
}