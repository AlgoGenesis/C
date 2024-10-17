#include<stdio.h>  

const int RUN = 32;  
int min(int a, int b)    
{    
    return (a < b) ? a : b;   
}    
// function sorts array from starting index to ending index which is of size atmost RUN  
void insertionSort(int a[], int beg, int end) /* function to sort an array with insertion sort */  
{  
    int i, j, temp;  
    for (i = beg + 1; i <= end; i++) {  
        temp = a[i];  
        j = i - 1;  
  
        while(j >= 0 && temp <= a[j])    
        {    
            a[j + 1] = a[j];     
            j = j - 1;    
        }    
        a[j + 1] = temp;    
    }  
}  
// Function to merge the sorted runs   
void merge(int a[], int beg, int mid, int end)    
{    
    int i, j, k;  
    int n1 = mid - beg + 1;    
    int n2 = end - mid;        
    int LeftArray[n1], RightArray[n2]; //temporary arrays      
    /* copy data to temp arrays */  
    for (i = 0; i < n1; i++)    
        LeftArray[i] = a[beg + i];    
    for (j = 0; j < n2; j++)    
        RightArray[j] = a[mid + 1 + j];       
    i = 0;   
    j = 0;  
    k = beg;       
    while (i < n1 && j < n2)    
    {    
        if(LeftArray[i] <= RightArray[j])    
        {    
            a[k] = LeftArray[i];    
            i++;    
        }    
        else    
        {    
            a[k] = RightArray[j];    
            j++;    
        }    
        k++;    
    }    
    while (i < n1)    
    {    
        a[k] = LeftArray[i];    
        i++;    
        k++;    
    }       
    while (j < n2)    
    {    
        a[k] = RightArray[j];    
        j++;    
        k++;    
    }    
}  
//function for implement tim sort
void timSort(int a[], int n)  
{  
    // Sort individual subarrays of size RUN 
    for (int i = 0; i < n; i += RUN)  
        insertionSort(a, i, min((i + RUN - 1), (n - 1)));   
  
    // Start merging from size RUN .  
    for (int size = RUN; size < n; size = 2 * size)  
    {  
        for (int beg = 0; beg < n; beg += 2 * size)  
        {  
            // find ending point of left sub array. The starting point of right sub array is mid + 1 */  
            int mid = beg + size - 1;  
            int end = min((beg + 2 * size - 1), (n - 1));  
  
            // Merge subarray 
            if(mid < end)  
                merge(a, beg, mid, end);  
        }  
    }  
}  
// function to print the array elements
void printArr(int a[], int n)  
{  
    for (int i = 0; i < n; i++)  
        printf("%d ", a[i]);  
    printf("\n");  
}  
int main()  
{  
    int a[] = { 40, 12, 31, 27, 25, 8, 1, 32, 17 };  
    int n = sizeof(a) / sizeof(a[0]);  
    printf("Before sorting array elements are - \n");  
    printArr(a, n);  
    timSort(a, n);  
    printf("\nAfter sorting array elements are - \n");    
    printArr(a, n);  
    return 0;  
}
