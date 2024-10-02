//basic C header file
#include<stdio.h>

//function to swap two elemnts
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

//partition function to place the pivot in the correct position 
int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=(low-1);

    for(int j=low;j<high;j++){
        if(arr[j]<=pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);//return partitioning index
}

void quick_sort(int arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
//recursively sort elements
        quick_sort(arr,low,pi-1);
        quick_sort(arr,pi+1,high);
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

    quick_sort(arr, 0, n - 1);

    printf("Sorted array:- \n");
    print_array(arr, n);
    return 0;
}